#include <LiquidCrystal.h>
#define api_pin A0 //pin sensor api dihubungkan ke pin analog A0
#define suhu_pin A1 // pin sensor suhu dihubungkan ke pin analog A1
#define gas_pin A2
#define buzzer_pin 9 // pin buzzer dihubungkan ke pin digital 9
#define led_merah 2 // pin LED merah dihubungkan ke pin digital 2
#define led_kuning 3 // pin LED kuning dihubungkan ke pin digital 3
#define led_hijau 4 // pin LED hijau dihubungkan ke pin digital 4
#define LiquidCrystal lcd(16, 12, 11, 5, 4, 3, 2,);

void setup(){
    Serial.begin(9600); // membuka serial monitor dengan baud rate 9600
    pinMode(api_pin, INPUT); // mengatur pin sensor api sebagai input
    pinMode(suhu_pin, INPUT); // mengatur pin sensor suhu sebagai input
    pinMode(gas_pin, INPUT); 
    pinMode(buzzer_pin, OUTPUT); // mengatur pin buzzer sebagai output
    pinMode(led_merah, OUTPUT); // mengatur pin LED merah sebagai output
    pinMode(led_kuning, OUTPUT); // mengatur pin LED kuning sebagai output
    pinMode(led_hijau, OUTPUT); // mengatur pin LED hijau sebagai output
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
}

void loop(){
    // membaca data suhu dari sensor suhu
    int suhu = analogRead(suhu_pin);

    // membaca data dari sensor api
    int api = analogRead(api_pin);

    int asap = analogRead(asap_pin);

    Serial.print("Suhu: ");
    Serial.print(suhu);
    Serial.print(", Sensor Api: ");
    Serial.print(api);

    Serial.print(", Sensor Gas: ");
    Sensor.print(gas);
    Sensor.print("Suhu: ");
    Sensor.print(suhu);
    Sensor.print(", Sensor Api: ");
    Sensor.print(api);

    //menyalakann LED hijau jika suhu di bawah 30 derajat Celcius dan Sensor api tidak mendeteksi asap
    if (suhu < 30 && api < 500 && gas < 800){
        digitalWrite(led_hijau, HIGH);
        digitalWrite(led_kuning, LOW);
        digitalWrite(led_merah, LOW);
        digitalWrite(buzzer_pin, LOW);
        lcd.clear();
    }
    // menyalakan LED kuning jika suhu di atas 20 derajat Celcius dan sensor api mendeteksi asap
    else if (suhu >= 20 && suhu < 30 && api > 500 gas >= 800){
        digitalWrite(led_kuning, HIGH);
        digitalWrite(led_hijau, LOW);
        digitalWrite(led_merah, LOW);
        digitalWrite(buzzer_pin, LOW);
        lcd.setCursor(0, 0);
        lcd.print("Peringatan:");
        lcd.setCursor(0, 1);
        lcd.print("Kemungkinan Kebakaran!");
    }
    // menyalakan LED merah dan buzzer jika suhu di atas 30 derajat Celcius 
    else if (suhu >= 30 || api > 500){
        digitalWrite(led_merah, HIGH);
        digitalWrite(led_kuning, LOW);
        digitalWrite(led_hijau, LOW);
        digitalWrite(buzzer_pin, HIGH);
        lcd.setCursor(0, 0);
        lcd.print("Peringatan:");
        lcd.setCursor(0, 1);
        lcd.print("Terjadi Kebakaran!");
    }
    //menunggu 1 detik sebelum membaca data sensor kembali
delay(1000);
}