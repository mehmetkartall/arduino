#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define DHTPIN 2
#define DHTTYPE DHT11 //AAB
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();       //LCD'Yİ BAŞLATTIM
  lcd.backlight();  // LCD'NİN ARKA IŞIĞINI AKTİFLEŞTİRDİM
  dht.begin();      // SICAKLIK VE NEM SENSÖRÜMÜ BAŞLATTIM

  lcd.setCursor(6, 0);
  lcd.print("ELKA");
  lcd.setCursor(5, 1);
  lcd.print("BILISIM");
  delay(5000);
  lcd.clear();
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  lcd.setCursor(1, 0);
  lcd.print("SICAKLIK:");
  lcd.setCursor(11, 0);
  lcd.print("NEM:");
  lcd.setCursor(2, 1);
  lcd.print(temperature, 1);
  lcd.setCursor(7, 1);
  lcd.print("C");
  lcd.setCursor(12, 1);
  lcd.print(humidity, 0);
  lcd.setCursor(11, 1);
  lcd.print("%");


  if (temperature < 18) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("DUSUK SICAKLIK");
    delay(2000);
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("SICAKLIK:");
    lcd.setCursor(11, 0);
    lcd.print("NEM:");
    lcd.setCursor(2, 1);
    lcd.print(temperature, 1);
    lcd.setCursor(7, 1);
    lcd.print("C");
    lcd.setCursor(12, 1);
    lcd.print(humidity, 0);
    lcd.setCursor(11, 1);
    lcd.print("%");
    delay(1000);
  }

  if (temperature > 26) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("YUKSEK SICAKLIK");
    delay(2000);
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("SICAKLIK:");
    lcd.setCursor(11, 0);
    lcd.print("NEM:");
    lcd.setCursor(2, 1);
    lcd.print(temperature, 1);
    lcd.setCursor(7, 1);
    lcd.print("C");
    lcd.setCursor(12, 1);
    lcd.print(humidity, 0);
    lcd.setCursor(11, 1);
    lcd.print("%");
    delay(1000);
  }
}
