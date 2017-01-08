
#include "pitches.h"
const int buttonPin=2;
const int Relayext=13;
const int relayr=4;



int melody[] = {
  NOTE_C4, NOTE_C5,NOTE_C6, NOTE_C7, NOTE_C8};


int noteDurations[] = {
  4, 5, 6, 7,1};
  
void playmusic(){
  for (int thisNote = 0; thisNote < 5; thisNote++) {

    int noteDuration = 1000/noteDurations[thisNote];
    tone(8, melody[thisNote],noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
  }
}
  
void setup() {
 playmusic();
 pinMode(buttonPin, INPUT);
 pinMode(Relayext, OUTPUT);
 pinMode(relayr,OUTPUT);
 digitalWrite(Relayext,LOW);
 digitalWrite(buttonPin,HIGH);
 

 
}

void loop() {
  
  int buttonState;
  
  buttonState=digitalRead(buttonPin);
  
  if(buttonState==0){
    digitalWrite(Relayext,HIGH);
    digitalWrite(relayr,HIGH);
    delay(500);
    digitalWrite(relayr,LOW);
    playmusic();
    delay(1000);
    
    digitalWrite(Relayext,LOW);
    digitalWrite(buttonPin,HIGH);
    //digitalWrite(relayr,LOW);
    
  }
  
    
   
  
}

