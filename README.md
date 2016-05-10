# termoLCD
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

void setup()
{
  /* Инициализируем дисплей: 2 строки по 16 символов */
  lcd.begin(16, 2);
  /* Выводим на дисплей традиционную фразу (: */
  lcd.setCursor(0, 0);
  lcd.print("t1:");

  lcd.setCursor(6, 0);
  lcd.print("t2:");

  lcd.setCursor(12, 0);
  lcd.print("t3:");

}

void loop()
{
  /* Устанавливаем курсор в 1 столбец 2й строки. Нумерация идёт с нуля,
     первым аргументом идёт номер столбца.
  */

  sensor1 = analogRead(sensor1Pin);
  lcd.setCursor(0, 1);
  lcd.print("      ");
  /* Выводим на дисплей число секунд, прошедших с момента старта Arduino */
  lcd.setCursor(0, 1);
  sensor1 = map(sensor1, 191, 1023, 28, 150);
  lcd.print(sensor1);

  sensor2 = analogRead(sensor2Pin);
  lcd.setCursor(6, 1);
  lcd.print("      ");
  /* Выводим на дисплей число секунд, прошедших с момента старта Arduino */
  lcd.setCursor(6, 1);
  sensor2 = map(sensor2, 199, 1023, 28, 150);
  lcd.print(sensor2);

  sensor3 = analogRead(sensor3Pin);
  lcd.setCursor(12, 1);
  lcd.print("      ");
  /* Выводим на дисплей число секунд, прошедших с момента старта Arduino */
  lcd.setCursor(12, 1);
  sensor3 = map(sensor3, 271, 1023, 28, 150);
  lcd.print(sensor3);
  delay(1000);
}
