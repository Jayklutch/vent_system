#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); // setting LCD address to 0x27 (16 x 2 display)
int hangtime=500;
int rtemp =99;                   //roof temp
int htemp =00;                   //house temp
int fan =1;                      //fan speed
int motor =3;                    //motor out pin
int rs =5;                       //roof sensor is pin 5
int hs =7;                       //house sensor is pin 7
int up =2;                       //up button is pin 2
int down =4;                     //down button is pin 4

void setup(){
  lcd.init();                    // initialize the lcd
  lcd.backlight();               //and turn the backlight on (possibly not needed)
pinMode(23, INPUT);
pinMode(24,INPUT);
  pinMode(motor, OUTPUT);       //we want to CONTROL the motor
  pinMode(rs, INPUT);           //we want the roof and house sensors
  pinMode(hs, INPUT);           //to GIVE US information
  pinMode(up, INPUT);           // make pin a button input
  digitalWrite(up, HIGH);       //pull internal resistor high
  pinMode(down, INPUT);         //ditto
  digitalWrite(down, HIGH);      //ditto
  lcd.setCursor(0,0);           //set the cursor at the first digit
  lcd.print("  JAYS DVS SYS");           //write some text to the screen
  lcd.setCursor(0,1);
  lcd.print(" Loading.......");
  delay(4000);
  lcd.setCursor(0,0);           //set the cursor at the first digit
  lcd.print(" AND LUCY IS ");           //write some text to the screen
  lcd.setCursor(0,1);
  lcd.print("  AMAZING!!");
  delay(4000);
}

void loop(){
rtemp = (0.9 * analogRead(23) * 100.0) / 1024;
htemp = (0.8 * analogRead(24) * 100.0) / 1024;
hangtime=1500;
  lcd.setCursor(0,0);           //set the cursor at the first digit
  lcd.print("Roof:");           //write some text to the screen
  lcd.print(rtemp);             //display the varible known as 'rtemp'
  lcd.print("  Fan: ");
  lcd.print(fan);
  lcd.setCursor(0,1);
  lcd.print(" Living Room: ");
  lcd.print(htemp);

  if(digitalRead(up)==LOW)
  {
  hangtime=300;
  if (fan<5)
   {
    fan++;}
  }

if (digitalRead(down)==LOW){
hangtime=300;
  if (fan>0){
  fan--;}
  }
analogWrite(motor,fan*51);
delay(hangtime);
}

