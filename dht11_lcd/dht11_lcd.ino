#include <LiquidCrystal_I2C.h>  //Kütüphaneleri anlat
#include <DHT.h>
#include <Wire.h>

#define DHTPIN 2           //Burada sensörün sinyal pininin nereye bağlanacağını seçiyorum
#define DHTTYPE DHT11      //Burada sensör modelini ayarlıyorum
DHT dht(DHTPIN, DHTTYPE);  //pin ve model bilgilerini DHT değişkeninin içine atıyorum.

LiquidCrystal_I2C lcd(0x27, 16, 2);


int ledy = 8;
int ledk = 9;

void setup() {
  lcd.init();
  lcd.backlight();
  dht.begin();
  Serial.begin(9600);

  pinMode(ledy, OUTPUT);
  pinMode(ledk, OUTPUT);

  lcd.setCursor(2, 0);
  lcd.print("ELKA BILISIM");
  lcd.setCursor(3, 1);
  lcd.print("TERMOMETRE");
  delay(5000);
  lcd.clear();
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  lcd.setCursor(1, 0);
  lcd.print("SICAKLIK:");
  lcd.setCursor(7, 1);
  lcd.print("C");
  lcd.setCursor(11, 0);
  lcd.print("NEM:");
  lcd.setCursor(11, 1);
  lcd.print("%");

  lcd.setCursor(2, 1);
  lcd.print(temperature, 1);

  lcd.setCursor(12, 1);
  lcd.print(humidity, 0);


  if (temperature < 20)  //1.koşul:düşük sıcaklık uyarısı
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("DUSUK SICAKLIK");
    delay(1000);
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("SICAKLIK:");
    lcd.setCursor(7, 1);
    lcd.print("C");
    lcd.setCursor(11, 0);
    lcd.print("NEM:");
    lcd.setCursor(11, 1);
    lcd.print("%");

    lcd.setCursor(2, 1);
    lcd.print(temperature, 1);

    lcd.setCursor(12, 1);
    lcd.print(humidity, 0);
    delay(1000);
  }

  if (temperature > 25) //2.koşul:yüksek sıcaklık uyarısı 
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("YUKSEK SICAKLIK");
    delay(1000);
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("SICAKLIK:");
    lcd.setCursor(7, 1);
    lcd.print("C");
    lcd.setCursor(11, 0);
    lcd.print("NEM:");
    lcd.setCursor(11, 1);
    lcd.print("%");

    lcd.setCursor(2, 1);
    lcd.print(temperature, 1);

    lcd.setCursor(12, 1);
    lcd.print(humidity, 0);
    delay(1000);
  }

  if (humidity < 40) //düşük nem uyarısı 
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("DUSUK HAVA NEMI");
    delay(1000);
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("SICAKLIK:");
    lcd.setCursor(7, 1);
    lcd.print("C");
    lcd.setCursor(11, 0);
    lcd.print("NEM:");
    lcd.setCursor(11, 1);
    lcd.print("%");

    lcd.setCursor(2, 1);
    lcd.print(temperature, 1);

    lcd.setCursor(12, 1);
    lcd.print(humidity, 0);
    delay(1000);
  }

  if (humidity > 60) //yüksek nem uyarısı
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("YUKSEK HAVA NEMI");
    delay(1000);
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("SICAKLIK:");
    lcd.setCursor(7, 1);
    lcd.print("C");
    lcd.setCursor(11, 0);
    lcd.print("NEM:");
    lcd.setCursor(11, 1);
    lcd.print("%");

    lcd.setCursor(2, 1);
    lcd.print(temperature, 1);

    lcd.setCursor(12, 1);
    lcd.print(humidity, 0);
    delay(1000);
  }
}
