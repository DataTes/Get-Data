/*
  This code will fetch the latest data from your antares project device.
  Your Antares project device must have a structure like this:
  (Note that nesting the JSON object can only be done up to 2 levels using this library)
  {
    "temperature": some-integer,
    "humidity": some-integer,
    "wind_speed": some-float,
    "rain_level": some-float,
    "location" : {
      "latitude": "static-string",
      "longitude": "static-string"
    }
  }
  For more information please visit https://antares.id/id/docs.html
*/

#include <AntaresESPHTTP.h>  // Include the AntaresESP32HTTP library

#define ACCESSKEY "a1a24854e75fb4a6:5f10fe29734dd905"    // Replace with your Antares account access key
#define WIFISSID "A4ple"      // Replace with your Wi-Fi SSID
#define PASSWORD "12345678"  // Replace with your Wi-Fi password

#define projectName "data_12"  // Antares project name
#define deviceName "data_123"   // Name of the device

AntaresESPHTTP antares(ACCESSKEY);  // Initialize AntaresESP32HTTP with the access key

void setup() {
  Serial.begin(115200);                        // Initialize serial communication
  antares.setDebug(true);                      // Enable Antares library debug mode
  antares.wifiConnection(WIFISSID, PASSWORD);  // Connect to WiFi using provided SSID and password
}

void loop() {
  // Get the latest data from your Antares device
  antares.get(projectName, deviceName);

  // Check if we're actually getting data
  if (antares.getSuccess()) {
    int temp = antares.getInt("temperature");
    int hum = antares.getInt("humidity");

    Serial.println("Temperature: " + String(temp));
    Serial.println("Humidity: " + String(hum));
  }
  delay(5000);
}