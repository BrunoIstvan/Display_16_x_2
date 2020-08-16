#include <Arduino.h>
#include <LiquidCrystal.h>

void move_palavras(int total, char direcao);
void pisca();

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  
  lcd.setCursor(2, 0);
  lcd.print("LETICIA AMA");
  lcd.setCursor(1, 1);
  lcd.print("PAPAI E MAMAE ");
  delay(1000);

  move_palavras(3, 'R');
  move_palavras(6, 'L');
  move_palavras(3, 'R');

  delay(1000);

  for(int i = 0; i < 3; i++) {
    pisca();
  }

}

void move_palavras(int total, char direcao) {
  for(int i = 0; i < total; i++) {
    if(direcao == 'R') {
      lcd.scrollDisplayRight();  
    } else if(direcao == 'L') {
      lcd.scrollDisplayLeft();  
    }
    delay(50);
  }
  
}

void pisca() {
   lcd.noDisplay();
   delay(500);
   lcd.display();
   delay(500);
}
