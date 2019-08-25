/*
  The following code is for Wemos D1 mini (https://wiki.wemos.cc/products:retired:d1_mini_v2.3.0)
  These boards will connect to the same power source as the lamps and will connect to a predefined
  Wi-Fi network when powered. They are used as wireless indicators of the current bathroom state.
  These boards only support a 2.4GHz 802.11b/g/n connection.
*/

/* Includes ----------------------------------------- */
#include <ESP8266WiFi.h> // https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WiFi
#include <ESP8266Ping.h> // https://github.com/dancol90/ESP8266Ping

/* Global variables --------------------------------- */
//SSID of your network
const char ssid[] = "Testing";  //SSID of your Wi-Fi network
const char pass[] = "12345678"; //Password of your Wi-Fi network

// Aadress to test connection against (prolly router itself)
IPAddress ip (192, 168, 10, 1); // Testing the connection

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
    bool ret = Ping.ping(ip, 1); // This is just a secondary check to a desired client on the network
    int response_time = Ping.averageTime();
    Serial.print("Pinging: ");
    Serial.print(ip);
    Serial.print(" received-response: ");
    Serial.print((ret) ? ("true") : ("false"));
    Serial.print(" time: ");
    Serial.print(response_time);
    Serial.println("ms");
    if (!ret) { // Indicate error, via the builtin LED
      // Initialize builtin LED
      for (byte i = 0; i < 15; i++) {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(100);
        digitalWrite(LED_BUILTIN, LOW);
        delay(100);
      }
      digitalWrite(LED_BUILTIN, LOW); // Leave the LED on after indication
    } else {
      digitalWrite(LED_BUILTIN, HIGH); // Turn the LED off if ping was successful
    }
  } else { // Else try to reconnect
    Serial.println("Lost connection to wifi, trying to reconnect");
    WiFi.begin(ssid, pass);
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
