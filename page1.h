#ifndef PAGE1_H
#define PAGE1_H

const char PAGE1[] PROGMEM = R"=====(
  <!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Form</title>
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
    <script>
        function showForm(formType) {
            // Hide all forms
            document.getElementById('wpa2').style.display = 'none';
            document.getElementById('eap').style.display = 'none';

            // Show the selected form
            document.getElementById(formType).style.display = 'block';
        }
        
        function saveDetails(secinput, ssidinput, userinput, passwordinput, autoinput) {
            localStorage.setItem("securityafter", secinput);
            localStorage.setItem("ssidvalafter", ssidinput);
            localStorage.setItem("usernamevalafter", userinput);
            localStorage.setItem("passwordvalafter", passwordinput);
            localStorage.setItem("autoafter", autoinput);
        }

    </script>

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
    <div class="selection">
        <p>Select WiFi Connection</p>
        <button id="wpa2button" onclick="showForm('wpa2')">WPA2</button>
        <button id="eapbutton" onclick="showForm('eap')">EAP</button>
    </div>

    <div>
        <form id="wpa2" action="/page2" method="post">
            <h2>WPA2 ESP32 Wi-Fi Connection</h2>
            <i class="fa fa-wifi"></i>
            <input class="input" type="text" id="ssidwpa2" name="ssid" placeholder="WiFi Name" required><br>
            <i class="fa fa-lock"></i>
            <input class="input" type="text" id="passwordwpa2" name="password" placeholder="Password" required><br>
            <div>
                <label>Auto-Recognition</label>
                <label class="switch">
                    <input id ="reconfigwpa2" type="checkbox">
                    <span class="slider round"></span>
                </label>
            </div>
            <a href="/page2">
                <input class="submitbutton" type="submit" onclick="saveDetails('WPA2', document.getElementById('ssidwpa2').value, 'Not Applicable for WPA2', document.getElementById('passwordwpa2').value, document.getElementById('reconfigwpa2').checked)" value="Connect to WiFi">
            </a>
        </form>

        <form id="eap" action="/page2" method="post">
            <h2>EAP ESP32 Wi-Fi Connection</h2>
            <i class="fa fa-wifi"></i>
            <input class="input" type="text" id="ssideap" name="ssid" placeholder="WiFi Name" required><br>
            <i class="fa fa-user"></i>
            <input class="input" type="text" id="usernameeap" name="username" placeholder="Username" required><br>
            <i class="fa fa-lock"></i>
            <input class="input" type="text" id="passwordeap" name="password" placeholder="Password" required><br>
            <div>
                <label>Auto-Recognition</label>
                <label class="switch">
                    <input id ="reconfigeap" type="checkbox">
                    <span class="slider round"></span>
                </label>
            </div>
            <a href="/page2">
                <input class="submitbutton" type="submit" onclick="saveDetails('EAP', document.getElementById('ssideap').value, document.getElementById('usernameeap').value, document.getElementById('passwordeap').value, document.getElementById('reconfigeap').checked)" value="Connect to WiFi">
            </a>
        </form>

    </div>

    

</body>
</html>
)=====";

#endif // PAGE1_H
