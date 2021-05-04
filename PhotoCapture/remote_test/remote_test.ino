int cam = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(cam, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(cam, LOW); 
  delay(5000);
  digitalWrite(cam, HIGH);
  delay(200);
}


// orange/white is +
