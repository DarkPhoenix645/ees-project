#include <SPI.h>
#include <LoRa.h> 
String inString = "";    // string to hold input
int val = 0;
 
void setup() 
{
  Serial.begin(9600);
  
  while (!Serial);
  Serial.println("LoRa Receiver");
  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}
 
void loop() 
{
    if (Serial.read() == 's') 
    {
        // try to parse packet
        int packetSize = LoRa.parsePacket();
        if (packetSize) {
            while (LoRa.available())
            {
                int inChar = LoRa.read();
                inString += (char)inChar;
                val = inString.toInt();       
            }   
            LoRa.packetRssi();    
        }
            
        Serial.println(inString);
        inString = "";
    }
}