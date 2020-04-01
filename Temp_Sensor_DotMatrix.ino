// For I2C       
#include <Wire.h> 
#include <Math.h>      
// Libraries for Matrix       
#include "Adafruit_LEDBackpack.h"       
#include "Adafruit_GFX.h"       
Adafruit_8x8matrix m1 = Adafruit_8x8matrix();      
Adafruit_8x8matrix m2 = Adafruit_8x8matrix();   
Adafruit_8x8matrix m3 = Adafruit_8x8matrix();   

void setup() {       
 Serial.begin(9600);       
 // Good idea to send data to both        
 // device and serial as it helps with       
 // troubleshooting.        
 Serial.println("8x8 LED Matrix Test");       
 // set the address       
 m1.begin(0x70);
 m2.begin(0x71);
 m3.begin(0x72);   
 
 initDisplays();
}       
       
void loop() {       
  double temp1 = readTempSensor();
  drawTemperature(temp1);
  delay(2500);
  clearAllScreens();
}

void initDisplays(){
  m1.clear();
  m2.clear();
  m3.clear();
  m1.setRotation(3);
  m2.setRotation(3);
  m3.setRotation(3);

  m1.writeDisplay();
  m2.writeDisplay();
  m3.writeDisplay();
}

void screenNumbers(){
  m1.clear();
  m2.clear();
  m3.clear();
  m1.print("1");
  m2.print("2");
  m3.print("3");
  
  m1.writeDisplay();
  m2.writeDisplay();
  m3.writeDisplay();
}

void clearAllScreens(){
  m1.clear();
  m2.clear();
  m3.clear();
  m1.writeDisplay();
  m2.writeDisplay();
  m3.writeDisplay();
}

void writePixel3Screen(int x, int y, int on){
  if (x < 8){
    m1.drawPixel(x, y, on);
    m1.writeDisplay();
  }else if(x > 7 && x < 16){
    m2.drawPixel(x - 8, y, on);
    m2.writeDisplay();
  }else{
    m3.drawPixel(x - 16, y, on);
    m3.writeDisplay();
  }
}

void drawTemperature(double temp) {
  String t1 = String(temp, 1);
  char d1 = t1[0];
  //Serial.print("d1: ");
  //Serial.print(d1);
  char d2 = t1[1];
  //Serial.print(", d2: ");
  //Serial.print(d2);
  char d3 = t1[3];
  //Serial.print(", d3: ");
  //Serial.print(d3);
  //Serial.println();
  draw3Digits(d1, d2, d3);
}

void draw3Digits(char d1, char d2, char d3){
  drawNumber(d1, 0, 0);
  drawNumber(d2, 6, 0);
  drawPoint(12,0);
  drawNumber(d3, 14, 0);
  drawCelsius(20, 0);
}

void drawNumber(char number, int startX, int startY){
  switch(number){
    case '0': draw0(startX, startY); break;
    case '1': draw1(startX, startY); break;
    case '2': draw2(startX, startY); break;
    case '3': draw3(startX, startY); break;
    case '4': draw4(startX, startY); break;
    case '5': draw5(startX, startY); break;
    case '6': draw6(startX, startY); break;
    case '7': draw7(startX, startY); break;
    case '8': draw8(startX, startY); break;
    case '9': draw9(startX, startY); break;
  }
}

double readTempSensor(){
  float val = analogRead(A7);
  //double temp = (val/1024.0)*500;
  
  
  
  double temp = val*5000/(1024*10);
  Serial.print("temp: ");
  Serial.print(temp);
  Serial.println();
  return temp;
}

//DRAWING NUMBERS

void draw1(int startX, int startY){
  writePixel3Screen(startX + 0, startY + 0, 0); // row 0
  writePixel3Screen(startX + 1, startY + 0, 0);
  writePixel3Screen(startX + 2, startY + 0, 1);
  writePixel3Screen(startX + 3, startY + 0, 0);
  writePixel3Screen(startX + 4, startY + 0, 0);

  writePixel3Screen(startX + 0, startY + 1, 0); // row 1
  writePixel3Screen(startX + 1, startY + 1, 1);
  writePixel3Screen(startX + 2, startY + 1, 1);
  writePixel3Screen(startX + 3, startY + 1, 0);
  writePixel3Screen(startX + 4, startY + 1, 0);

  writePixel3Screen(startX + 0, startY + 2, 0); // row 2
  writePixel3Screen(startX + 1, startY + 2, 0);
  writePixel3Screen(startX + 2, startY + 2, 1);
  writePixel3Screen(startX + 3, startY + 2, 0);
  writePixel3Screen(startX + 4, startY + 2, 0);

  writePixel3Screen(startX + 0, startY + 3, 0); // row 3
  writePixel3Screen(startX + 1, startY + 3, 0);
  writePixel3Screen(startX + 2, startY + 3, 1);
  writePixel3Screen(startX + 3, startY + 3, 0);
  writePixel3Screen(startX + 4, startY + 3, 0);

  writePixel3Screen(startX + 0, startY + 4, 0); // row 4
  writePixel3Screen(startX + 1, startY + 4, 0);
  writePixel3Screen(startX + 2, startY + 4, 1);
  writePixel3Screen(startX + 3, startY + 4, 0);
  writePixel3Screen(startX + 4, startY + 4, 0);

  writePixel3Screen(startX + 0, startY + 5, 0); // row 5
  writePixel3Screen(startX + 1, startY + 5, 0);
  writePixel3Screen(startX + 2, startY + 5, 1);
  writePixel3Screen(startX + 3, startY + 5, 0);
  writePixel3Screen(startX + 4, startY + 5, 0);

  writePixel3Screen(startX + 0, startY + 6, 0); // row 6
  writePixel3Screen(startX + 1, startY + 6, 1);
  writePixel3Screen(startX + 2, startY + 6, 1);
  writePixel3Screen(startX + 3, startY + 6, 1);
  writePixel3Screen(startX + 4, startY + 6, 0);
}

void draw2(int startX, int startY) {
  writePixel3Screen(startX + 0, startY + 0, 0); // row 0
  writePixel3Screen(startX + 1, startY + 0, 1);
  writePixel3Screen(startX + 2, startY + 0, 1);
  writePixel3Screen(startX + 3, startY + 0, 1);
  writePixel3Screen(startX + 4, startY + 0, 0);

  writePixel3Screen(startX + 0, startY + 1, 1); // row 1
  writePixel3Screen(startX + 1, startY + 1, 0);
  writePixel3Screen(startX + 2, startY + 1, 0);
  writePixel3Screen(startX + 3, startY + 1, 0);
  writePixel3Screen(startX + 4, startY + 1, 1);

  writePixel3Screen(startX + 0, startY + 2, 0); // row 2
  writePixel3Screen(startX + 1, startY + 2, 0);
  writePixel3Screen(startX + 2, startY + 2, 0);
  writePixel3Screen(startX + 3, startY + 2, 0);
  writePixel3Screen(startX + 4, startY + 2, 1);

  writePixel3Screen(startX + 0, startY + 3, 0); // row 3
  writePixel3Screen(startX + 1, startY + 3, 1);
  writePixel3Screen(startX + 2, startY + 3, 1);
  writePixel3Screen(startX + 3, startY + 3, 1);
  writePixel3Screen(startX + 4, startY + 3, 0);

  writePixel3Screen(startX + 0, startY + 4, 1); // row 4
  writePixel3Screen(startX + 1, startY + 4, 0);
  writePixel3Screen(startX + 2, startY + 4, 0);
  writePixel3Screen(startX + 3, startY + 4, 0);
  writePixel3Screen(startX + 4, startY + 4, 0);

  writePixel3Screen(startX + 0, startY + 5, 1); // row 5
  writePixel3Screen(startX + 1, startY + 5, 0);
  writePixel3Screen(startX + 2, startY + 5, 0);
  writePixel3Screen(startX + 3, startY + 5, 0);
  writePixel3Screen(startX + 4, startY + 5, 0);

  writePixel3Screen(startX + 0, startY + 6, 1); // row 6
  writePixel3Screen(startX + 1, startY + 6, 1);
  writePixel3Screen(startX + 2, startY + 6, 1);
  writePixel3Screen(startX + 3, startY + 6, 1);
  writePixel3Screen(startX + 4, startY + 6, 1);
}

void draw3(int startX, int startY) {
  writePixel3Screen(startX + 0, startY + 0, 1); // row 0
  writePixel3Screen(startX + 1, startY + 0, 1);
  writePixel3Screen(startX + 2, startY + 0, 1);
  writePixel3Screen(startX + 3, startY + 0, 1);
  writePixel3Screen(startX + 4, startY + 0, 1);

  writePixel3Screen(startX + 0, startY + 1, 0); // row 1
  writePixel3Screen(startX + 1, startY + 1, 0);
  writePixel3Screen(startX + 2, startY + 1, 0);
  writePixel3Screen(startX + 3, startY + 1, 0);
  writePixel3Screen(startX + 4, startY + 1, 1);

  writePixel3Screen(startX + 0, startY + 2, 0); // row 2
  writePixel3Screen(startX + 1, startY + 2, 0);
  writePixel3Screen(startX + 2, startY + 2, 0);
  writePixel3Screen(startX + 3, startY + 2, 1);
  writePixel3Screen(startX + 4, startY + 2, 0);

  writePixel3Screen(startX + 0, startY + 3, 0); // row 3
  writePixel3Screen(startX + 1, startY + 3, 0);
  writePixel3Screen(startX + 2, startY + 3, 1);
  writePixel3Screen(startX + 3, startY + 3, 1);
  writePixel3Screen(startX + 4, startY + 3, 0);

  writePixel3Screen(startX + 0, startY + 4, 1); // row 4
  writePixel3Screen(startX + 1, startY + 4, 0);
  writePixel3Screen(startX + 2, startY + 4, 0);
  writePixel3Screen(startX + 3, startY + 4, 0);
  writePixel3Screen(startX + 4, startY + 4, 1);

  writePixel3Screen(startX + 0, startY + 5, 1); // row 5
  writePixel3Screen(startX + 1, startY + 5, 0);
  writePixel3Screen(startX + 2, startY + 5, 0);
  writePixel3Screen(startX + 3, startY + 5, 0);
  writePixel3Screen(startX + 4, startY + 5, 1);

  writePixel3Screen(startX + 0, startY + 6, 0); // row 6
  writePixel3Screen(startX + 1, startY + 6, 1);
  writePixel3Screen(startX + 2, startY + 6, 1);
  writePixel3Screen(startX + 3, startY + 6, 1);
  writePixel3Screen(startX + 4, startY + 6, 0);
}

void draw4(int startX, int startY) {
  writePixel3Screen(startX + 0, startY + 0, 0); // row 0
  writePixel3Screen(startX + 1, startY + 0, 0);
  writePixel3Screen(startX + 2, startY + 0, 0);
  writePixel3Screen(startX + 3, startY + 0, 1);
  writePixel3Screen(startX + 4, startY + 0, 0);

  writePixel3Screen(startX + 0, startY + 1, 0); // row 1
  writePixel3Screen(startX + 1, startY + 1, 0);
  writePixel3Screen(startX + 2, startY + 1, 1);
  writePixel3Screen(startX + 3, startY + 1, 1);
  writePixel3Screen(startX + 4, startY + 1, 0);

  writePixel3Screen(startX + 0, startY + 2, 0); // row 2
  writePixel3Screen(startX + 1, startY + 2, 1);
  writePixel3Screen(startX + 2, startY + 2, 0);
  writePixel3Screen(startX + 3, startY + 2, 1);
  writePixel3Screen(startX + 4, startY + 2, 0);

  writePixel3Screen(startX + 0, startY + 3, 1); // row 3
  writePixel3Screen(startX + 1, startY + 3, 0);
  writePixel3Screen(startX + 2, startY + 3, 0);
  writePixel3Screen(startX + 3, startY + 3, 1);
  writePixel3Screen(startX + 4, startY + 3, 0);

  writePixel3Screen(startX + 0, startY + 4, 1); // row 4
  writePixel3Screen(startX + 1, startY + 4, 1);
  writePixel3Screen(startX + 2, startY + 4, 1);
  writePixel3Screen(startX + 3, startY + 4, 1);
  writePixel3Screen(startX + 4, startY + 4, 1);

  writePixel3Screen(startX + 0, startY + 5, 0); // row 5
  writePixel3Screen(startX + 1, startY + 5, 0);
  writePixel3Screen(startX + 2, startY + 5, 0);
  writePixel3Screen(startX + 3, startY + 5, 1);
  writePixel3Screen(startX + 4, startY + 5, 0);

  writePixel3Screen(startX + 0, startY + 6, 0); // row 6
  writePixel3Screen(startX + 1, startY + 6, 0);
  writePixel3Screen(startX + 2, startY + 6, 0);
  writePixel3Screen(startX + 3, startY + 6, 1);
  writePixel3Screen(startX + 4, startY + 6, 0);
}

void draw5(int startX, int startY) {
  writePixel3Screen(startX + 0, startY + 0, 1); // row 0
  writePixel3Screen(startX + 1, startY + 0, 1);
  writePixel3Screen(startX + 2, startY + 0, 1);
  writePixel3Screen(startX + 3, startY + 0, 1);
  writePixel3Screen(startX + 4, startY + 0, 1);

  writePixel3Screen(startX + 0, startY + 1, 1); // row 1
  writePixel3Screen(startX + 1, startY + 1, 0);
  writePixel3Screen(startX + 2, startY + 1, 0);
  writePixel3Screen(startX + 3, startY + 1, 0);
  writePixel3Screen(startX + 4, startY + 1, 0);

  writePixel3Screen(startX + 0, startY + 2, 1); // row 2
  writePixel3Screen(startX + 1, startY + 2, 1);
  writePixel3Screen(startX + 2, startY + 2, 1);
  writePixel3Screen(startX + 3, startY + 2, 1);
  writePixel3Screen(startX + 4, startY + 2, 0);

  writePixel3Screen(startX + 0, startY + 3, 0); // row 3
  writePixel3Screen(startX + 1, startY + 3, 0);
  writePixel3Screen(startX + 2, startY + 3, 0);
  writePixel3Screen(startX + 3, startY + 3, 0);
  writePixel3Screen(startX + 4, startY + 3, 1);

  writePixel3Screen(startX + 0, startY + 4, 0); // row 4
  writePixel3Screen(startX + 1, startY + 4, 0);
  writePixel3Screen(startX + 2, startY + 4, 0);
  writePixel3Screen(startX + 3, startY + 4, 0);
  writePixel3Screen(startX + 4, startY + 4, 1);

  writePixel3Screen(startX + 0, startY + 5, 1); // row 5
  writePixel3Screen(startX + 1, startY + 5, 0);
  writePixel3Screen(startX + 2, startY + 5, 0);
  writePixel3Screen(startX + 3, startY + 5, 0);
  writePixel3Screen(startX + 4, startY + 5, 1);

  writePixel3Screen(startX + 0, startY + 6, 0); // row 6
  writePixel3Screen(startX + 1, startY + 6, 1);
  writePixel3Screen(startX + 2, startY + 6, 1);
  writePixel3Screen(startX + 3, startY + 6, 1);
  writePixel3Screen(startX + 4, startY + 6, 0);
}

void draw6(int startX, int startY) {
  writePixel3Screen(startX + 0, startY + 0, 0); // row 0
  writePixel3Screen(startX + 1, startY + 0, 0);
  writePixel3Screen(startX + 2, startY + 0, 1);
  writePixel3Screen(startX + 3, startY + 0, 1);
  writePixel3Screen(startX + 4, startY + 0, 1);

  writePixel3Screen(startX + 0, startY + 1, 0); // row 1
  writePixel3Screen(startX + 1, startY + 1, 1);
  writePixel3Screen(startX + 2, startY + 1, 0);
  writePixel3Screen(startX + 3, startY + 1, 0);
  writePixel3Screen(startX + 4, startY + 1, 0);

  writePixel3Screen(startX + 0, startY + 2, 1); // row 2
  writePixel3Screen(startX + 1, startY + 2, 0);
  writePixel3Screen(startX + 2, startY + 2, 0);
  writePixel3Screen(startX + 3, startY + 2, 0);
  writePixel3Screen(startX + 4, startY + 2, 0);

  writePixel3Screen(startX + 0, startY + 3, 1); // row 3
  writePixel3Screen(startX + 1, startY + 3, 1);
  writePixel3Screen(startX + 2, startY + 3, 1);
  writePixel3Screen(startX + 3, startY + 3, 1);
  writePixel3Screen(startX + 4, startY + 3, 0);

  writePixel3Screen(startX + 0, startY + 4, 1); // row 4
  writePixel3Screen(startX + 1, startY + 4, 0);
  writePixel3Screen(startX + 2, startY + 4, 0);
  writePixel3Screen(startX + 3, startY + 4, 0);
  writePixel3Screen(startX + 4, startY + 4, 1);

  writePixel3Screen(startX + 0, startY + 5, 1); // row 5
  writePixel3Screen(startX + 1, startY + 5, 0);
  writePixel3Screen(startX + 2, startY + 5, 0);
  writePixel3Screen(startX + 3, startY + 5, 0);
  writePixel3Screen(startX + 4, startY + 5, 1);

  writePixel3Screen(startX + 0, startY + 6, 0); // row 6
  writePixel3Screen(startX + 1, startY + 6, 1);
  writePixel3Screen(startX + 2, startY + 6, 1);
  writePixel3Screen(startX + 3, startY + 6, 1);
  writePixel3Screen(startX + 4, startY + 6, 0);
}

void draw7(int startX, int startY) {
  writePixel3Screen(startX + 0, startY + 0, 1); // row 0
  writePixel3Screen(startX + 1, startY + 0, 1);
  writePixel3Screen(startX + 2, startY + 0, 1);
  writePixel3Screen(startX + 3, startY + 0, 1);
  writePixel3Screen(startX + 4, startY + 0, 1);

  writePixel3Screen(startX + 0, startY + 1, 0); // row 1
  writePixel3Screen(startX + 1, startY + 1, 0);
  writePixel3Screen(startX + 2, startY + 1, 0);
  writePixel3Screen(startX + 3, startY + 1, 0);
  writePixel3Screen(startX + 4, startY + 1, 1);

  writePixel3Screen(startX + 0, startY + 2, 0); // row 2
  writePixel3Screen(startX + 1, startY + 2, 0);
  writePixel3Screen(startX + 2, startY + 2, 0);
  writePixel3Screen(startX + 3, startY + 2, 0);
  writePixel3Screen(startX + 4, startY + 2, 1);

  writePixel3Screen(startX + 0, startY + 3, 0); // row 3
  writePixel3Screen(startX + 1, startY + 3, 0);
  writePixel3Screen(startX + 2, startY + 3, 0);
  writePixel3Screen(startX + 3, startY + 3, 1);
  writePixel3Screen(startX + 4, startY + 3, 0);

  writePixel3Screen(startX + 0, startY + 4, 0); // row 4
  writePixel3Screen(startX + 1, startY + 4, 0);
  writePixel3Screen(startX + 2, startY + 4, 1);
  writePixel3Screen(startX + 3, startY + 4, 0);
  writePixel3Screen(startX + 4, startY + 4, 0);

  writePixel3Screen(startX + 0, startY + 5, 0); // row 5
  writePixel3Screen(startX + 1, startY + 5, 1);
  writePixel3Screen(startX + 2, startY + 5, 0);
  writePixel3Screen(startX + 3, startY + 5, 0);
  writePixel3Screen(startX + 4, startY + 5, 0);

  writePixel3Screen(startX + 0, startY + 6, 1); // row 6
  writePixel3Screen(startX + 1, startY + 6, 0);
  writePixel3Screen(startX + 2, startY + 6, 0);
  writePixel3Screen(startX + 3, startY + 6, 0);
  writePixel3Screen(startX + 4, startY + 6, 0);
}

void draw8(int startX, int startY) {
  writePixel3Screen(startX + 0, startY + 0, 0); // row 0
  writePixel3Screen(startX + 1, startY + 0, 1);
  writePixel3Screen(startX + 2, startY + 0, 1);
  writePixel3Screen(startX + 3, startY + 0, 1);
  writePixel3Screen(startX + 4, startY + 0, 0);

  writePixel3Screen(startX + 0, startY + 1, 1); // row 1
  writePixel3Screen(startX + 1, startY + 1, 0);
  writePixel3Screen(startX + 2, startY + 1, 0);
  writePixel3Screen(startX + 3, startY + 1, 0);
  writePixel3Screen(startX + 4, startY + 1, 1);

  writePixel3Screen(startX + 0, startY + 2, 1); // row 2
  writePixel3Screen(startX + 1, startY + 2, 0);
  writePixel3Screen(startX + 2, startY + 2, 0);
  writePixel3Screen(startX + 3, startY + 2, 0);
  writePixel3Screen(startX + 4, startY + 2, 1);

  writePixel3Screen(startX + 0, startY + 3, 0); // row 3
  writePixel3Screen(startX + 1, startY + 3, 1);
  writePixel3Screen(startX + 2, startY + 3, 1);
  writePixel3Screen(startX + 3, startY + 3, 1);
  writePixel3Screen(startX + 4, startY + 3, 0);

  writePixel3Screen(startX + 0, startY + 4, 1); // row 4
  writePixel3Screen(startX + 1, startY + 4, 0);
  writePixel3Screen(startX + 2, startY + 4, 0);
  writePixel3Screen(startX + 3, startY + 4, 0);
  writePixel3Screen(startX + 4, startY + 4, 1);

  writePixel3Screen(startX + 0, startY + 5, 1); // row 5
  writePixel3Screen(startX + 1, startY + 5, 0);
  writePixel3Screen(startX + 2, startY + 5, 0);
  writePixel3Screen(startX + 3, startY + 5, 0);
  writePixel3Screen(startX + 4, startY + 5, 1);

  writePixel3Screen(startX + 0, startY + 6, 0); // row 6
  writePixel3Screen(startX + 1, startY + 6, 1);
  writePixel3Screen(startX + 2, startY + 6, 1);
  writePixel3Screen(startX + 3, startY + 6, 1);
  writePixel3Screen(startX + 4, startY + 6, 0);
}

void draw9(int startX, int startY) {
  writePixel3Screen(startX + 0, startY + 0, 0); // row 0
  writePixel3Screen(startX + 1, startY + 0, 1);
  writePixel3Screen(startX + 2, startY + 0, 1);
  writePixel3Screen(startX + 3, startY + 0, 1);
  writePixel3Screen(startX + 4, startY + 0, 0);

  writePixel3Screen(startX + 0, startY + 1, 1); // row 1
  writePixel3Screen(startX + 1, startY + 1, 0);
  writePixel3Screen(startX + 2, startY + 1, 0);
  writePixel3Screen(startX + 3, startY + 1, 0);
  writePixel3Screen(startX + 4, startY + 1, 1);

  writePixel3Screen(startX + 0, startY + 2, 1); // row 2
  writePixel3Screen(startX + 1, startY + 2, 0);
  writePixel3Screen(startX + 2, startY + 2, 0);
  writePixel3Screen(startX + 3, startY + 2, 0);
  writePixel3Screen(startX + 4, startY + 2, 1);

  writePixel3Screen(startX + 0, startY + 3, 0); // row 3
  writePixel3Screen(startX + 1, startY + 3, 1);
  writePixel3Screen(startX + 2, startY + 3, 1);
  writePixel3Screen(startX + 3, startY + 3, 1);
  writePixel3Screen(startX + 4, startY + 3, 1);

  writePixel3Screen(startX + 0, startY + 4, 0); // row 4
  writePixel3Screen(startX + 1, startY + 4, 0);
  writePixel3Screen(startX + 2, startY + 4, 0);
  writePixel3Screen(startX + 3, startY + 4, 0);
  writePixel3Screen(startX + 4, startY + 4, 1);

  writePixel3Screen(startX + 0, startY + 5, 0); // row 5
  writePixel3Screen(startX + 1, startY + 5, 0);
  writePixel3Screen(startX + 2, startY + 5, 0);
  writePixel3Screen(startX + 3, startY + 5, 1);
  writePixel3Screen(startX + 4, startY + 5, 0);

  writePixel3Screen(startX + 0, startY + 6, 1); // row 6
  writePixel3Screen(startX + 1, startY + 6, 1);
  writePixel3Screen(startX + 2, startY + 6, 1);
  writePixel3Screen(startX + 3, startY + 6, 0);
  writePixel3Screen(startX + 4, startY + 6, 0);
}

void draw0(int startX, int startY) {
  writePixel3Screen(startX + 0, startY + 0, 0); // row 0
  writePixel3Screen(startX + 1, startY + 0, 1);
  writePixel3Screen(startX + 2, startY + 0, 1);
  writePixel3Screen(startX + 3, startY + 0, 1);
  writePixel3Screen(startX + 4, startY + 0, 0);

  writePixel3Screen(startX + 0, startY + 1, 1); // row 1
  writePixel3Screen(startX + 1, startY + 1, 0);
  writePixel3Screen(startX + 2, startY + 1, 0);
  writePixel3Screen(startX + 3, startY + 1, 0);
  writePixel3Screen(startX + 4, startY + 1, 1);

  writePixel3Screen(startX + 0, startY + 2, 1); // row 2
  writePixel3Screen(startX + 1, startY + 2, 0);
  writePixel3Screen(startX + 2, startY + 2, 0);
  writePixel3Screen(startX + 3, startY + 2, 1);
  writePixel3Screen(startX + 4, startY + 2, 1);

  writePixel3Screen(startX + 0, startY + 3, 1); // row 3
  writePixel3Screen(startX + 1, startY + 3, 0);
  writePixel3Screen(startX + 2, startY + 3, 1);
  writePixel3Screen(startX + 3, startY + 3, 0);
  writePixel3Screen(startX + 4, startY + 3, 1);

  writePixel3Screen(startX + 0, startY + 4, 1); // row 4
  writePixel3Screen(startX + 1, startY + 4, 1);
  writePixel3Screen(startX + 2, startY + 4, 0);
  writePixel3Screen(startX + 3, startY + 4, 0);
  writePixel3Screen(startX + 4, startY + 4, 1);

  writePixel3Screen(startX + 0, startY + 5, 1); // row 5
  writePixel3Screen(startX + 1, startY + 5, 0);
  writePixel3Screen(startX + 2, startY + 5, 0);
  writePixel3Screen(startX + 3, startY + 5, 0);
  writePixel3Screen(startX + 4, startY + 5, 1);

  writePixel3Screen(startX + 0, startY + 6, 0); // row 6
  writePixel3Screen(startX + 1, startY + 6, 1);
  writePixel3Screen(startX + 2, startY + 6, 1);
  writePixel3Screen(startX + 3, startY + 6, 1);
  writePixel3Screen(startX + 4, startY + 6, 0);
}

void drawPoint(int startX, int startY) {
  writePixel3Screen(startX + 0, startY + 6, 1);
}

void drawCelsius(int startX, int startY) {
  writePixel3Screen(startX + 0, startY + 0, 0); // row 0
  writePixel3Screen(startX + 1, startY + 0, 1);
  writePixel3Screen(startX + 2, startY + 0, 1);
  writePixel3Screen(startX + 3, startY + 0, 0);

  writePixel3Screen(startX + 0, startY + 1, 1); // row 1
  writePixel3Screen(startX + 1, startY + 1, 0);
  writePixel3Screen(startX + 2, startY + 1, 0);
  writePixel3Screen(startX + 3, startY + 1, 1);

  writePixel3Screen(startX + 0, startY + 2, 1); // row 2
  writePixel3Screen(startX + 1, startY + 2, 0);
  writePixel3Screen(startX + 2, startY + 2, 0);
  writePixel3Screen(startX + 3, startY + 2, 1);

  writePixel3Screen(startX + 0, startY + 3, 0); // row 3
  writePixel3Screen(startX + 1, startY + 3, 1);
  writePixel3Screen(startX + 2, startY + 3, 1);
  writePixel3Screen(startX + 3, startY + 3, 0);
}
