int RightSensor = 4;
int LeftSensor = 11;
int ENB = 5;
int In4 = 6;
int In3 = 7;
int In2 = 8;
int In1 = 9;
int ENA = 10;

int prevState = 0;
int curState;

void turnOnRightEngine(int val, boolean Direction){
  if(Direction){
    digitalWrite(In2, LOW);  
    digitalWrite(In1, HIGH);
  } 
  else{
    digitalWrite(In2, HIGH);  
    digitalWrite(In1, LOW);     
  }
  analogWrite(ENA, val);
}

void turnOnLeftEngine(int val, boolean Direction){
  if(Direction){
    digitalWrite(In3, LOW);  
    digitalWrite(In4, HIGH);
  } 
  else{
    digitalWrite(In3, HIGH);  
    digitalWrite(In4, LOW);     
  }
  analogWrite(ENB, val);
}

void turnOffRightEngine(){
    digitalWrite(In2, LOW);  
    digitalWrite(In1, LOW);
    analogWrite(ENA,0);
}

void turnOffLeftEngine(){
    digitalWrite(In3, LOW);  
    digitalWrite(In4, LOW);
    analogWrite(ENB,0);
}

void setup() 
{ 
  pinMode(RightSensor, INPUT);
  pinMode(LeftSensor, INPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
}  

void changeState(int state){
   switch(state){
    case 0:
    {
      turnOffLeftEngine();
      turnOffRightEngine();
      break; 
    }
    case 1:
    {
      turnOffLeftEngine();
      turnOnRightEngine(150, true);
      break; 
    }
    case 2:
    {
      turnOffRightEngine();
      turnOnLeftEngine(150, true);
      break; 
    }
    case 3:
    {
      turnOnLeftEngine(150, true);
      turnOnRightEngine(150, true);
      break; 
    }
  }
}

void loop()
{
  int rs = digitalRead(RightSensor);
  int ls = digitalRead(LeftSensor);
  int state = prevState;
  
  switch(state){
    case 0:
    {
      if(ls == 1 && rs == 0)
        curState = 3;
      else
        curState = 0;
      break; 
    }
    case 1:
    {
      if(ls == 0 && rs == 0)
        curState = 1;
      else if(rs == 1)
        curState = 2;
      else if(ls == 1 && rs == 0)
        curState = 3;
      break; 
    }
    case 2:
    {
      if(ls == 0 && rs == 0)
        curState = 2;
      else if(rs == 1)
        curState = 2;
      else if(ls == 1 && rs == 0)
        curState = 3;
      break; 
    }
    case 3:
    {
      if(ls == 0 && rs == 0)
        curState = 1;
      else if(rs == 1)
        curState = 2;
      else if(ls == 1 && rs == 0)
        curState = 3;
      break; 
    }
  }
  changeState(curState);
  prevState = curState;
}