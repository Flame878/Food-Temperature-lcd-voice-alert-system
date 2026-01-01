#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>
#define ONE_WIRE_BUS 5

LiquidCrystal lcd(12,11,10,9,8,7);
OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

//const int recordPin = 3;
const int playEPin = 2;
void setup() {
  
//pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
  Serial.begin(9600);
  Serial.println("Dallas Temp Start");
  sensors.begin();
  Serial.println("Starting ISD");
  lcd.begin(16, 2);
  lcd.print("Temperature F/C: ");

}
 void playback(int playEPin){
    digitalWrite(2, HIGH);
    delay(1000);
    digitalWrite(2,LOW);
    delay(1000);
  }
  void LCDTemp_Loop(float tempF, float tempC){
    lcd.setCursor(0, 1);
    lcd.print("                ");
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print(tempF);
    lcd.print(" In Ferin");
    delay(5000);
    lcd.setCursor(0, 1);
    lcd.print("                ");
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print(tempC);
    lcd.print(" In Celsius");
    delay(5000);
  }
void loop() {
  Serial.print("Requesting Tempretures");
  sensors.requestTemperatures();
  Serial.println("Finished");

  float tempC = sensors.getTempCByIndex(0);
  float tempF = sensors.getTempFByIndex(0);


  if (tempC < 62 or tempF < 145){
    Serial.print("Temperature in Fahrenheit: ");
    Serial.print(tempF);
    Serial.print("\n Temperature in Celsius: ");
    Serial.print(tempC);
    LCDTemp_Loop(tempF, tempC);
    Serial.println("\n Temperature is below Requried amount turn Up!");
   // delay(10000);
  }
  else if (tempC > 62 or tempF > 145){
    Serial.print("Temperature in Fahrenheit: ");
    Serial.print(tempF);
    Serial.print("\n Temperature in Celsius: ");
    Serial.print(tempC);
    LCDTemp_Loop(tempF, tempC);
    playback(playEPin);
    Serial.println(" \n Temperature is above Good Nice!");
    
  }
  else{
    Serial.println("dnk");
  }
 
}