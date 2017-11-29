#include<ESP8266WiFi.h>

WiFiServer server(80); // Initalize a server on port 80
int LED_PIN = 13; // Mapped to D7

void setup() 
{
  WiFi.mode(WIFI_AP); // Setup the ESP8266 as access point
  WiFi.softAP("Hello_IoT", "12345678"); // Provide SSID and passwords  
  server.begin(); // Start the HTTP server
 
  // initialize digital pin 13 as an output.
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW); //Initial state is OFF

  Serial.begin(9600); // Communication between ESP8266 and serial monitor
  IPAddress HTTPS_ServerIP = WiFi.softAPIP(); // Obtain the IP of the Server 
  Serial.print("Server IP is: "); // Print the IP to the monitor window 
  Serial.println(HTTPS_ServerIP);
}

void loop() {
  WiFiClient client = server.available();
  if (!client) { 
      return; 
  } 
  //Looking under the hood 
  Serial.println("Somebody has connected :)");

  //Read what the browser has sent into a String class and print the request to the monitor
  // String request = client.readString(); 
  String request = client.readStringUntil('\r');

  //Looking under the hood 
  Serial.println(request);

  if (request.indexOf("/OFF") != -1)
  { 
    digitalWrite(LED_PIN, LOW); 
  }
  else if (request.indexOf("/ON") != -1)
  { 
    digitalWrite(LED_PIN, HIGH); 
  }

  String s = "HTTP/1.1 200 OK\r\n";
  s += "Content-Type: text/html\r\n\r\n";
  s += "<!DOCTYPE html>\r\n<html>";
  s += "<head><title>Title of the document</title></head>";
  s += "<body>";
  s += "<p><input =\"button\" name=\"b1\" value=\"Turn LED on\" onclick=\"location.href='/ON'\"></p>";
  s += "<p><input =\"button\" name=\"b1\" value=\"Turn LED off\" onclick=\"location.href='/OFF'\"></p>";
  s += "</body>";
  s += "</html>";

  client.flush(); //clear previous info in the stream 
  client.print(s); // Send the response to the client 
  delay(1); 
  Serial.println("Client disconnected"); //Looking under the hood
}
