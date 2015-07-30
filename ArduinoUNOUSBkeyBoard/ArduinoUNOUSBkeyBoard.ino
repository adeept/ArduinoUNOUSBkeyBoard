/***********************************************************
File name:   ArduinoUNOUSBKeyBoard.ino
Description:  We use Arduino UNO board to do a computer keyboard 
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2015/07/20 
***********************************************************/
#include "UsbKeyboard.h"
int KEYPIN1 = 8;          //Set the digital 8 to button interface 
void setup()
{
  TIMSK0 &= !(1 << TOIE0);         //disable timer 0 overflow interrupt (used for millis)
  pinMode(KEYPIN1, INPUT_PULLUP);  //Set digital 2 port mode, the INPUT_PULLUP for the input
}
void loop()
{
  UsbKeyboard.update();
  if(digitalRead(KEYPIN1) == HIGH){//Detection button interface to HIGH
    delayMs(10);//Delay 10ms for the elimination of key leading-edge jitter
    if(digitalRead(KEYPIN1) == LOW){//Confirm button is pressed
      UsbKeyboard.sendKeyStroke(KEY_Y);//send "y"
      UsbKeyboard.sendKeyStroke(KEY_O);//send "o"
      UsbKeyboard.sendKeyStroke(KEY_U);//send "u"
      UsbKeyboard.sendKeyStroke(KEY_SPACE);//send " "
      UsbKeyboard.sendKeyStroke(KEY_D);//send "d"
      UsbKeyboard.sendKeyStroke(KEY_O);//send "o"
      UsbKeyboard.sendKeyStroke(KEY_SPACE);//send " "
      UsbKeyboard.sendKeyStroke(KEY_V);//send "v"
      UsbKeyboard.sendKeyStroke(KEY_E);//send "e"
      UsbKeyboard.sendKeyStroke(KEY_R);//send "r"
      UsbKeyboard.sendKeyStroke(KEY_Y);//send "y"
      UsbKeyboard.sendKeyStroke(KEY_SPACE);//send " "
      UsbKeyboard.sendKeyStroke(KEY_W);//send "w"
      UsbKeyboard.sendKeyStroke(KEY_E);//send "e"
      UsbKeyboard.sendKeyStroke(KEY_L);//send "l"
      UsbKeyboard.sendKeyStroke(KEY_L);//send "l"
      UsbKeyboard.sendKeyStroke(KEY_ENTER);//send  enter
    }
  }
}
void delayMs(unsigned int ms) {//delay time
  for (int i = 0; i < ms; i++) {
    delayMicroseconds(1000);
  }
}
