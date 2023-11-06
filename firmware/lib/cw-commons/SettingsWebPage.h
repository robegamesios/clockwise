#pragma once

#include <Arduino.h>

// TODO: Move the whole JS to a CDN soon

const char SETTINGS_PAGE[] PROGMEM = R""""(
<!DOCTYPE html>
<html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Card Example</title>
    <style>
        .card {
            width: 200px;
            border: 1px solid #ccc;
            border-radius: 8px;
            box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);
            margin: 10px;
            padding: 20px;
        }

        .card-title {
            font-size: 20px;
            font-weight: bold;
        }

        .card-description {
            margin-top: 10px;
        }

        .card-image {
            width: 100%;
            max-width: 100%;
            height: auto;
            margin-top: 10px;
        }

        .update-button {
            display: block;
            margin-top: 10px;
            background-color: #007bff;
            color: #fff;
            padding: 10px 20px;
            border: none;
            border-radius: 4px;
            text-align: center;
            text-decoration: none;
            cursor: pointer;
        }
    </style>
</head>

<title>Clockwise Settings</title>
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
<link rel="shortcut icon" type="image/x-icon"
  href="https://github.com/jnthas/clockwise/raw/gh-pages/static/images/favicon.png">

<body>
<div class="card">
        <h2 class="card-title">Card Title</h2>
        <p class="card-description">This is a card description. You can add your content here.</p>
        <img class="card-image" 
        src="data:image/png;base64,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PSJodHRwOi8vbnMuYWRvYmUuY29tL3RpZmYvMS4wLyIKICAgICAgICAgICAgeG1sbnM6ZXhpZkVYPSJodHRwOi8vY2lwYS5qcC9leGlmLzEuMC8iCiAgICAgICAgICAgIHhtbG5zOkdJTVA9Imh0dHA6Ly93d3cuZ2ltcC5vcmcveG1wLyI+CiAgICAgICAgIDxleGlmOlBpeGVsWURpbWVuc2lvbj42NDwvZXhpZjpQaXhlbFlEaW1lbnNpb24+CiAgICAgICAgIDxleGlmOkdQU0RhdGU+MjAyMjowNjoyNjwvZXhpZjpHUFNEYXRlPgogICAgICAgICA8ZXhpZjpTY2VuZUNhcHR1cmVUeXBlPjU8L2V4aWY6U2NlbmVDYXB0dXJlVHlwZT4KICAgICAgICAgPGV4aWY6RXhwb3N1cmVUaW1lPjEvMTwvZXhpZjpFeHBvc3VyZVRpbWU+CiAgICAgICAgIDxleGlmOkdQU1ZlcnNpb25JRD4yLjIuMC4wPC9leGlmOkdQU1ZlcnNpb25JRD4KICAgICAgICAgPGV4aWY6Rm9jYWxMZW5JbjM1bW1GaWxtPjI0PC9leGlmOkZvY2FsTGVuSW4zNW1tRmlsbT4KICAgICAgICAgPGV4aWY6TGlnaHRTb3VyY2U+MDwvZXhpZjpMaWdodFNvdXJjZT4KICAgICAgICAgPGV4aWY6SVNPU3BlZWRSYXRpbmdzPgogICAgICAgICAgICA8cmRmOlNlcT4KICAgICAgICAgICAgICAgPHJkZjpsaT4wPC9yZGY6bGk+CiAgICAgICAgICAgIDwvcmRmOlNlcT4KICAgICAgICAgPC9leGlmOklTT1NwZWVkUmF0aW5ncz4KICAgICAgICAgPGV4aWY6SW1hZ2VVbmlxdWVJRD5hMjA5NTA1MjkzMDFkN2EyMDAwMDAwMDAwMDAwMDAwMDwvZXhpZjpJbWFnZVVuaXF1ZUlEPgogICAgICAgICA8ZXhpZjpGbGFzaCByZGY6cGFyc2VUeXBlPSJSZXNvdXJjZSI+CiAgICAgICAgICAgIDxleGlmOkZ1bmN0aW9uPkZhbHNlPC9leGlmOkZ1bmN0aW9uPgogICAgICAgICAgICA8ZXhpZjpGaXJlZD5GYWxzZTwvZXhpZjpGaXJlZD4KICAgICAgICAgICAgPGV4aWY6UmV0dXJuPjA8L2V4aWY6UmV0dXJuPgogICAgICAgICAgICA8ZXhpZjpNb2RlPjA8L2V4aWY6TW9kZT4KICAgICAgICAgICAgPGV4aWY6UmVkRXllTW9kZT5GYWxzZTwvZXhpZjpSZWRFeWVNb2RlPgogICAgICAgICA8L2V4aWY6Rmxhc2g+CiAgICAgICAgIDxleGlmOkV4cG9zdXJlUHJvZ3JhbT4wPC9leGlmOkV4cG9zdXJlUHJvZ3JhbT4KICAgICAgICAgPGV4aWY6Rm9jYWxMZW5ndGg+MC8xPC9leGlmOkZvY2FsTGVuZ3RoPgogICAgICAgICA8ZXhpZjpCcmlnaHRuZXNzVmFsdWU+LTExMy8yNTwvZXhpZjpCcmlnaHRuZXNzVmFsdWU+CiAgICAgICAgIDxleGlmOkZOdW1iZXI+MC8xPC9leGlmOkZOdW1iZXI+CiAgICAgICAgIDxleGlmOkdQU0FsdGl0dWRlPjAvMTwvZXhpZjpHUFNBbHRpdHVkZT4KICAgICAgICAgPGV4aWY6V2hpdGVCYWxhbmNlPjA8L2V4aWY6V2hpdGVCYWxhbmNlPgogICAgICAgICA8ZXhpZjpHUFNBbHRpdHVkZVJlZj4wPC9leGlmOkdQU0FsdGl0dWRlUmVmPgogICAgICAgICA8ZXhpZjpNZXRlcmluZ01vZGU+MTwvZXhpZjpNZXRlcmluZ01vZGU+CiAgICAgICAgIDxleGlmOlBpeGVsWERpbWVuc2lvbj42NDwvZXhpZjpQaXhlbFhEaW1lbnNpb24+CiAgICAgICAgIDxleGlmOkdQU0xvbmdpdHVkZVJlZj5FPC9leGlmOkdQU0xvbmdpdHVkZVJlZj4KICAgICAgICAgPGV4aWY6R1BTTGF0aXR1ZGVSZWY+TjwvZXhpZjpHUFNMYXRpdHVkZVJlZj4KICAgICAgICAgPGV4aWY6RXhwb3N1cmVNb2RlPjA8L2V4aWY6RXhwb3N1cmVNb2RlPgogICAgICAgICA8ZXhpZjpBcGVydHVyZVZhbHVlPjM3LzIwPC9leGlmOkFwZXJ0dXJlVmFsdWU+CiAgICAgICAgIDxleGlmOkdQU0xvbmdpdHVkZT4wLDBFPC9leGlmOkdQU0xvbmdpdHVkZT4KICAgICAgICAgPGV4aWY6U2Vuc2luZ01ldGhvZD4yPC9leGlmOlNlbnNpbmdNZXRob2Q+CiAgICAgICAgIDxleGlmOlNodXR0ZXJTcGVlZFZhbHVlPjQwOTkvMTAwMDwvZXhpZjpTaHV0dGVyU3BlZWRWYWx1ZT4KICAgICAgICAgPGV4aWY6R1BTTGF0aXR1ZGU+MCwwTjwvZXhpZjpHUFNMYXRpdHVkZT4KICAgICAgICAgPHhtcE1NOk9yaWdpbmFsRG9jdW1lbnRJRD54bXAuZGlkOmNlMjRiY2U5LTEyYmItNDRjNy1iM2JkLTUzNWFhZjVhZjgxYTwveG1wTU06T3JpZ2luYWxEb2N1bWVudElEPgogICAgICAgICA8eG1wTU06RG9jdW1lbnRJRD5naW1wOmRvY2lkOmdpbXA6YTQxMTYxNmQtZDBhNy00ZGRhLWJiMjYtNmEyOTgxZGU0ZGYyPC94bXBNTTpEb2N1bWVudElEPgogICAgICAgICA8eG1wTU06SW5zdGFuY2VJRD54bXAuaWlkOjgxMjRiNjA0LWJiMTUtNGNkYS1hODdjLTQzMjQ3MjJlZjU1OTwveG1wTU06SW5zdGFuY2VJRD4KICAgICAgICAgPHhtcE1NOkhpc3Rvcnk+CiAgICAgICAgICAgIDxyZGY6QmFnPgogICAgICAgICAgICAgICA8cmRmOmxpIHJkZjpwYXJzZVR5cGU9IlJlc291cmNlIj4KICAgICAgICAgICAgICAgICAgPHN0RXZ0OmNoYW5nZWQ+Lzwvc3RFdnQ6Y2hhbmdlZD4KICAgICAgICAgICAgICAgICAgPHN0RXZ0OnNvZnR3YXJlQWdlbnQ+R2ltcCAyLjEwIChMaW51eCk8L3N0RXZ0OnNvZnR3YXJlQWdlbnQ+CiAgICAgICAgICAgICAgICAgIDxzdEV2dDp3aGVuPjIwMjItMDctMDJUMDk6NTg6MjQtMDM6MDA8L3N0RXZ0OndoZW4+CiAgICAgICAgICAgICAgICAgIDxzdEV2dDppbnN0YW5jZUlEPnhtcC5paWQ6MDZmM2FkYzEtNmM3ZC00YmZlLTkwNzctYTE3MzkxMzFkOTFiPC9zdEV2dDppbnN0YW5jZUlEPgogICAgICAgICAgICAgICAgICA8c3RFdnQ6YWN0aW9uPnNhdmVkPC9zdEV2dDphY3Rpb24+CiAgICAgICAgICAgICAgIDwvcmRmOmxpPgogICAgICAgICAgICA8L3JkZjpCYWc+CiAgICAgICAgIDwveG1wTU06SGlzdG9yeT4KICAgICAgICAgPGRjOkZvcm1hdD5pbWFnZS9qcGVnPC9kYzpGb3JtYXQ+CiAgICAgICAgIDxwaG90b3Nob3A6RGF0ZUNyZWF0ZWQ+MjAyMi0wNi0yNlQxOTozNzowMzwvcGhvdG9zaG9wOkRhdGVDcmVhdGVkPgogICAgICAgICA8eG1wOkNyZWF0ZURhdGU+MjAyMi0wNi0yNlQxOTozNzowMzwveG1wOkNyZWF0ZURhdGU+CiAgICAgICAgIDx4bXA6Q3JlYXRvclRvb2w+R0lNUCAyLjEwLjI4PC94bXA6Q3JlYXRvclRvb2w+CiAgICAgICAgIDx4bXA6TW9kaWZ5RGF0ZT4yMDIyLTA3LTAyVDA5OjU4OjIyPC94bXA6TW9kaWZ5RGF0ZT4KICAgICAgICAgPHRpZmY6TWFrZT4tLTwvdGlmZjpNYWtlPgogICAgICAgICA8dGlmZjpSZXNvbHV0aW9uVW5pdD4yPC90aWZmOlJlc29sdXRpb25Vbml0PgogICAgICAgICA8dGlmZjpYUmVzb2x1dGlvbj4zMDA8L3RpZmY6WFJlc29sdXRpb24+CiAgICAgICAgIDx0aWZmOllSZXNvbHV0aW9uPjMwMDwvdGlmZjpZUmVzb2x1dGlvbj4KICAgICAgICAgPHRpZmY6T3JpZW50YXRpb24+MTwvdGlmZjpPcmllbnRhdGlvbj4KICAgICAgICAgPHRpZmY6TW9kZWw+LS08L3RpZmY6TW9kZWw+CiAgICAgICAgIDxleGlmRVg6UGhvdG9ncmFwaGljU2Vuc2l0aXZpdHk+MDwvZXhpZkVYOlBob3RvZ3JhcGhpY1NlbnNpdGl2aXR5PgogICAgICAgICA8R0lNUDpWZXJzaW9uPjIuMTAuMjg8L0dJTVA6VmVyc2lvbj4KICAgICAgICAgPEdJTVA6VGltZVN0YW1wPjE2NTY3NjY3MDQ1OTE1NTU8L0dJTVA6VGltZVN0YW1wPgogICAgICAgICA8R0lNUDpQbGF0Zm9ybT5MaW51eDwvR0lNUDpQbGF0Zm9ybT4KICAgICAgICAgPEdJTVA6QVBJPjIuMDwvR0lNUDpB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" alt="Card Image">
        <a class="update-button" href="#">Update</a>
</div>

  <div class="w3-container" style="background-image: linear-gradient(120deg, #155799, #159957);">
    <img class="w3-animate-zoom w3-padding w3-image"
      src="data:image/png;base64,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" alt="Logo"
      style="width:20%">
  </div>

  <div class="w3-bar w3-black w3-medium">
    <div id="fw-version" class="w3-bar-item w3-black w3-hover-red"></div>
    <div class="w3-bar-item w3-button w3-hover-yellow w3-right" onclick="loadChangeFirmwarePage();"><i class='fa fa-power-off'></i> Change Theme</div>
    <div id="ssid" class="w3-bar-item w3-hover-blue w3-right"></div>
    <div class="w3-bar-item w3-button w3-hover-yellow w3-right" onclick="restartDevice();"><i class='fa fa-power-off'></i> Restart</div>
    <div id="status" class="w3-bar-item w3-green" style="display:none"><i class='fa fa-floppy-o'></i> Saved! Restart your device</div>
  </div>

  <div class="w3-row-padding w3-padding">
    <div id="base" class="w3-col s3 m3 s12" style="display: none;">
      <div class="w3-card-4 w3-margin-bottom">
        <header class="w3-container w3-blue-gray">
          <h4 id="title">{{TITLE}}</h4>
        </header>
        <div class="w3-container">
          <p style="min-height: 45px;" id="description">{{DESCRIPTION}}</p>
          <hr>
          <div class="w3-row w3-section">
            <div class="w3-col" style="width:50px"><i id="icon" class="w3-xxlarge w3-text-dark-grey fa"></i>
            </div>
            <div class="w3-rest" id="formInput">
              {{FORM_INPUT}}
            </div>
          </div>
        </div>
        <button id="cardButton" class="w3-button w3-block w3-light-blue">Save</button>
      </div>
    </div>
  </div>
  <script>
    function createCards(settings) {
      console.log(settings);
      const cards = [
        {
          title: "Display Bright",
          description: "0 = dark (display off) / 255 = super bright | Value: <strong><output id='rangevalue'>" + settings.displaybright + "</output></strong>",
          formInput: "<input class='w3-input w3-border' type='range' min='0' max='255' value='" + settings.displaybright + "' class='slider' id='bright' oninput='rangevalue.value=value'>",
          icon: "fa-adjust",
          save: "updatePreference('displayBright', bright.value)",
          property: "displayBright"
        },
        {
          title: "Use 24h format?",
          description: "Changes the hour format to show 20:00 instead of 8:00PM",
          formInput: "<input class='w3-check' type='checkbox' id='use24h' " + (settings.use24hformat == '1' ? "checked" : "") + "><label for='use24h'> Yep</label>",
          icon: "fa-clock-o",
          save: "updatePreference('use24hFormat', Number(use24h.checked))",
          property: "use24hFormat"
        },
        {
          title: "Swap Blue/Green pins?",
          description: "Swap Blue and Green pins because the panel is RBG instead of RGB",
          formInput: "<input class='w3-check' type='checkbox' id='swapBG' " + (settings.swapbluegreen == '1' ? "checked" : "") + "><label for='swapBG'> Yep</label>",
          icon: "fa-random",
          save: "updatePreference('swapBlueGreen', Number(swapBG.checked))",
          property: "swapBlueGreen"
        },
        {
          title: "Timezone",
          description: "Consult your TZ identifier <a href='https://en.wikipedia.org/wiki/List_of_tz_database_time_zones'>here.</a> Examples: America/Sao_Paulo, Europe/Lisbon",
          formInput: "<input id='tz' class='w3-input w3-light-grey' name='tz' type='text' placeholder='Timezone' value='" + settings.timezone + "'>",
          icon: "fa-globe",
          save: "updatePreference('timeZone', tz.value)",
          property: "timeZone"
        },
        {
          title: "NTP Server",
          description: "Configure your prefered NTP Server. You can use one of the <a href='https://www.ntppool.org'>NTP Pool Project</a> pools or a local one.",
          formInput: "<input id='ntp' class='w3-input w3-light-grey' name='ntp' type='text' placeholder='NTP Server' value='" + settings.ntpserver + "'>",
          icon: "fa-server",
          save: "updatePreference('ntpServer', ntp.value)",
          property: "ntpServer"
        },
        {
          title: "Automatic Bright",
          description: "Inform the values read by the LDR when the room is dark (min value) and bright (max value). Range 0 - 4095",
          formInput: "<input id='autoBrightMin' class='w3-input w3-light-grey w3-cell w3-margin-right' name='autoBrightMin' style='width:45%;' type='number' min='0' max='4095' placeholder='Min value' value='" + settings.autobrightmin + "'>" + 
                     "<input id='autoBrightMax' class='w3-input w3-light-grey w3-cell' name='autoBrightMax' style='width:45%;' type='number' min='0' max='4095' placeholder='Max value' value='" + settings.autobrightmax + "'>",
          icon: "fa-sun-o",
          save: "updatePreference('autoBright', autoBrightMin.value.padStart(4, '0') + ',' + autoBrightMax.value.padStart(4, '0'))",
          property: "autoBright"
        },
        {
          title: "LDR Pin",
          description: "The GPIO pin where the LDR is connected to. Use just the numeric value (default: 35) | <a href='#' onclick='readPin(ldrPin.value);'>Read Pin: </a><strong id='ldrPinRead'>0</strong>",
          formInput: "<input id='ldrPin' class='w3-input w3-light-grey' name='ldrPin' type='number' min='0' max='39' value='" + settings.ldrpin + "'>",
          icon: "fa-microchip",
          save: "updatePreference('ldrPin', ldrPin.value)",
          property: "ldrPin"
        },
        {
          title: "[Canvas] Description file",
          description: "Name of the description file to be rendered without extension.",
          formInput: "<input id='descFile' class='w3-input w3-light-grey' name='descFile' type='text' placeholder='Description File' value='" + settings.canvasfile + "'>",
          icon: "fa-file-image-o",
          save: "updatePreference('canvasFile', descFile.value)",
          property: "canvasFile",
          exclusive: "cw-cf-0x07"
        },
        {
          title: "[Canvas] Server Address",
          description: "Server address where the description files are located. Change this to test it locally.",
          formInput: "<input id='serverAddress' class='w3-input w3-light-grey' name='serverAddress' type='text' placeholder='Canvas Server' value='" + settings.canvasserver + "'>",
          icon: "fa-server",
          save: "updatePreference('canvasServer', serverAddress.value)",
          property: "canvasServer",
          exclusive: "cw-cf-0x07"
        },
        {
          title: "Posix Timezone String",
          description: "To avoid remote lookups, provide a Posix string that corresponds to your timezone. Leave empty to obtain this automatically from the server. <a href=\"https://github.com/nayarsystems/posix_tz_db/blob/master/zones.csv\">Click here for a list.</a>",
          formInput: "<input id='posixString' class='w3-input w3-light-grey' name='posixString' type='text' placeholder='Manual Posix String' value='" + settings.manualposix + "'>",
          icon: "fa-globe",
          save: "updatePreference('manualPosix', posixString.value)",
          property: "manualPosix"
        }
      ];

      var base = document.querySelector('#base');
      cards.forEach(c => {

        if (!c.hasOwnProperty('exclusive') || (c.hasOwnProperty('exclusive') && c.exclusive === settings.clockface_name)) {
          var clone = base.cloneNode(true);
          clone.id = c.property + "-card";
          clone.removeAttribute("style");

          Array.prototype.slice.call(clone.getElementsByTagName('*')).forEach(e => {
            e.id = e.id + "-" + c.property;
          });

          base.before(clone);
          document.getElementById("title-" + c.property).innerHTML = c.title
          document.getElementById("description-" + c.property).innerHTML = c.description
          document.getElementById("formInput-" + c.property).innerHTML = c.formInput
          document.getElementById("icon-" + c.property).classList.add(c.icon);
          document.getElementById("cardButton-" + c.property).setAttribute("onclick", c.save);
        }
      })

      document.getElementById("ssid").innerHTML = "<i class='fa fa-wifi'></i> " + settings.wifissid
      document.getElementById("fw-version").innerHTML = "<i class='fa fa-code-fork'></i> Firmware v" + settings.cw_fw_version
    }

    function updatePreference(key, value) {
      const xhr = new XMLHttpRequest();
      xhr.onreadystatechange = function () {
        if (this.readyState == 4 && this.status >= 200 && this.status < 299) {
          document.getElementById('status').style.display = 'block';
        }
      };
      xhr.open('POST', '/set?' + key + '=' + value);
      xhr.send();

      setTimeout(() => {
        document.getElementById('status').style.display = 'none';
      }, 2000);
    }

    function splitHeaders(request) {
      const headers = request.getAllResponseHeaders().trim().split(/[\r\n]+/);
      const headerMap = {};
      headers.forEach((line) => {
        const parts = line.split(": ");
        const header = parts.shift().substring(2);
        const value = parts.join(": ");
        headerMap[header] = value;
      });
      return headerMap;
    }

    function requestGet(path, cb) {
      var xmlhttp = new XMLHttpRequest();
      xmlhttp.onreadystatechange = function () {
        if (this.readyState === 2 && this.status === 204) {
          cb(this);
        }
      };
      xmlhttp.open("GET", path, true);
      xmlhttp.send();
    }
    
    function readPin(pin) {
      requestGet("/read?pin=" + pin, (req) => {
        var headers = splitHeaders(req);
        document.getElementById("ldrPinRead").innerHTML = headers.pin;  
      });  
    }

    function begin() {
      requestGet("/get", (req) => {
        createCards(splitHeaders(req));
      });  
    }

    function restartDevice() {
      const xhr = new XMLHttpRequest();
      xhr.open('POST', '/restart');
      xhr.send();
    }

    function loadChangeFirmwarePage() {
      const xhr = new XMLHttpRequest();
      xhr.open('GET', '/change_firmware');
      xhr.send();
      setTimeout(function() {
        location.reload();
      }, 1000);
    }

    //Local
    //createCards({ "displayBright": 30, "swapBlueGreen": 1, "use24hFormat": 0, "timeZone": "Europe/Lisbon", "ntpServer": "pool.ntp.org", "wifiSsid": "test", "autoBrightMin":0, "autoBrightMax":800, "ldrPin":35, "cw_fw_version":"1.2.2", "clockface_name":"cw-cf-0x07", "canvasServer":"raw.githubusercontent.com", "canvasFile":"star-wars.json" });

    //Embedded
    begin();

  </script>
</body>
</html>
)"""";


/* Style */
String style =
    "<style>#file-input,input{width:100%;height:44px;border-radius:4px;margin:10px auto;font-size:15px}"
    "input{background:#f1f1f1;border:0;padding:0 15px}body{background:#3498db;font-family:sans-serif;font-size:14px;color:#777}"
    "#file-input{padding:0;border:1px solid #ddd;line-height:44px;text-align:left;display:block;cursor:pointer}"
    "#bar,#prgbar{background-color:#f1f1f1;border-radius:10px}#bar{background-color:#3498db;width:0%;height:10px}"
    "form{background:#fff;max-width:258px;margin:75px auto;padding:30px;border-radius:5px;text-align:center}"
    ".btn{background:#3498db;color:#fff;border-radius:5px;cursor:pointer}</style>";

String changeFirmwarePage =
    "<script src='https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js'></script>"

    "<form name=settingsForm>"
    "<h2>Settings</h2>"
    "<p>Click this instead of the browser Back Button.</p>"
    "<input onclick=gotoSettings() class=btn id='gotoSettingsButton' value='Go to Settings'></form>"

    "<form method='POST' action='#' enctype='multipart/form-data' id='upload_form'>"
    "<h2>Update Firmware</h2>"
    "<p>Change to a different theme.</p>"
    "<input type='file' name='update' id='file' onchange='sub(this)' style=display:none>"
    "<label id='file-input' for='file'>   Choose file...</label>"
    "<input type='submit' class=btn value='Update Firmware'>"
    "<br><br>"
    "<div id='prg'></div>"
    "<br><div id='prgbar'><div id='bar'></div></div><br></form>"

    "<form name=resetForm>"
    "<h2>Reset WiFi</h2>"
    "<p>This will reset the WiFi configuration.</p>"
    "<input onclick=resetWiFi() class=btn id='resetWifiButton' value='Reset WiFi'></form>"

    "<script>"
    "function gotoSettings() {"
    "var xhr = new XMLHttpRequest();"
    "xhr.open('GET', '/goto_settings');"
    "xhr.send();"
    "setTimeout(function() {"
    "location.reload();"
    "}, 1000);"
    "}"

    "function resetWiFi() {"
    "if (confirm('Are you sure you want to reset the WiFi? This will clear WiFi configuration.')) {"
    "window.location.href = '/reset_wifi';"
    "}"
    "}"

    "function sub(obj){"
    "var fileName = obj.value.split('\\\\');"
    "document.getElementById('file-input').innerHTML = '   '+ fileName[fileName.length-1];"
    "};"

    "$('form').submit(function(e){"
    "e.preventDefault();"
    "var form = $('#upload_form')[0];"
    "var data = new FormData(form);"
    "$.ajax({"
    "url: '/update_firmware',"
    "type: 'POST',"
    "data: data,"
    "contentType: false,"
    "processData: false,"
    "xhr: function() {"
    "var xhr = new window.XMLHttpRequest();"
    "xhr.upload.addEventListener('progress', function(evt) {"
    "if (evt.lengthComputable) {"
    "var per = evt.loaded / evt.total;"
    "$('#prg').html('progress: ' + Math.round(per*100) + '%');"
    "$('#bar').css('width',Math.round(per*100) + '%');"
    "}"
    "}, false);"
    "return xhr;"
    "},"
    "success:function(d, s) {"
    "console.log('success!');"
    "},"
    "error: function (a, b, c) {"
    "}"
    "});"
    "});"
    "</script>" +
    style;
