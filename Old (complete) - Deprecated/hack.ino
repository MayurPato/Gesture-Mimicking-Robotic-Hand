#define BLYNK_TEMPLATE_ID "TMPLsYSO7d2F"
#define BLYNK_DEVICE_NAME "Hack"
#define BLYNK_AUTH_TOKEN "UyCQT6zof3Ll3YCZ6JB5ucniV5bP0aqs"
#define BLYNK_PRINT Serial
#include<Servo.h>

Servo Motor;
Servo Motor2;
Servo Motor3;

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
WiFiClient wiFiClient;

int val;

char auth[] = BLYNK_AUTH_TOKEN ;
char ssid[] = "pato";
char pass[] = "mayurpato";

BLYNK_WRITE(V0)
{
  val = param.asInt();
}


void handcontrol()
{
  if (val == 1)
  {
    Serial.println("One up");
    Motor.write(180);
    Motor2.write(180);
    Motor3.write(180);
  }
  else if (val == 2)
    {
      Serial.println("two up");
      Motor.write(0);
      Motor2.write(180);
      Motor3.write(180);
    }
  else if (val == 3 || val == 5 || val == 4)
  {
    Serial.println("three up");
    Motor.write(0);
    Motor2.write(0);
    Motor3.write(180);
  }
  else 
  {
    Serial.println("None up");
    Motor.write(180);
    Motor2.write(180);
    Motor3.write(0);
  }
}

void setup() {
   Serial.begin(115200);
   Blynk.begin(auth, ssid, pass);
   Motor.attach(D2);
   Motor2.attach(D5);
   Motor3.attach(D6);
   Motor.write(180);
   Motor2.write(180);
   Motor3.write(180);
}

void loop() 
{
  Blynk.run();
  handcontrol();
}
