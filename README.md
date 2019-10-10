<img align="left" width="160" height="110" src="https://i.imgur.com/LRG8dA1.jpg">

# kortexA1_codeFiles
A simple guide for using Kortex A1 Dec board

# Kortex A1 All-in-one development board
Kortex A1 is a WiFi enabled multi-sensor development board for environment monitoring and wireless control. It's like an Arduino UNO but with lots of available components such as environmetal sensors and an ESP8266 that make this board universal for almost any project idea.
<p align="center">
  <img width="460" height="300" src="https://cdn.tindiemedia.com/images/resize/itDjxbigkN4QkDhZrZ5ShPI5YtE=/p/fit-in/653x435/filters:fill(fff)/i/561311/products/2018-06-07T19%3A16%3A56.940Z-IMG_20180105_192122.jpg">
</p>

## Getting Started

Imagine having your own monitoring system capable of recording environment status, visualizing data on your computer or turning things on and off wherever you are on the planet, sounds cool right?
In these steps I'll be showing you how to take maximum advantage of Kortex A1 and its capabilities, so you can build almost any project without having to learn all electronics basics, just upload the code and enjoy!

### Prerequisites


**1-** Get a [Kortex A1](https://www.tindie.com/products/kortex_am/kortex-a1--wifi-multi-sensor-development-board-2/) board

**2-** Install the [CP2104 Driver](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers) 

**3-** Install the [Arduino IDE](https://www.google.com). (Before uploading the code to your Kortex A1, remember to set the board on the Arduino IDE to Arduino UNO/
   Genuino UNO, so the IDE will recognise your Kortex A1)


## Running Blynk
<img align="left" width="100" height="100" src="https://cdn6.aptoide.com/imgs/8/9/a/89a2feafbafc451bd21b1e8f9b0d9c1c_icon.png?w=256">
For running Blynk with your Kortex A1 there are two code scripts, the one called "KORTEXA1_BLYNK_BLANK" comes with no dashboard configured onto it, and "KORTEXA1_BLYNK_DASHB1" comes with a dashboard made from a set of widgets (1 chart, 4 data panels and 1 button). 
If you want to create your own dashboard you can use and modify "KORTEXA1_BLYNK_BLANK" code so it can be interfaced through your Blynk dashbaord, here there's some ([documentation](http://docs.blynk.cc/)) on how to do it.

To link your Kortex A1 to the Blynk dashboard (DASHB1) that I built, just follow these steps:
(note that these steps are only for "KORTEXA1_BLYNK_DASHB1")

**1-** Download [Blynk](https://www.tindie.com/products/kortex_am/kortex-a1--wifi-multi-sensor-development-board-2/) from the play store.

**2-** Once you have downloaded the app, register and create an account.

**3-** Create your first project, and copy your AUTH_KEY which we will use later on our code ([more info](http://docs.blynk.cc/))

**4-** On project settings, give your project a name, and on hardware model select Arduino UNO

**5-** Now you have to setup your dashboard. Remember that Blynk gives you only 1000 of power, so take advantage of it. 
Start by adding a chart with 4 sources of data (temperature/humidity/pressure/altitude), also add 4 data panels which will visualize    in numbers the received data such as temperature, pressure, etc..... finally add a pushbutton.

**6-** Once you have added all the widgets, now it's time to configure them. Start by linking the pushbutton to digital pin 13 (D13). Then  you'll have to configure the 4 data panels. The first data panel which corresponds to "temperature", must be linked to virtual pin  0.The second data panel corresponds to "humidity" and has to be linked to virtual pin 1, the third data panel corresponds to "altitude" and its virtual pin is 2, and finally the fourth data panel correspnds to "pressure" and also has to be linked to virtual pin 3.

**7-** Now that you have successfully created and configured your Blynk dashboard, you have to make some modifications in the code (KORTEXA1_BLTNK_DASHB1). Start by 
   pasting your **AUTH_KEY** **where it says YOUR_AUTH_KEY:
 ```
   char auth[] = "YOUR_AUTH_KEY";
  ```
   Then add your access point SSID and password (AP_SSID / AP_PASS)
   ```
   Blynk.begin(auth, wifi, "AP_SSID", "AP_PASS"); // Initilize Blynk
 ```

**8-** Finally upload the code to your Kortex A1 board and open serial monitor at 9600 baud. You'll see that the noard will connect to your access point and it will 
   automatically start pushing data to Blynk server. Now open your Blynk app and enjoy your wireless monitoring! (make sure that D13 led works when you toggle your pushbutton! ;)

[Here's a demo video of how it should work](https://www.youtube.com/watch?v=qijERRKEPd8)

