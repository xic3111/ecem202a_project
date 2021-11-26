window.onload = function(){
  for(let i = 1; i < 6; i++){
    document.getElementById("Key_" + i).addEventListener("click", function() {
    var now = new Date();
    var info = "Key_" + i + ": " + now.getHours() + ":" + now.getMinutes() + ":" + now.getSeconds() + ":" + now.getMilliseconds();
    console.log(info);
    document.getElementById("data").textContent += info;
    document.getElementById("data").textContent += "\n\n";
  });
  }
}
