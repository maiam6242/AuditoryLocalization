#include <Servo.h>

static double A;
static double B;
static double C;
static double D;

static double a = 0;
static double b = 0;
static double c = 0;
static double d = 0;

static int theta;
static int phi;
static long TH = 100;
static double r;

static Servo bottomservo;
static Servo topservo;

static double starttime;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  A = analogRead(A4);
  B = analogRead(A1);
  C = analogRead(A2);
  D = analogRead(A3);

  Serial.println("Am I working?");

  bottomservo.attach(9);  
  topservo.attach(10); 
  starttime = millis();
  
}

double calcTx(int letter){
 double x = letter - a;
 return x;
}

void turnServos(){
  //TODO: CHANGE IF ANGLES AREN'T RIGHT
  if (theta >= 0 && theta <= 270) {
      if (phi >= 0 && phi <= 270) { // goes from 0 degrees to 270 degrees
        topservo.write(phi);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
        bottomservo.write(theta);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position

    //hold until we have new sound?
  }
  }
 
}


void convertAngles(){
    phi = (phi*180)/PI;
    theta = (theta*180)/PI;  
    Serial.println(phi);
    Serial.println(theta);
}

void convertSpherical(int x, int y, int z){
  
  r = sqrt(pow(x,2)+ pow(y,2) + pow(z,2));
  theta = acos(z/r);
  phi = atan(y/x); 

  //return r;
}

void loop() {
  // put your main code here, to run repeatedly:
  
//if(A > TH && B > TH && C > TH && D > TH){
//  Serial.println("A:");
//  Serial.println(A);
//  Serial.println("B:");
//  Serial.println(B);
//  Serial.println("C:");
//  Serial.println(C);
//  Serial.println("D:");
//  Serial.println(D);
//}
//if (A < TH){
//  A = analogRead(A4);
//}
//if (B < TH){
//  B = analogRead(A1);
//}
//if (C < TH){
//  C = analogRead(A2);
//}
//if (D < TH){
//  D = analogRead(A3);
//}

//while (a == 0 || b == 0 || c == 0 || d == 0)
//{
//   
    if (A > TH && a == 0)
    {
      Serial.println("A:");
      Serial.println(A);
      a = millis() - starttime;
      Serial.println("a:");
      Serial.println(a);
     }
    if (A < TH){
      A = analogRead(A4);
     }


    if (B > TH && b == 0)
     {
      Serial.println("B:");
      Serial.println(B);
      b = millis() - starttime;
      Serial.println("b:");
      Serial.println(b);
     }
    
    else if (B < TH)
     {
      B = analogRead(A1);
     } 


    if (C > TH && c == 0)
     {
     Serial.println("C:");
     Serial.println(C);
     c = millis() - starttime;
     Serial.println("c:");
     Serial.println(c);
     }
    
    if (C < TH)
     {
     C = analogRead(A2);
     }


     if (D > TH && d == 0)
     {
      Serial.println("D:");
      Serial.println(D);
      d = millis() - starttime;
      Serial.println("d:");
      Serial.println(d);
     }
    
    if (D < TH)
     {
     D  = analogRead(A3);
     }

    
//}

}
