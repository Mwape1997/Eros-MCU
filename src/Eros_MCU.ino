/*Author: Mwape
 * Date: 2018
 * V1
 * For use with NODEMCU

*/

#include <ESP8266WiFi.h>
#include <Wire.h>

 char ssid[] = "ABC";
 char pass[] = "123";

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  pinMode(D5, OUTPUT);


   Serial.begin(9600); /* begin serial for debug */
 Wire.begin(D1, D2); /* join i2c bus with SDA=D1 and SCL=D2 of NodeMCU */

Serial.print("Attempting to connect...");

 WiFi.disconnect();
 WiFi.begin(ssid,pass);
 delay(500);

 while(WiFi.status() != WL_CONNECTED){
  digitalWrite(D5, LOW);
  delay(500);
  Serial.println(",");
 }
 digitalWrite(D5, LOW);

 Serial.print("SSID....,");
 Serial.println(WiFi.SSID());
 Serial.println("Successfully connected...");

 Serial.print("IP address of MCU: ");
 Serial.print(WiFi.macAddress());
 WiFi.printDiag(Serial);

}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level
                                    // but actually the LED is on; this is because
                                    // it is active low on the ESP-01)
  delay(1000);                      // Wait for a second
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(1000);                      // Wait for two seconds (to demonstrate the active low LED)

  Wire.beginTransmission(8); /* begin with device address 8 */
 Wire.write("Hello Arduino");  /* sends hello string */
 Wire.endTransmission();    /* stop transmitting */

 Wire.requestFrom(8, 13); /* request & read data of size 13 from slave */
 while(Wire.available()){
    char c = Wire.read();
  Serial.print(c);
 }
 Serial.println();
 delay(1000);
}
