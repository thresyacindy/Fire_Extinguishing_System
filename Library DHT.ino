#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define asapSensorPin A0
#define apiSensorPin A2
#define led_merah 3
#define led_kuning 4
#define led_hijau 5
#define RELAY_ON 0
#define RELAY_OFF 1
#define RELAY_1 2
#define suhuon 11
#define suhuoff 12
#define DHTPIN A1
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    lcd.init();
    lcd.backlight();

    pinMode(asapSensorPin, INPUT);
    pinMode(apiSensorPin, INPUT);
    pinMode(led_merah, OUTPUT);
    pinMode(led_kuning, OUTPUT);
    pinMode(led_hijau, OUTPUT);
    pinMode(RELAY_1, OUTPUT);
    pinMode(suhuon, OUTPUT);
    pinMode(suhuoff, OUTPUT);

    digitalWrite(RELAY_1, RELAY_OFF);
    digitalWrite(led_merah, LOW);
    digitalWrite(led_kuning, LOW);

    lcd.begin(16, 2);
    lcd.setCurcor(1,0);
    lcd.print("System Deteksi");
    lcd.print("Kebakaran");
    delay(5000);
    lcd.clear();

    lcd.setCurcor(2,0);
    lcd.print("Di Buat Oleh");
    lcd.setCurcor(2,1);
    lcd.print("Kelompok 11");
    delay(5000);
    lcd.clear();
}

// menyalakan LED hijau jika suhu di bawah 30 derajat celcius dan sensor aoi menyala
if (suhu <30 && api> 500 && asap < 599) {
    digitalWrite(led_hijau, HIGH);
    digitalWrite(led_kuning, LOW);
    digitalWrite(led_merah, LOW);
    digitalWrite(buzzer_pin, LOW);
    digitalWrite(relay_pin, HIGH);
    lcd.clear();
    lcd.setCurcor(2, 0);
    lcd.print("Suhu:");
    lcd.print(suhu);
    lcd.print("C ");
    lcd.setCurcor(1, 1);
    lcd.print("Sensor Api:");
    lcd.print(api);
    delay(1500);
}

//sensor api
int apiLevel = analogRead(apiSensorPin);
Serial.print("Api Level: ");
Serial.printIn(apiLevel);

if (apiLevel < 500) {
    digitalWrite(RELAY_1, RELAY_ON);
    digitalWrite(led_merah, HIGH);
    digitalWrite(led_hijau, LOW);
    lcd.clear();
    lcd.setCurcor(0, 0);
    lcd.print("Bahaya Api!");
    delay(2000);
}else {
    digitalWrite(RELAY_1, RELAY_OFF);
    digitalWrite(led_merah, LOW);
    digitalWrite(led_hijau, HIGH);

//dht11
//Baca humidity dan temperature
float h = dht.readHumidity();
float t = dht.readTemperature();
lcd.setCurcor(0, 0);
lcd.print(" Temp: ");
lcd.print(t);
lcd.print("C");
lcd.setCurcor(0, 1);
lcd.print("Api Level: ");
lcd.print(apiLevel);
delay(500);

}