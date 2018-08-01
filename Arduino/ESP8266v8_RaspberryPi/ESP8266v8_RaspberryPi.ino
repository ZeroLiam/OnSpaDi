#include "WiFiEsp.h"

#include <SoftwareSerial.h>

SoftwareSerial Serial1(3,2); // RX, TX

char ssid[] = "Lexa";            // your network SSID (name)
char pass[] = "getInNow5";        // your network password
int status = WL_IDLE_STATUS;     // the Wifi radio's status

//char server[] = "api.thingspeak.com";
char server[] = "141.54.50.6";

// Initialize the Ethernet client object
WiFiEspClient client;

void setup()
{
  // initialize serial for debugging
  Serial.begin(115200);
  // initialize serial for ESP module
  Serial1.begin(115200);
  // initialize ESP module
  WiFi.init(&Serial1);

  // check for the presence of the shield
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue
    while (true);
  }

  // attempt to connect to WiFi network
  while ( status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass);
  }

  // you're connected now, so print out the data
  Serial.println("You're connected to the network");
  
  printWifiStatus();
  int valSensor = getSensorData();

  Serial.println();
  Serial.println("Starting connection to server...");
  // if you get a connection, report back via serial
  if (client.connect(server, 8888)) {
    Serial.println("Connected to server");
    // Make a HTTP request
    client.println("GET 141.54.50.6");
//    client.println("GET https://api.thingspeak.com/update?api_key=71FA2ETD4HS7EUVI&field1="+String(valSensor));
    client.println("Host: 141.54.50.6");
    client.println("Connection: close");
    client.println();
  }
}

int getSensorData(){
  return random(100); // Replace with 
}


void loop()
{
  
  int valSensor = getSensorData();
  // if there are incoming bytes available
  // from the server, read them and print them
  while (client.available()) {
    char c = client.read();
    client.println("GET https://api.thingspeak.com/update?api_key=71FA2ETD4HS7EUVI&field1="+String(valSensor));
    client.println("Host: api.thingspeak.com");
    Serial.write(c);
    printWifiStatus();
  }

  // if the server's disconnected, stop the client
//  if (!client.connected()) {
//    Serial.println();
//    Serial.println("Disconnecting from server...");
//    client.stop();
//
//    // do nothing forevermore
//    while (true);
//  }
}


void printWifiStatus()
{
  // print the SSID of the network you're attached to
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength
  long rssi = WiFi.RSSI();
  Serial.print("Signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
