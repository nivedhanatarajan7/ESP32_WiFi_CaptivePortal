#ifndef PAGE2_H
#define PAGE2_H

const char PAGE2[] PROGMEM = R"=====(
  <!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Confirm</title>
    <style>
  .switch {
    position: relative;
    display: inline-block;
    width: 30px;
    height: 18px;
    margin: 10px;
  }
  
  .switch input { 
    opacity: 0;
    width: 0;
    height: 0;
  }
  
  .slider {
    position: absolute;
    cursor: pointer;
    top: 0;
    left: 0;
    right: 0;
    bottom: 0;
    background-color: #ccc;
    -webkit-transition: .4s;
    transition: .4s;
  }
  
  .slider:before {
    position: absolute;
    content: "";
    height:10px;
    width: 10px;
    left: 4px;
    bottom: 4px;
    background-color: white;
    -webkit-transition: .4s;
    transition: .4s;
  }
  
  input:checked + .slider {
    background-color: #3e4057;
  }
  
  input:focus + .slider {
    box-shadow: 0 0 1px #3e4057;
  }
  
  input:checked + .slider:before {
    -webkit-transform: translateX(10px);
    -ms-transform: translateX(10px);
    transform: translateX(10px);
  }
  
  /* Rounded sliders */
  .slider.round {
    border-radius: 34px;
  }
  
  .slider.round:before {
    border-radius: 50%;
  }

  .header{
    background-color: #3e4057;
    text-align: center;
    color: white;
    height: 150px;
    margin-bottom: 10px;
  }

  .info{
    display: flex;
    align-items: center;
    padding: 7px;
    background-color: #f0f0f0;
    width: 600px;
    height: 30px;
    margin: auto;
    margin-bottom: 10px;
    border-radius: 10px;
  }

  .details{
    display: run-in	;
    align-items: center;
    background-color: #f0f0f0;
    padding: 10px;
    padding-left: 60px;
    padding-right: 50px;
    width: 500px;
    height: 190px;
    margin: auto;
    margin-bottom: 20px;
    border-radius: 10px;
  }

  .directions{
    text-align: center;
  }

  .wait{
    text-align: center;
  }

  body{
    font-family: Arial;
    font-size: 14px;
  }

  .selection {
    text-align: center;
    margin:auto;

  }

  .path {
    text-align: center;
  }

  .back {
    width: 300px;
    color: white;
    background-color: gray;
  }

  .confirm {
    width: 300px;
    color: white;
    background-color: #3e4057;
  }
  
  .input{
    width: 400px;
    margin-bottom:  10px;
    height: 20px;
    
  }

  form{
    display: none;
    max-width: 1000px;
    margin: auto;
    text-align: center;
  }

  button {
    border-radius: 5px;
    padding: 5px;
  }

  .submitbutton{
    background-color: #3e4057;
    color: white;
    width: 400px;
    height: 30px;
    border-radius: 5px;
  }
    </style></head>
<body>
    <div class ="header">
        <br>
        <h1>WiFi Setup</h1>
    </div>
    <div class="info">
        <p>Currently connected to: <span id="nameview"></span> <a href="/page3">View Data</a></p>
        <script>
            document.getElementById("nameview").innerHTML = localStorage.getItem("ssidvalbefore");
        </script>
    </div>

    <div class = "details">
        <p class="directions">Please confirm that you would like to connect to the following network:</p>
        <p><b>Security: </b> <span id="sec"></span> </p>
        <script>
            document.getElementById("sec").innerHTML=localStorage.getItem("securityafter");
        </script>
        <p><b>Network Name: </b> <span id="name"></span></p>
        <script>
            document.getElementById("name").innerHTML=localStorage.getItem("ssidvalafter");
        </script>
        <p><b>Username: </b> <span id="user"></span></p>
        <script>
            document.getElementById("user").innerHTML=localStorage.getItem("usernamevalafter");
        </script>
        <p><b>Password: </b> <span id="pass"></span> </p>
        <script>
            document.getElementById("pass").innerHTML=localStorage.getItem("passwordvalafter");
        </script>
        <p><b>Auto Reconfigure: </b> <span id="recon"></span></p>
        <script>
            document.getElementById("recon").innerHTML=localStorage.getItem("autoafter");
        </script>
    </div>

    
    <div class = "path">
        <button class="back" onclick="page1()">Back</button>
        <script>
          function page1() {
              window.location.href = '/page1';
          }
        </script>
        <button class="confirm" onclick="page4()">Confirm</button>
        <script>
          function page4() {
              window.location.href = '/page4';
          }
        </script>
    </div>
</body>
</html>
)=====";

#endif // PAGE2_H
