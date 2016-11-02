
byte msg[] = { 0b1111111,0b1111111,0b1111111,0b1111111,
                0b0111111,0b0111111,0b1111111,0b0001000,
                0b1111001,0b0100001,0b1111111,0b0010010,
                0b0001000,0b1111001,0b0100001,0b1111111,
                0b0111111,0b0111111,0b1111111,0B1111001,
                0b0100100,0b0111111,0b1000000,0b0010000,
                0b0111111,0b0100100,0b1000000,0B1111001,
                0b0000010,0b1111111,0b0111111,0b0111111,
                0b1111111,0b0001001,0b0001000,0b0001100,
                0b0001100,0b0010001,0b1111111,0b0001000,
                0b1111001,0b0100001,0b1111111,0b1111111,
                0b1111111,0b1111111};
void setup(){
  pinMode(A0,INPUT);
  DDRD = B11111110;
  DDRB = B00111111;
}

void loop(){
  unsigned long how = analogRead(A0);
  for (int i = 0; i < 42 ; i++){
    unsigned long Asendi = millis();
    for (unsigned long Rekho = Asendi; Rekho - Asendi <= how ; Rekho = millis()){
      printt(i);
    }
  }   
}

void printt(int k){
  for (int i = 0; i < 4 ; i++){
    PORTB = 1<<(i+1);
    PORTB = ((PORTB>>1)<<1) ^ msg2[k+(3-i)]>>6;
    PORTD = msg[k+(3-i)]<<2;
    delay(5);
  }
}
