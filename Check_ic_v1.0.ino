int i = 0;
int pin6 = 6;
int pin7 = 7;
int pin5 = 5;
int arr[10] ;
int sta = -1;
void setup() {
  Serial.begin(9600);
}
//---------------------------------------------------------------------The loop function runs over and over again forever ------------------------------------//
void loop() {
  while(i < 1){ 
  Serial.println("LEST_START");
    setup_1();
    Mode_1();
    sta = CheckIC_1();
    //Serial.println("MODE1");
      if(sta == 11){
      Serial.println("MODE2");
      setup_2();
      Mode_2();
      sta = CheckIC_2();
      }
      if(sta == 22){
        Serial.println("MODE3");
      setup_3();
      //Mode_3();
        
      }
      
  //Serial.println("arr[1]" + int(arr[0]));
  Serial.println("END");
  i++;
  }
}
//end loop
//----------------------------------------------------------------------------------------end loop----------------------------------------------------------//
// statuss
void statuss(){
   if(digitalRead(pin5) == HIGH){
      Serial.println("HIGH");
  }
    if(digitalRead(pin5) == LOW){
    Serial.println("LOW");
  }
}
//-------------------------------------------- Check Number IC ----------------------------------//
// CheckIC_1
int CheckIC_1(){
  
  if((arr[0] == 0) && (arr[1] == 1) && (arr[2] == 1) && (arr[3] == 1) ){
    Serial.println("IC 7432 OR GATE");
    return 1;
  }
  if((arr[0] == 0) && (arr[1] == 0) && (arr[2] == 0) && (arr[3] == 1) ){
    Serial.println("IC 7408 AND GATE");
    return 1;
  }
  if((arr[0] == 0) && (arr[1] == 1) && (arr[2] == 1) && (arr[3] == 0) ){
    Serial.println("IC 7486 XOR GATE");
    return 1;
  }
  if((arr[0] == 1) && (arr[1] == 1) && (arr[2] == 1) && (arr[3] == 0) ){
    Serial.println("IC 7400 NAND GATE");
    return 1;
  }
  return 11;
}
// CheckIC_2
int CheckIC_2(){
  if((arr[0] == 1) && (arr[1] == 0) && (arr[2] == 1) && (arr[3] == 0) ){
    Serial.println("IC 7404 NOT GATE");
    return 22;
  }
  else Serial.println("IC 74??");
  return 22;
}
//-------------------------------------------- End Check Number IC ----------------------------------//
//--------------------------------------------- Select Mode ----------------------------------------//
//-----------------------------------Mode(1) 2 in 1
void Mode_1(){
  digitalWrite(pin6,LOW);
  digitalWrite(pin7,LOW);
  arr[0] = digitalRead(pin5);
  statuss();
  //delay(1000);
  digitalWrite(pin6,LOW);
  digitalWrite(pin7,HIGH);
  arr[1] = digitalRead(pin5);
  statuss();
  //delay(1000);
  digitalWrite(pin6,HIGH);
  digitalWrite(pin7,LOW);
  arr[2] = digitalRead(pin5);
  statuss();
  //delay(1000);
  digitalWrite(pin6,HIGH);
  digitalWrite(pin7,HIGH);
  arr[3] = digitalRead(pin5);
  statuss();
  //delay(1000);
}

//---------------------------------------Mode(1) 1 in 1
void Mode_2(){
  digitalWrite(pin6,LOW);
  //digitalWrite(pin7,LOW);
  arr[0] = digitalRead(pin7);
  //statuss();
  //delay(1000);
  
  digitalWrite(pin6,HIGH);
  //digitalWrite(pin7,HIGH);
  arr[1] = digitalRead(pin7);
  //statuss();
  //delay(1000);
  
  digitalWrite(pin6,LOW);
  //digitalWrite(pin7,LOW);
  arr[2] = digitalRead(pin7);
  //statuss();
  //delay(1000);
  
  digitalWrite(pin6,HIGH);
  //digitalWrite(pin7,HIGH);
  arr[3] = digitalRead(pin7);
  //statuss();
  //delay(1000);
}
//------------------------------------------- End Select Mode ----------------------------------------//

//---------------------------------------------- Setup mode --------------------------//
//Setup mode_1 2 in 1
void setup_1() {
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,INPUT);
}
//Setup mode_2 1 in 1
void setup_2() {
  //Serial.begin(9700);
  pinMode(7,OUTPUT);
  pinMode(6,INPUT);
  //pinMode(5,INPUT);
  //Serial.println("MODE2");
}
//Setup mode_3 1 in 2
void setup_3() {
  //Serial.begin(9700);
  pinMode(6,OUTPUT);
  pinMode(7,INPUT);
  //pinMode(5,INPUT);
  //Serial.println("MODE2");
}
//---------------------------------------------- End Setup mode --------------------------//




