
// Laps Timer 
// http://microbot.my
// 
#include <QTRSensors.h>

#define NUM_SENSORS             5  // number of sensors used
#define NUM_SAMPLES_PER_SENSOR  4  // average 4 analog samples per sensor reading
#define EMITTER_PIN             QTR_NO_EMITTER_PIN  // emitter is controlled by digital pin 2

// sensors 0 through 4 are connected to analog inputs 0 through 4, respectively
QTRSensorsAnalog qtra((unsigned char[]) {A0, A1 ,A2 , A3, A6},
  NUM_SENSORS, NUM_SAMPLES_PER_SENSOR, EMITTER_PIN);
unsigned int sensorValues[NUM_SENSORS];


#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET 4
#define SCREEN_ADDRESS 0x3C                                   

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); 

#define WAITING 0 // waiting to start
#define TIMERONE 1 // timer one running
#define TIMERTWO 2 // timer two running
#define FINISHED 3 // timer complete

const long minute = 60000; // 60000 milliseconds in a minute
const int resetPin = 2; 
const int buttonPin = 12; 
const int ledPin =  13;      // the number of the LED pin

long startTime = 0;
long timeOne = 0;
long timeTwo = 0;
int timer = WAITING; // timer state. Initially waiting for first button press
int reset = 0;  // reset button state
int button = 0; // main button state
int ont;
int trashold= 800;


void setup()   {    
  pinMode(buttonPin, INPUT); //init button pin to input
  pinMode(resetPin, INPUT);  //init reset pin to input
  pinMode(ledPin, OUTPUT); // initialize the LED pin as an output: 
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3c
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(10,0);
  printDigits(0);
  
}


void loop() {

    // read raw sensor values
  qtra.read(sensorValues);

ont=sensorValues[0];
  
 timerr();
  }// eo void loop
