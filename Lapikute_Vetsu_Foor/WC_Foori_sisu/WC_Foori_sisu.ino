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
const char ssid[] = "Lapikud";  //SSID of your Wi-Fi network
const char pass[] = "wifiparool"; //Password of your Wi-Fi network

// Static IPs of the two clients
IPAddress dest0 (172, 20, 20, 69); // Defined in the WiFi DNS
IPAddress dest1 (172, 20, 20, 70); // Defined in the WiFi DNS


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


    bool resp0 = Ping.ping(dest0, 1); // This is just a secondary check to a desired client on the network
    int response_time0 = Ping.averageTime();
    bool resp1 = Ping.ping(dest1, 1);
    int response_time1 = Ping.averageTime();
    Serial.print("Pinging: ");
    Serial.print(dest0);
    Serial.print(" received-response: ");
    Serial.print((resp0) ? ("true") : ("false"));
    Serial.print(" time: ");
    Serial.print(response_time0);
    Serial.println("ms");
    Serial.print("Pinging: ");
    Serial.print(dest1);
    Serial.print(" received-response: ");
    Serial.print((resp1) ? ("true") : ("false"));
    Serial.print(" time: ");
    Serial.print(response_time1);
    Serial.println("ms");
    
    Serial.print((resp0 && resp1)?("--- Bathrooms occupied"):("--- Atleast one bathroom free"));
    Serial.print(" Status: [");
    Serial.print(resp0);
    Serial.print(",");
    Serial.print(resp1);
    Serial.println("] ---");
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
