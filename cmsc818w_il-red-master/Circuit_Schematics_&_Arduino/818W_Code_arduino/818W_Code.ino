#include <Wire.h>
#include "Adafruit_SI1145.h"
Adafruit_SI1145 uv = Adafruit_SI1145();

int ledPin_blue = 13;     // The LED is connected on pin 13
int ledPin_green = 12;     // The LED is connected on pin 13
int ledPin_red = 8;     // The LED is connected on pin 13
int ledPin_ir = 7;     // The LED is connected on pin 13
int data_points = 20;

int rgb[20];     // variable to stores data
int ir[20];     // variable to stores data
int ultra[20];     // variable to stores data


void setup() {
  // put your setup code here, to run once:

 // make the LED pin (pin 13) an output pin
  pinMode(ledPin_blue, OUTPUT);
  pinMode(ledPin_green, OUTPUT);
  pinMode(ledPin_red, OUTPUT);
  pinMode(ledPin_ir, OUTPUT);

  
  Serial.begin(9600);
  
  uv.begin();
  
//  Serial.println("Adafruit SI1145 test");
//  if (! uv.begin()) 
//  {
//    Serial.println("Didn't find Si1145");
//    while (1);
//  }
//  Serial.println("OK!");

    // put your main code here, to run repeatedly:============>>>
  delay(3000);

  digitalWrite(ledPin_blue, LOW);
  digitalWrite(ledPin_green, LOW);
  digitalWrite(ledPin_red, LOW);
  digitalWrite(ledPin_ir, LOW);
  delay(3000);
  

// GREEN HERE =====================>>>>>

  digitalWrite(ledPin_green, HIGH);
  delay(3000);
  for(int i = 0; i<data_points; i++)
  {
    rgb[i]= uv.readVisible();
    ir[i] = uv.readIR();
    ultra[i] =  uv.readUV();
    delay(500);
  }
  delay(3000);
  digitalWrite(ledPin_green, LOW);

  for(int i = 0; i<data_points; i++)
  {
    Serial.println("Green");
    delay(500);

    Serial.println("rgb");
    Serial.println(rgb[i]);
    
    Serial.println("IR");
    Serial.println(ir[i]);
  
    Serial.println("UV");
    Serial.println(ultra[i]);
//    delay(500);

  }

//  Serial.println("End_green");


// BLUE HERE =====================>>>>>

  digitalWrite(ledPin_blue, HIGH);
  delay(3000);
  for(int i = 0; i<data_points; i++)
  {
    rgb[i]= uv.readVisible();
    ir[i] = uv.readIR();
    ultra[i] =  uv.readUV();
    delay(500);
  }
  delay(3000);
  digitalWrite(ledPin_blue, LOW);

  for(int i = 0; i<data_points; i++)
  {
    Serial.println("Blue");
    delay(500);

    Serial.println("rgb");
    Serial.println(rgb[i]);
    
    Serial.println("IR");
    Serial.println(ir[i]);
  
    Serial.println("UV");
    Serial.println(ultra[i]);
//    delay(500);

  }
  
//  Serial.println("End_blue");

// RED HERE =====================>>>>>

  digitalWrite(ledPin_red, HIGH);
  delay(3000);
  for(int i = 0; i<data_points; i++)
  {
    rgb[i]= uv.readVisible();
    ir[i] = uv.readIR();
    ultra[i] =  uv.readUV();
    delay(500);
  }
  delay(3000);
  digitalWrite(ledPin_red, LOW);

  for(int i = 0; i<data_points; i++)
  {
    Serial.println("Red");
    delay(500);

    Serial.println("rgb");
    Serial.println(rgb[i]);
    
    Serial.println("IR");
    Serial.println(ir[i]);
  
    Serial.println("UV");
    Serial.println(ultra[i]);
//    delay(500);

  }

//  Serial.println("End_red");

// IR HERE =====================>>>>>

  digitalWrite(ledPin_ir, HIGH);
  delay(3000);
  for(int i = 0; i<data_points; i++)
  {
    rgb[i]= uv.readVisible();
    ir[i] = uv.readIR();
    ultra[i] =  uv.readUV();
    delay(500);
  }
  delay(3000);
  digitalWrite(ledPin_ir, LOW);

  for(int i = 0; i<data_points; i++)
  {
    Serial.println("Infrared");
    delay(500);

    Serial.println("rgb");
    Serial.println(rgb[i]);
    
    Serial.println("IR");
    Serial.println(ir[i]);
  
    Serial.println("UV");
    Serial.println(ultra[i]);
//    delay(500);

  }
  
//  Serial.println("End_ir");
  delay(3000);
  Serial.println("End");
  
  
//  Serial.println("===================");
//  Serial.print("Vis: "); Serial.println(uv.readVisible());
//  Serial.print("IR: "); Serial.println(uv.readIR());
//  
//  // Uncomment if you have an IR LED attached to LED pin!
////  Serial.print("Prox: "); Serial.println(uv.readProx());
//
//  float UVindex = uv.readUV();
//  // the index is multiplied by 100 so to get the
//  // integer index, divide by 100!
//  UVindex /= 100.0;  
//  Serial.print("UV: ");  Serial.println(UVindex);
//
//  delay(5000);
//  digitalWrite(ledPin_blue, LOW);
//  digitalWrite(ledPin_green, HIGH);
//  delay(5000);

}
void loop()
{}
