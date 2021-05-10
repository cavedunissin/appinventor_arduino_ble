#include <SoftwareSerial.h>
SoftwareSerial HM10(7, 8); // RX = 2, TX = 3
// addr example D8:A9:8B:7B:79:E4 HMSsoft
char appData;
String inData = "";
int x = 0;
void setup()
{
  Serial.begin(9600);
  Serial.println("HM10 serial started at 9600");
  HM10.begin(9600); // set HM10 serial at 9600 baud rate
  pinMode(4, OUTPUT); // onboard LED
  digitalWrite(4, LOW); // switch OFF LED
}

void loop()
{
  HM10.listen();  // listen the HM10 port
  while (HM10.available() > 0) {   // if HM10 sends something then read
    appData = HM10.read();
    //Data = int(appData);
    //x = int(appData);
    inData = String(appData);  // save the data in string format
    Serial.println(inData);
    Serial.println(appData);
    //Serial.write(appData);
  }
  //Serial.println(appData);
  /**if (Serial.available()) {           // Read user input if available.
    delay(10);
    HM10.write(Serial.read());
  }**/
  if ( inData == "f") {  //原本為""
    Serial.println("LED OFF");
    digitalWrite(4, LOW); // switch OFF LED
    delay(500);
  }
  if ( inData == "o") {
    Serial.println("LED ON");
    digitalWrite(4, HIGH); // switch OFF LED
    delay(500);
  }
}
