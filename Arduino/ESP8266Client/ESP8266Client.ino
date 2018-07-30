#include<stdlib.h>
#include <SoftwareSerial.h>
#define RX 3
#define TX 2

String AP = "Lexa";       // CHANGE ME
String PASS = "getInNow5"; // CHANGE ME
String API = "71FA2ETD4HS7EUVI";   // CHANGE ME
String HOST = "api.thingspeak.com";
String PORT = "80";
String field = "field1";
int countTrueCommand;
int countTimeCommand; 
boolean found = false; 
int valSensor = 1;
String s = "";
  String result;
SoftwareSerial esp8266(RX,TX); 


String sendCommand(const char *toSend, unsigned long milliseconds) {
  String result;
  Serial.print("Sending: ");
  Serial.println(toSend);
  monitor.println(toSend);
  unsigned long startTime = millis();
  Serial.print("Received: ");
  while (millis() - startTime < milliseconds) {
    if (monitor.available()) {
      char c = monitor.read();
      Serial.write(c);
      result += c;  // append to the result string
    }
    Serial.println();
  }
  return result;
}

void setup() {
  
 Serial.begin(9600);
 esp8266.begin(9600);

 sendCommand("AT", 1000, "OK");

   result = sendCommand("AT+CWJAP=\"Lexa\",\"getInNow5\"", 5000);
  if (result.indexOf("OK") != -1)
    Serial.println("JAP worked");

  result = sendCommand("AT+CIPSTART=0,\"TCP\",\"api.thingspeak.com\",80", 2000, "OK");
  if (result.indexOf("OK") != -1)
    Serial.println("CIPSTART worked");

  result = sendCommand("AT+CIPSEND=0,110", 2000, "OK");
  if (result.indexOf(">") != -1)
    Serial.println("CIPSEND worked");

  result = sendCommand("GET https://api.thingspeak.com/update?api_key=71FA2ETD4HS7EUVI&field1=13", 10000);
}

void loop(){
    Serial.println(result);
}



