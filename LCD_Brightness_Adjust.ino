#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);        // select the pins used on the LCD panel

int lcd_key     = 0;
int adc_key_in  = 0;
int bright = 255;

#define btnUP     1
#define btnDOWN   2
#define btnNONE   5

void setup(){
    lcd.begin(16, 2);
    
}

int readButtons()
{
  adc_key_in = analogRead(0);       // read the value from the sensor
  lcd.setCursor(12,1);              //Display analogue value on Pin A0
  lcd.print(adc_key_in);
  lcd.print("   ");
  if (adc_key_in < 250 && adc_key_in > 144 )  return btnUP;
  else if (adc_key_in < 450 && adc_key_in > 251)  return btnDOWN;
  else return btnNONE;
}
void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 0);
  lcd.print("Brightness:");
  lcd.setCursor(0,1);
  lcd.print("A0 Value:");
  analogWrite(10, bright);
  lcd.setCursor(12,0);
  lcd.print(bright);

  lcd_key = readButtons();

  switch (lcd_key){

    case btnDOWN:{        //Down button is pressed to dim screen
      if (bright > 0)     //Sets minimum brightness
      {
        bright--;
      }  
      break;
    }
    case btnUP:{        //Up button is pressed to brighten screen
      if (bright < 255) //Sets maximum brightness
      {
        bright++;
      }
      break;
    }
    case btnNONE:{
      break;
    }
  }
}
