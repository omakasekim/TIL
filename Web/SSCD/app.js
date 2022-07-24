// Your web app's Firebase configuration
var firebaseConfig = {
    apiKey: "AIzaSyC2VImSleRbgACKUUXiHDzQ6s9JGtmXxEk",
    authDomain: "web-based-chat-95161.firebaseapp.com",
    databaseURL: "https://web-based-chat-95161-default-rtdb.firebaseio.com",
    projectId: "web-based-chat-95161",
    storageBucket: "web-based-chat-95161.appspot.com",
    messagingSenderId: "592044011772",
    appId: "1:592044011772:web:aad3f274e4239f0aa06779",
    measurementId: "G-101E7RENPY"
};
firebase.initializeApp(firebaseConfig);
var db = firebase.database();
var username = prompt("Please Tell Us Your Name");
document.getElementById("message-form").addEventListener("submit", sendMessage);
function sendMessage(e) {
    e.preventDefault();
    var timestamp = Date.now();
    var messageInput = document.getElementById("message-input");
    var message = messageInput.value;
    messageInput.value = "";
    document
        .getElementById("messages")
        .scrollIntoView({ behavior: "smooth", block: "end", inline: "nearest" });
    db.ref("messages/" + timestamp).set({
        username: username,
        message: message,
    });
}
var fetchChat = db.ref("messages/");
fetchChat.on("child_added", function (snapshot) {
    var messages = snapshot.val();
    var message = "<li class=".concat(username === messages.username ? "sent" : "receive", "><span>").concat(messages.username, ": </span>").concat(messages.message, "</li>");
    document.getElementById("messages").innerHTML += message;
});
