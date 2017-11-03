#define CUBESIZE 8
//COLUMNS
#define  C0 2
#define  C1 3
#define  C2 4
#define  C3 5
#define  C4 6
#define  C5 7
#define  C6 8
#define  C7 9
//CONTROL
#define SRCLK 11
#define NOT_SRCLK 12
#define RCLK 13
#define NOT_OE A1
//LEVEL
#define LEVEL A0

struct mask
{
  byte level;
  byte col0;
  byte col1;
  byte col2;
  byte col3;
  byte col4;
  byte col5;
  byte col6;
  byte col7;
} MASK;

void setup() {
  // put your setup code here, to run once:
  pinMode(C0, OUTPUT);
  pinMode(C1, OUTPUT);
  pinMode(C2, OUTPUT);
  pinMode(C3, OUTPUT);
  pinMode(C4, OUTPUT);
  pinMode(C5, OUTPUT);
  pinMode(C6, OUTPUT);
  pinMode(C7, OUTPUT);
  pinMode(SRCLK, OUTPUT);
  pinMode(NOT_SRCLK, OUTPUT);
  pinMode(RCLK, OUTPUT);
  pinMode(NOT_OE, OUTPUT);
  pinMode(LEVEL, OUTPUT);
}

void enableOutput()
{
  digitalWrite(NOT_SRCLK, HIGH);
  digitalWrite(NOT_OE, LOW);
}

void writeRegister()
{
  digitalWrite(SRCLK, LOW);
  digitalWrite(SRCLK, HIGH);
}

void latchRegister()
{
  digitalWrite(RCLK, LOW);
  digitalWrite(RCLK, HIGH);
}

void setMask(mask m)
{
  digitalWrite(LEVEL, m.level);
  digitalWrite(C0, m.col0);
  digitalWrite(C1, m.col1);
  digitalWrite(C2, m.col2);
  digitalWrite(C3, m.col3);
  digitalWrite(C4, m.col4);
  digitalWrite(C5, m.col5);
  digitalWrite(C6, m.col6);
  digitalWrite(C7, m.col7);
}

void mode1()
{
  for (int i = 0; i < 8; i++)
  {
    enableOutput();
    MASK.level = HIGH;
    MASK.col0 = HIGH;
    MASK.col1 = HIGH;
    MASK.col2 = HIGH;
    MASK.col3 = HIGH;
    MASK.col4 = HIGH;
    MASK.col5 = HIGH;
    MASK.col6 = HIGH;
    MASK.col7 = HIGH;
    setMask(MASK);
    writeRegister();
    latchRegister();
    delay(200);
  }
  for (int i = 0; i < 8; i++)
  {
    enableOutput();
    MASK.level = LOW;
    MASK.col0 = LOW;
    MASK.col1 = LOW;
    MASK.col2 = LOW;
    MASK.col3 = LOW;
    MASK.col4 = LOW;
    MASK.col5 = LOW;
    MASK.col6 = LOW;
    MASK.col7 = LOW;
    setMask(MASK);
    writeRegister();
    latchRegister();
    delay(100);
  }
}

void loop() {
  mode1();
  mode1();
  mode1();
  mode1();
  delay(500);
}
