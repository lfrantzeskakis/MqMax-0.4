
int enablepin=6;
int startpin1=5;
int startpin2=4;
int ledpin=13;
int manualpin=8;
int workingpin=9;
int standbypin=10;
int manualmodepin=11;
int watertable[100];
int flag=0;
int long timepass=0;
int long timesetwork=600000;//10 minutes
int long timesetwait=40000; //40 sec

boolean istherewater(){
  int temp=0;
  float temp1=0;
  for(int i=0; i<100;i++){
    delay(100);
    int sensorValue = analogRead(A0);
    watertable[i]=sensorValue;
  }
  for(int i=0; i<100;i++)
    temp= watertable[i]+temp;
   
  temp1=temp/100;
float voltage= temp1*(5.0/1023.0);
if (voltage>2.0)
return true;
else
return false;
}
    


void setup() {
 pinMode(enablepin,OUTPUT);
 pinMode(startpin1,OUTPUT);
 pinMode(startpin2,OUTPUT);
 pinMode(ledpin,OUTPUT);
 Serial.begin(9600);
 digitalWrite(ledpin,LOW);
 digitalWrite(enablepin,LOW);
 digitalWrite(startpin1,LOW);
 int flag=0;
 
 
}


void loop() {
  unsigned long currentMillis = millis();
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1023.0);
 
  
  if(voltage < 1){
    digitalWrite(ledpin,LOW);
    digitalWrite(enablepin,LOW);
    digitalWrite(startpin1,LOW);
  }
  
  
  if(voltage > 2.5 && flag == 0){
    digitalWrite(ledpin,HIGH);
    digitalWrite(enablepin,HIGH);
    digitalWrite(startpin1,HIGH);
    flag=1;
    }
    
   if(manualmodepin ==1 && flag == 0){
     digitalWrite(ledpin,HIGH);
    digitalWrite(enablepin,HIGH);
    digitalWrite(startpin1,HIGH);
    //time count
    flag=1;
   }
     
  
  Serial.print(voltage);
  Serial.print("| led is : ");
  Serial.println(digitalRead(ledpin));
  
  
}
