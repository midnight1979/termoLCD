/* Подключаем библиотеку для работы с LCD */
#include <LiquidCrystal.h>

/* Создаём объект LCD-дисплея, используя конструктор класса LiquidCrystal
  с 6ю аргументами. Библиотека по количеству аргументов сама определит,
  что нужно использовать 4-битный интерфейс.
  Указываем, к каким пинам Arduino подключены выводы дисплея:
    RS, E, DB4, DB5, DB6, DB7
*/
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int sensor1Pin = A0;
int sensor1 = 0;

int sensor2Pin = A1;
int sensor2 = 0;

int sensor3Pin = A2;
int sensor3 = 0;

byte degr[8] = {
  0b00000110, 0b00001001, 0b00001001, 0b00000110, 0b00000000

};

void setup()
{

  Serial.begin(9600);

  /* Инициализируем дисплей: 2 строки по 16 символов */
  lcd.begin(16, 2);
  lcd.createChar(0, degr);

  /* Выводим на дисплей традиционную фразу (: */
  lcd.setCursor(0, 0);
  lcd.print("T1");
  lcd.write(byte(0));
  lcd.print("C");

  lcd.setCursor(6, 0);
  lcd.print("T2");
  lcd.write(byte(0));
  lcd.print("C");

  lcd.setCursor(12, 0);
  lcd.print("T3");
  lcd.write(byte(0));
  lcd.print("C");


  // play a note on pin 8 for 500 ms:
  tone(8, 500, 300);
  delay(100);
  tone(8, 600, 300);
  delay(100);
  tone(8, 800, 300);
  delay(100);
  tone(8, 1000, 300);
  delay(300);
  noTone(8);

}

void loop()
{

  // Читаем значение первого терморезистора и выводим на LCD
  sensor1 = analogRead(sensor1Pin);
  lcd.setCursor(0, 1);
  lcd.print("      ");
  /* Выводим на дисплей число секунд, прошедших с момента старта Arduino */
  lcd.setCursor(0, 1);
  sensor1 = map(sensor1, 191, 1023, 28, 150);
  lcd.print(sensor1);
  lcd.write(byte(0));

  // Читаем значение второго терморезистора и выводим на LCD
  sensor2 = analogRead(sensor2Pin);
  lcd.setCursor(6, 1);
  lcd.print("      ");
  /* Выводим на дисплей число секунд, прошедших с момента старта Arduino */
  lcd.setCursor(6, 1);
  sensor2 = map(sensor2, 199, 1023, 28, 150);
  lcd.print(sensor2);
  lcd.write(byte(0));

  // Читаем значение третьего терморезистора и выводим на LCD
  sensor3 = analogRead(sensor3Pin);
  lcd.setCursor(12, 1);
  lcd.print("      ");
  /* Выводим на дисплей число секунд, прошедших с момента старта Arduino */
  lcd.setCursor(12, 1);
  sensor3 = map(sensor3, 282, 1023, 28, 150);
  lcd.print(sensor3);
  lcd.write(byte(0));
  delay(500);
}
