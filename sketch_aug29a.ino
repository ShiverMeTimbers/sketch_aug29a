//constants
  int A = 0;
  int B = 0;
  int C = 0;
  int D = 0;
  int i,code;

//declaring pin numbers
int const  switch_A= 2;
int const  switch_B= 3;
int const  switch_C= 4;
int const  switch_D= 5;
int combination[4] ={5,3,4,2};
int userInput[4];
int serialoutput[4];

//array for oattern combination


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //opens serial port, setting data rate to 9600 bps
  pinMode(switch_A, INPUT);
  pinMode(switch_B, INPUT);
  pinMode(switch_C, INPUT);
  pinMode(switch_D, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:


//enter code
 
for(0;i<4;i++){

  //do nothing if pin is low
  while(A!=HIGH && B != HIGH && C!=HIGH && D!=HIGH){
    A= digitalRead(switch_A);
    B= digitalRead(switch_B);
    C= digitalRead(switch_C);
    D= digitalRead(switch_D);
    };

  //if pin is high!  
  if(A == HIGH){
    Serial.println("Switch A working \n");
    code = switch_A;
    userInput[i]=code;
    delay(1000);
  }
  
   else if(B == HIGH){
    Serial.print("Switch B working \n");
    code = switch_B;
    userInput[i]=code;
    delay(1000);
    
  }
  else if(C == HIGH){
    Serial.println("Switch C working \n");
    code = switch_C;
    userInput[i]=code;
    delay(1000);
    
  }
  else if(D == HIGH){
    Serial.println("Switch D working \n");
    code = switch_D;
    userInput[i]=code;
    delay(1000);
    D=LOW;
    digitalWrite(switch_D, LOW);  
    }
    //reset
    A=LOW;B=LOW;C=LOW;
    digitalWrite(switch_A, LOW);
    digitalWrite(switch_B, LOW);
    digitalWrite(switch_C, LOW);
    
    delay(1000);
  }//end for loop

  //display array
//  for(i=0;i<4;i++){  
//    Serial.print(userInput[i]);
//    delay(1000);
//  }

  //compare pattern
  for(i=0;i<4;i++){
    if(combination[i] != userInput[i]){
      Serial.print("Please try again!");delay(10000);
     } 
  } 
  Serial.print("Unlocked!");delay(10000);
     
}
