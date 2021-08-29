  

void timerr(){
  //-------- main loop -------
 switch ( timer){
   case WAITING: // initial state - waiting for first button press.
     display.clearDisplay();
     display.setCursor(10,00); 
     printDigits(0);
     display.display(); // display screen showing 00:00s
     button = digitalRead(buttonPin);
     if(button){ // button is pressed.
       timer = TIMERONE; // start the first timer 
       startTime = millis();//read the time the button is pressed.
       while (digitalRead(buttonPin)){
         //--- wait for button to be released.
       }
     }
   break;
   case TIMERONE: //running first timer
     timeOne = millis();
     button = digitalRead(buttonPin);
     reset = digitalRead(resetPin);
     display.clearDisplay();
     display.setCursor(10,00);
     printDigits(timeOne - startTime);
     display.display();
     //-----------------------------------
     if(reset){ //reset button was pressed. Clear screeen and start again
       timer = WAITING;
       while (digitalRead(resetPin)){
         //--- wait for reset button to be released.
       }
     }
     //------------------------------------
     if(button){ // button was pressed
         timer = TIMERTWO;  // start the second timer
         //timeTwo = millis(); //record the time for the start of the second timer
         while (digitalRead(buttonPin)){
           //--- wait for button to be released.
         }
       }
   break;
   
    case FINISHED: //running first timer
     reset = digitalRead(resetPin);
     if(reset){ //reset button was pressed. Clear screeen and start again
       display.clearDisplay();
       display.setCursor(10,0);
       printDigits(0);
       display.display();
       timer = WAITING;
       while (digitalRead(resetPin)){
         //--- wait for reset button to be released.
       }
     } 
   break;  
   } // eo switch


  
}

void printDigits(long timeInMillis){ 
  // convert the time from milliseconds to four digit SS:HH 
  // seconds and hundredths and display at current cursor position
  int seconds;
  int hundredths;
  seconds = timeInMillis /1000;
  seconds = seconds % 60; // seconds never more than 60
  hundredths = (timeInMillis % 1000)/10;
  
  if (seconds <10){ // print leading zero if necessary
    display.print("0");
  }
  display.print(seconds);
  display.print(":");
  if (hundredths <10){ //print leading zero if necessary
  display.print("0");
  
  }
  display.print(hundredths);
  display.print("s");
  //display.display();
}
