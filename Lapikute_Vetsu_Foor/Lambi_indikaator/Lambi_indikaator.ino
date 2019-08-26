/*
  The following code is for Wemos D1 mini (https://wiki.wemos.cc/products:retired:d1_mini_v2.3.0)
  These boards will connect to the same power source as the lamps and will connect to a predefined
  Wi-Fi network when powered. They are used as wireless indicators of the current bathroom state.
  These boards only support a 2.4GHz 802.11b/g/n connection.
*/

/* Includes ----------------------------------------- */
#include <ESP8266WiFi.h> // https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WiFi

/* Global variables --------------------------------- */
//SSID of your network
const char ssid[] = "Lapikud";  //SSID of your Wi-Fi network
const char pass[] = "wifiparool"; //Password of your Wi-Fi network

/* Setup -------------------------------------------- */
void setup()
{
  Serial.begin(115200);
  delay(10);

  // Setup the builtin led for indication
  pinMode(LED_BUILTIN, OUTPUT); // it is the ground pin for the LED, so LOW means LED is On

  // Connect to Wi-Fi network
  Serial.println();
  Serial.print("Connecting to:  ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Wi-Fi connected successfully, with IP: ");
  Serial.println(WiFi.localIP());
}
void loop () {
  if (WiFi.status() == WL_CONNECTED) { // If connection still exists
    digitalWrite(LED_BUILTIN, HIGH); // Turn the LED off if ping was successful
  } else { // Else try to reconnect

    Serial.println("Lost connection to wifi, trying to reconnect");
    WiFi.begin(ssid, pass);
    for (byte i = 0; i < 15; i++) {
      digitalWrite(LED_BUILTIN, HIGH);
      delay(100);
      digitalWrite(LED_BUILTIN, LOW);
      delay(100);
    }
    digitalWrite(LED_BUILTIN, LOW); // Leave the LED on after indication
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
    Serial.println("");
    Serial.print("Wi-Fi reconnected successfully, with IP: ");
    Serial.println(WiFi.localIP());
  }
  delay(5000); // Wait 5s before testing the connection again
}
