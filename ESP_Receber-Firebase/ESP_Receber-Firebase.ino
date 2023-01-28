#include <FirebaseESP8266.h>
#if defined(ESP32)
  #include <WiFi.h>
#elif defined(ESP8266)
  #include <ESP8266WiFi.h>
#endif

#define WIFI_SSID "Silvania Cunha" // your wifi SSID
#define WIFI_PASSWORD "12345678" //your wifi PASSWORD

#define LedPin 16         // pin d0 as toggle pin
#define FIREBASE_HOST "toggle-button-20dbb-default-rtdb.firebaseio.com" // change here
#define FIREBASE_AUTH "sKzn6wSTxCWaTsL61zPIQCwZQYAcMkx1OGkj8Nhe"  // your private key
FirebaseData firebaseData;

void setup ()
{
  pinMode(LedPin, OUTPUT);
  Serial.begin(9600);
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ") ;
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);     
}
void loop ()
{
  if(Firebase.getString(firebaseData, "/Led1Status"))
  {
    String ledstatus = firebaseData.stringData();
    if(ledstatus.toInt() == 1){
      digitalWrite(LedPin, LOW);
      Serial.println("on");
    }
    else {
      digitalWrite(LedPin, HIGH);
      Serial.println("off");
    }
  }else{
    Serial.print("Error in getInt, ");
    Serial.println(firebaseData.errorReason());
  } 

  if(Serial.available()>0){
/*    char str[Serial.readString().length()] = Serial.readString()+"";
    if(str.substring(0,1) == 't'){
      float t = str.substring(1);
    }else{
      float u = str.substring(1);
    }*/
    String str = Serial.readString().substring(0,1);
    if(str.equals("t")){
      Serial.println("Temperatura");
    }else{
      Serial.println("Umidade");
    }
    /*switch (str) {
      case "t":
        Serial.println("Temperatura");
        break;
      case "u":
        Serial.println("Umidade");
        break;
    }*/
    //Firebase.setInt(firebaseData, "/Temperatura", t);
  }
}