
int buttonState = 0;

void setup() {
  // Set MIDI baud rate:
  Serial1.begin(31250);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(18, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(18);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(LED_BUILTIN, HIGH);
    noteOn(0x90, 0x3C, 0x45);
    delay(50);
    noteOn(0x90, 0x3C, 0x00);
    
    delay(100);
    noteOn(0x90, 0x3E, 0x45);
    delay(50);
    noteOn(0x90, 0x3E, 0x00);

    delay(100);
    noteOn(0x90, 0x40, 0x45);
    delay(50);
    noteOn(0x90, 0x40, 0x00);

    delay(100);
    noteOn(0x90, 0x41, 0x45);
    delay(50);
    noteOn(0x90, 0x41, 0x00);

    delay(100);
    noteOn(0x90, 0x40, 0x45);
    delay(50);
    noteOn(0x90, 0x40, 0x00);

    delay(200);
    noteOn(0x90, 0x3C, 0x45);
    delay(50);
    noteOn(0x90, 0x3C, 0x00);

    delay(100);
    noteOn(0x90, 0x3E, 0x45);
    delay(50);
    noteOn(0x90, 0x3E, 0x00);
    
  }
}

// plays a MIDI note. Doesn't check to see that cmd is greater than 127, or that
// data values are less than 127:
void noteOn(int cmd, int pitch, int velocity) {
  Serial1.write(cmd);
  Serial1.write(pitch);
  Serial1.write(velocity);
}
