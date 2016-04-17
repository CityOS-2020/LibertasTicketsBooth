#define card_motor 23
#define money_motor 22
#define D_5kn 42
#define D_5kn_OUT 43
#define IR_10_IN 32
#define IR_10_OUT 40
#define appPay 53
int knIN = 0; //Morali smo staviti INT jer bool nije radio kako je trebao.
int IR_10kn_IN = 0;
int IR_10kn_OUT=0;
int IR_app=0;
int IR_payment = 0;
String motor_state = "";
String payment = "NOT";

void setup() {
  pinMode(D_5kn, INPUT_PULLUP);
  pinMode(D_5kn_OUT, OUTPUT);
  pinMode(money_motor, OUTPUT);
  pinMode(card_motor, OUTPUT);
  digitalWrite(D_5kn_OUT, LOW);
  Serial.begin(9600);
  
}
  void loop() {
  knIN = digitalRead(D_5kn);
  IR_10kn_IN=digitalRead(IR_10_IN);
  IR_10kn_OUT=digitalRead(IR_10_OUT);
  IR_app=digitalRead(appPay);
  Serial.println(knIN);
  if (IR_10kn_OUT == 0)
  {
    analogWrite(money_motor, 255);
    motor_state = "ON";   
  }
  if (IR_10kn_IN == 0 and motor_state == "ON")
  {
      delay(1500);
      analogWrite(money_motor, 0);
      motor_state = "OFF";
  }
  analogWrite(card_motor, 0);
  if(IR_app==0){
    analogWrite(card_motor, 255);
    delay(500);
    analogWrite(card_motor, 0);
  }
  if (knIN == 0 && IR_10kn_IN == 0)
  {
    IR_payment = 1;
  }
  if (IR_payment == 1 && payment == "NOT"){
    analogWrite(card_motor, 255);
    payment = "YES";
    delay(500);
    analogWrite(card_motor, 0);
  }
}
  


