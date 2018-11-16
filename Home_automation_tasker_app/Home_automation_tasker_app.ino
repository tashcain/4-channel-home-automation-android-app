#define ledPin 10
//Pins Going to switches
#define s1 5
#define s2 4
#define s3 3
#define s4 2
// pins going to ralays
#define r1 10
#define r2 11
#define r3 12
#define r4 13
// pins reading switch pins(s1 is connected to t1, s2 to t2 and so on)
#define t1 9
#define t2 8
#define t3 7
#define t4 6

int s1_,s2_,s3_,s4_,t1_,t2_,t3_,t4_;
int ps1=-1;
int ps2=-1;
int ps3=-1;
int ps4=-1;
int state = 0;
void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  pinMode(t1,INPUT_PULLUP);
  pinMode(t2,INPUT_PULLUP);
  pinMode(t3,INPUT_PULLUP);
  pinMode(t4,INPUT_PULLUP);
  pinMode(s1,INPUT_PULLUP);
  pinMode(s2,INPUT_PULLUP);
  pinMode(s3,INPUT_PULLUP);
  pinMode(s4,INPUT_PULLUP);
  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);
  pinMode(r3,OUTPUT);
  pinMode(r4,OUTPUT);
  Serial.begin(38400); // Default communication rate of the Bluetooth module
}

void loop() {

  
  if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port

  }
 if (state == '1') {
  digitalWrite(r1, LOW); // Turn LED OFF
  Serial.println("S1: OFF"); // Send back, to the phone, the String "LED: ON"
  state = 0;
 }
 else if (state == '2') {
  digitalWrite(r1, HIGH);
  Serial.println("S1: ON");;
  state = 0;
 } 
 if (state == '3') {
  digitalWrite(r2, LOW); // Turn LED OFF
  Serial.println("S2: OFF"); // Send back, to the phone, the String "LED: ON"
  state = 0;
 }
 else if (state == '4') {
  digitalWrite(r2, HIGH);
  Serial.println("S2: ON");;
  state = 0;
 } 
 if (state == '5') {
  digitalWrite(r3, LOW); // Turn LED OFF
  Serial.println("S3: OFF"); // Send back, to the phone, the String "LED: ON"
  state = 0;
 }
 else if (state == '6') {
  digitalWrite(r3, HIGH);
  Serial.println("S3: ON");;
  state = 0;
 } 
 if (state == '7') {
  digitalWrite(r4, LOW); // Turn LED OFF
  Serial.println("S4: OFF"); // Send back, to the phone, the String "LED: ON"
  state = 0;
 }
 else if (state == '8') {
  digitalWrite(r4, HIGH);
  Serial.println("S4: ON");;
  state = 0;
 } 
 
  s1_=digitalRead(s1);
  s2_=digitalRead(s2);
  s3_=digitalRead(s3);
  s4_=digitalRead(s4);
  if(s1_!=ps1)
  {
      ps1=s1_;
      digitalWrite(r1,ps1);
  }
  if(s2_!=ps2)
  {
      ps2=s2_;
      digitalWrite(r2,ps2);
  }
  if(s3_!=ps3)
  {
      ps3=s3_;
      digitalWrite(r3,ps3);
  }
  if(s4_!=ps4)
  {
      ps4=s4_;
      digitalWrite(r4,ps4);
  }
  t1_=digitalRead(t1);
  t2_=digitalRead(t2);
  t3_=digitalRead(t3);
  t4_=digitalRead(t4);
  // for debugging on serial
  Serial.print(t1_);
  Serial.print("\t");
  Serial.print(t2_);
  Serial.print("\t");
  Serial.print(t3_);
  Serial.print("\t");
  Serial.print(t4_);
  Serial.print("\t\t");
  Serial.print(s1_);
  Serial.print("\t");
  Serial.print(s2_);
  Serial.print("\t");
  Serial.print(s3_);
  Serial.print("\t");
  Serial.print(s4_);
  Serial.print("\n");
  
}
