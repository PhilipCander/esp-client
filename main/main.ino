#include <ESP8266WiFi.h>

const char* ssid = "your_SSID"; // Replace with your Wi-Fi network SSID
const char* password = "your_PASSWORD"; // Replace with your Wi-Fi network password
const char* host = "192.168.1.100"; // Replace with the IP address of your server

void setup() {
  Serial.begin(115200);
  delay(10);

  // Connect to Wi-Fi
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;

    // Replace with your server IP and the path you want to send data to
    if (client.connect(host, 80)) {
      Serial.println("Connected to server");
      client.println("POST /path/to/your/endpoint HTTP/1.1");
      client.println("Host: 192.168.1.100"); // Replace with your server IP
      client.println("Content-Type: application/x-www-form-urlencoded");
      client.print("Content-Length: ");
      client.println(strlen("your_string_data"));
      client.println();
      client.println("your_string_data"); // Replace with the data you want to send
      delay(100);
    } else {
      Serial.println("Connection to server failed");
    }

    // Close the connection
    client.stop();
  } else {
    Serial.println("WiFi Disconnected");
  }

  delay(5000); // Delay for 5 seconds before sending the next request
}
