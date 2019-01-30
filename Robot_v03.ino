#define LS 6      //  левый датчик
#define RS 7      // правый датчик
 
#define DIR_R   2
#define SPEED_R  3 
#define DIR_L  4     
#define SPEED_L  5

void setup()
{
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(DIR_R , OUTPUT);
  pinMode(SPEED_R , OUTPUT);
  pinMode(DIR_L , OUTPUT);
  pinMode(SPEED_L, OUTPUT);
}
void loop()
{
  if(digitalRead(LS==HIGH) && digitalRead(RS==HIGH))     // Движение вперед
  {
    digitalWrite(DIR_R , HIGH);
    digitalWrite(SPEED_R ,HIGH);
    digitalWrite(DIR_L , HIGH);
    digitalWrite(SPEED_L ,HIGH);
  }
  
  if((digitalRead(LS==LOW)) && digitalRead(RS==HIGH))     // Поворот направо
  {
   digitalWrite(DIR_R , HIGH);
    digitalWrite(SPEED_R ,LOW);
    digitalWrite(DIR_L , HIGH);
    digitalWrite(SPEED_L ,HIGH);


  }
  
  if(digitalRead(LS==HIGH) && (digitalRead(RS==LOW))     // Поворот влево
  {
    digitalWrite(DIR_R , HIGH);
    digitalWrite(SPEED_R ,HIGH);
    digitalWrite(DIR_L , HIGH);
    digitalWrite(SPEED_L ,LOW);
 }
  
  if(digitalRead(LS==LOW) && (digitalRead(RS==LOW))     // остановка
  { digitalWrite(DIR_R , HIGH);
    digitalWrite(SPEED_R ,HIGH);
    digitalWrite(DIR_L , HIGH);
    digitalWrite(SPEED_L ,HIGH);
 }
}