//Stationary point mode --> additional point like mobile hotspot.
//Access point mode --> router is access point.


#include <WiFi.h> //accept the parameters and make wifi available.
#include <WiFiClient.h>
#include <WebServer.h> //connecting to https networks.
#include <ESPmDNS.h>

const char* ssid = "topC";
const char* password = "password";

WebServer server(80); //An instance of the WebServer class is created, which will handle incoming HTTP requests on port 80.

const int led = 42;

void handleRoot() {
  digitalWrite(led, HIGH);
  int rn=random(1,300);
  String string="<html><body><p>line 1<p> ";
  string +="number is "+String(rn) ;
  string +="<p>line 2<p><body><html>";
  server.send(200,"text/html",string);
  digitalWrite(led, LOW);
}

void handleNotFound() {
  digitalWrite(led, HIGH);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);     //send an HTTP response from the ESP32 web server to a client
  digitalWrite(led, LOW);
}

void setup(void) {
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);
  Serial.begin(115200);    //starts serial port communication
  WiFi.mode(WIFI_STA);   // Set Wi-Fi mode to Station (client) mode
  WiFi.begin(ssid, password);   // Connect to the specified Wi-Fi network
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) { //check whether connected to wifi or not.
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp32")) {  //initializes the mDNS responder on the ESP32 device
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);    // Register the route handler for the root URL

  server.on("/inline", []() {     //defines a route handler for the path "/inline"
    server.send(200, "text/html", "HARI AUM TAT SAT");
  });

  server.onNotFound(handleNotFound);    // Catch-all for not found paths

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();    // Process incoming client requests
  delay(2);//allow the cpu to switch to other tasks
}
