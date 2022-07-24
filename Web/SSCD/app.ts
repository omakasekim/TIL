// Your web app's Firebase configuration
const firebaseConfig = {
    apiKey: "AIzaSyC2VImSleRbgACKUUXiHDzQ6s9JGtmXxEk",
    authDomain: "web-based-chat-95161.firebaseapp.com",
    databaseURL: "https://web-based-chat-95161-default-rtdb.firebaseio.com",
    projectId: "web-based-chat-95161",
    storageBucket: "web-based-chat-95161.appspot.com",
    messagingSenderId: "592044011772",
    appId: "1:592044011772:web:aad3f274e4239f0aa06779",
    measurementId: "G-101E7RENPY"
  };
  // Initialize Firebase
  firebase.initializeApp(firebaseConfig);
  // initialize database
  const db = firebase.database();
  // get user's data
  const username = prompt("Please Tell Us Your Name");
  // submit form
  // listen for submit event on the form and call the postChat function
  document.getElementById("message-form").addEventListener("submit", sendMessage);
  // send message to db
  function sendMessage(e) {
    e.preventDefault();
    // get values to be submitted
    const timestamp = Date.now();
    const messageInput: any = document.getElementById("message-input");
    const message = messageInput.value;
    // clear the input box
    messageInput.value = "";
    //auto scroll to bottom
    document
      .getElementById("messages")
      .scrollIntoView({ behavior: "smooth", block: "end", inline: "nearest" });
  
    // create db collection and send in the data
    db.ref("messages/" + timestamp).set({
      username,
      message,
    });
  }
  
  // display the messages
  // reference the collection created earlier
  const fetchChat = db.ref("messages/");
  
  // check for new messages using the onChildAdded event listener
  fetchChat.on("child_added", function (snapshot) {
    const messages = snapshot.val();
    const message = `<li class=${
      username === messages.username ? "sent" : "receive"
    }><span>${messages.username}: </span>${messages.message}</li>`;
    // append the message on the page
    document.getElementById("messages").innerHTML += message;
  });