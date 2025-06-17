void setup() 
{
  Serial.begin(9600);
  
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() 
{
  //serial info read
  if ( Serial.available() > 0 ) { //if bites detected
    char simbols = Serial.read(); //read data by one bite

    Serial.println(simbols, DEC);

    //turn on LED once got 1 from input
    if (simbols == 49) { //49 == '1'
      digitalWrite(LED_BUILTIN, HIGH);
    } else if (simbols == '0'){
      digitalWrite(LED_BUILTIN, LOW);
    }

  }

  delay(50); //only for simulation

}