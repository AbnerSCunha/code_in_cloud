// For Firebase JS SDK v7.20.0 and later, measurementId is optional
const firebaseConfig = {
	apiKey: "AIzaSyBpzoRrnO2RsO61nEf07u9afTvHEruNQg8",
	authDomain: "toggle-button-20dbb.firebaseapp.com",
	databaseURL: "https://toggle-button-20dbb-default-rtdb.firebaseio.com",
	projectId: "toggle-button-20dbb",
	storageBucket: "toggle-button-20dbb.appspot.com",
	messagingSenderId: "3901522997",
	appId: "1:3901522997:web:6fd55de4c3fc4f993fdd7c",
	measurementId: "G-MCKWE3EHY2"
  };

  // Initialize Firebase
  firebase.initializeApp(firebaseConfig);

$(document).ready(function() {
    var database = firebase.database();
	var Led1Status;
	var Status;

	database.ref().on("value", function(snap){
		Led1Status = snap.val().Led1Status;
		if(Led1Status == "1"){    // check from the firebase
			//$(".Light1Status").text("The light is off");
			document.getElementById("unact").style.display = "none";
			document.getElementById("act").style.display = "block";

			document.getElementById("unact-icon").style.display = "none";
			document.getElementById("act-icon").style.display = "block";
		} else {
			//$(".Light1Status").text("The light is on");
			document.getElementById("unact").style.display = "block";
			document.getElementById("act").style.display = "none";

			document.getElementById("unact-icon").style.display = "block";
			document.getElementById("act-icon").style.display = "none";
		}
	});

	$(".toggle-btn").click(function(){
		var firebaseRef = firebase.database().ref().child("Led1Status");

		if(Led1Status == "1"){    // post to firebase
			firebaseRef.set("0");
			Led1Status = "0";
		} else {
			firebaseRef.set("1");
			Led1Status = "1";
		}
	})

	database.ref().on("value", function(snap){
		Status = snap.val().Temperatura;
		console.log(Status);
		document.getElementById("ShowTemp").innerHTML = `${Status} °C`;
	});
});