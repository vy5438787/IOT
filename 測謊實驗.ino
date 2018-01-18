const int BUZZER=2;
const int GSR=A2;
int threshold=0;
int sensorValue;
 
void setup(){
  long sum=0;
  Serial.begin(9600);
  pinMode(BUZZER,OUTPUT);
  digitalWrite(BUZZER,LOW);
  delay(1000);
  
 for(int i=0;i<500;i++)
  {
  sensorValue=analogRead(GSR);
  sum += sensorValue;
  delay(5);
  }
  threshold = sum/500;
   Serial.print("threshold =");
   Serial.println(threshold);
  }
 
void loop(){
  int temp;
  sensorValue=analogRead(GSR);
  Serial.print("sensorValue=");
  Serial.println(sensorValue);
  //temp = threshold - sensorValue;
  if(abs(sensorValue)<50)
  {
    digitalWrite(BUZZER,HIGH);
    Serial.println("YES!");
    delay(100);
    digitalWrite(BUZZER,LOW);
    delay(100);
  } else  if(abs(sensorValue) >= 50){
    Serial.println("No!");    
  }
  
  }
