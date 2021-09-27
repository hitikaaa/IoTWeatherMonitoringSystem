#include <LiquidCrystal.h>
#include "DHT.h"
#define DHTPIN 8            
 
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
int Gas = 9; 
int rain = 10;
#define DHTTYPE DHT11       
DHT dht(DHTPIN, DHTTYPE);   
 
char temperature[] = "Temp = 00.0 C  ";
char humidity[]    = "RH   = 00.0 %  ";
void setup() {
  lcd.begin(16, 4);
  dht.begin();
  pinMode(Gas , INPUT);
  pinMode(rain, INPUT);
}
 
void loop() {
  delay(300);           
  // Read humidity
  byte RH = dht.readHumidity();
  //Read temperature in degree Celsius
  byte Temp = dht.readTemperature();
  
  // Check if any reads failed and exit early (to try again)
  if (isnan(RH) || isnan(Temp)) {
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("Error");
    return;
  }
  temperature[7]     = Temp / 10 + 48;
  temperature[8]     = Temp % 10 + 48;
  temperature[11]    = 223;
  humidity[7]        = RH / 10 + 48;
  humidity[8]        = RH % 10 + 48;
  lcd.setCursor(0, 0);
  lcd.print(temperature);
  lcd.setCursor(0, 1);
  lcd.print(humidity);

   if(digitalRead(Gas) == HIGH)
  {
    lcd.setCursor(0,2);
    lcd.print("Gas Detected Yes");
    delay(200);
  }
else
{
  lcd.setCursor(0,2);
  lcd.print(" No Gas Detected ");
  delay(200);
}
if(digitalRead(rain)==HIGH)
{
   lcd.setCursor(0,3);
  lcd.print("It's Raning");
  delay(200);
}
if(digitalRead(rain)==LOW)
{
  lcd.setCursor(0,3);
  lcd.print("Not Raning ");
  delay(200);
}
}
