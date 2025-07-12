#include <Servo.h>   
int da =  -40, 
    db =   10,  
    dc =  -18,  
    dd =   12;  
int a90  = (90  + da),
    a120 = (120 + da),
    a150 = (150 + da),
    a180 = (180 + da);

int b0   = (0   + db),
    b30  = (30  + db),
    b60  = (60  + db),
    b90  = (90  + db);

int c90  = (90  + dc),
    c120 = (120 + dc),
    c150 = (150 + dc),
    c180 = (180 + dc);

int d0   = (0   + dd),
    d30  = (30  + dd),
    d60  = (60  + dd),
    d90  = (90  + dd);


int s11 = 90; 
int s12 = 90; 
int s21 = 90; 
int s22 = 90; 
int s31 = 90; 
int s32 = 90; 
int s41 = 90; 
int s42 = 90; 

int f    = 0;
int b    = 0;
int l    = 0;
int r    = 0;
int spd  = 3;   
int high = 0;  


Servo myServo1;
Servo myServo2; 
Servo myServo4; 
Servo myServo5; 
Servo myServo6;
Servo myServo7;
Servo myServo8; 


void setup()
{
  myServo1.attach(4);
  myServo2.attach(5);
  myServo3.attach(6);
  myServo4.attach(7);
  myServo5.attach(8);
  myServo6.attach(9);
  myServo7.attach(10);
  myServo8.attach(11);

  Serial.begin(9600); 

}



char Received_Command = 'S',Valid_Received_Command = 'S';   

void loop()
{
  unsigned long value;
  unsigned long lastValue;
  
  center_servos(); 
  high = 15;       
  spd = 3;        

  while (1 == 1)  
  {

    if(Serial.available())                
    {
        Received_Command = Serial.read();
        
  
        if((Received_Command == 'F')||(Received_Command == 'B')||(Received_Command == 'R')||(Received_Command == 'L')||(Received_Command == 'X')||(Received_Command == 'Y')
       ||(Received_Command == 'M')||(Received_Command == 'm')||(Received_Command == 'N')||(Received_Command == 'n')||(Received_Command == 'S'))
       {
            Valid_Received_Command =  Received_Command;
            Serial.println(Received_Command);
       }
    }

    if(Valid_Received_Command == 'F')          
    {
      forward();
    }
    else if(Valid_Received_Command == 'B')     
    {
      back();
    }
    else if(Valid_Received_Command == 'L')      
    {
      turn_left();
    }
    else if(Valid_Received_Command == 'R')    
    {
      turn_right();
    }
    else if(Valid_Received_Command == 'X')   
    {
      dance();
      Valid_Received_Command = 'S';
    }
    else if(Valid_Received_Command == 'Y')    
    {
      wave();
      Valid_Received_Command = 'S';
    }
    else if((Valid_Received_Command == 'S')||(Valid_Received_Command == 'm')||(Valid_Received_Command == 'n'))  
    {      
      center_servos(); 
      high = 15;       
      spd = 3;         
      Valid_Received_Command = 'P';
    }
      

      delay(1000);  

  }

}

void dance()
{
  center_servos();
  delay(100);
  lean_left();
  delay(100);
  lean_right();
  delay(100);
  lean_left();
  delay(100);
  lean_right();
  delay(100);
  lean_left();
  delay(100);
  lean_right();
  delay(100);
  lean_left();
  delay(100);
  lean_right();
  delay(100);
  center_servos();
  delay(100);
  bow();
  delay(100);
  center_servos();
}



void wave()
{


  center_servos();
  myServo4.write(45);
  myServo6.write(45);
  delay(1000);
  myServo8.write(0);
  delay(1000);
  myServo7.write(180);
  delay(1000);
  myServo7.write(30);
  delay(1000);
  myServo7.write(150);
  delay(1000);
  myServo7.write(30);
  delay(1000);
  myServo7.write(s41);
  delay(1000);
  myServo8.write(s42);
  center_servos();

}


void bow()
{
  center_servos();
  delay(100);
  myServo2.write(15);
  myServo8.write(15);
  delay(100);
  myServo2.write(90);
  myServo8.write(90);
  delay(100);
  
}


void lean_left()
{
  myServo2.write(15);
  myServo4.write(15);
  myServo6.write(150);
  myServo8.write(150);
}

void lean_right()
{
  myServo2.write(150);
  myServo4.write(150);
  myServo6.write(15);
  myServo8.write(15);
}


void trim_left()
{
  da--; 
  db--; 
  dc--; 
  dd--;
}



void trim_right()
{
  da++;
  db++;
  dc++;
  dd++; 
}



void forward()
{
  


  a90 = (90 + da),
  a120 = (120 + da),
  a150 = (150 + da),
  a180 = (180 + da);

 
  b0 = (0 + db),
  b30 = (30 + db),
  b60 = (60 + db),
  b90 = (90 + db);

  
  c90 = (90 + dc),
  c120 = (120 + dc),
  c150 = (150 + dc),
  c180 = (180 + dc);


  d0 = (0 + dd),
  d30 = (30 + dd),
  d60 = (60 + dd),
  d90 = (90 + dd);

  
  srv(a180, b0 , c120, d60, 42,  33,  33,  42,  1,  3,  1,  1);
  srv( a90, b30, c90,  d30, 6,   33,  33,  42,  3,  1,  1,  1);
  srv( a90, b30, c90,  d30, 42,  33,  33,  42,  3,  1,  1,  1);
  srv(a120, b60, c180, d0,  42,  33,  6,   42,  1,  1,  3,  1);
  srv(a120, b60, c180, d0,  42,  33,  33,  42,  1,  1,  3,  1);
  srv(a150, b90, c150, d90, 42,  33,  33,  6,   1,  1,  1,  3);
  srv(a150, b90, c150, d90, 42,  33,  33,  42,  1,  1,  1,  3);
  srv(a180, b0,  c120, d60, 42,  6,   33,  42,  1,  3,  1,  1);

}

void back ()
{

  srv(180, 0,  120, 60, 42, 33, 33, 42, 3,  1, 1, 1);
  srv(150, 90, 150, 90, 42, 18, 33, 42, 1,  3, 1, 1);
  srv(150, 90, 150, 90, 42, 33, 33, 42, 1,  3, 1, 1);
  srv(120, 60, 180, 0,  42, 33, 33, 6,  1,  1, 1, 3);
  srv(120, 60, 180, 0,  42, 33, 33, 42, 1,  1, 1, 3);
  srv(90,  30, 90,  30, 42, 33, 18, 42, 1,  1, 3, 1);
  srv(90,  30, 90,  30, 42, 33, 33, 42, 1,  1, 3, 1);
  srv(180, 0,  120, 60, 6,  33, 33, 42, 3,  1, 1, 1);

}



void turn_left ()
{

  srv(150,  90, 90,  30, 42, 6,  33, 42, 1, 3, 1, 1);
  srv(150,  90, 90,  30, 42, 33, 33, 42, 1, 3, 1, 1);
  srv(120,  60, 180, 0,  42, 33, 6,  42, 1, 1, 3, 1);
  srv(120,  60, 180, 0,  42, 33, 33, 24, 1, 1, 3, 1);
  srv(90,   30, 150, 90, 42, 33, 33, 6,  1, 1, 1, 3);
  srv(90,   30, 150, 90, 42, 33, 33, 42, 1, 1, 1, 3);
  srv(180,  0,  120, 60, 6,  33, 33, 42, 3, 1, 1, 1);
  srv(180,  0,  120, 60, 42, 33, 33, 33, 3, 1, 1, 1);
}



void turn_right ()
{
  srv( 90, 30, 150, 90, 6,  33, 33, 42, 3, 1, 1, 1);
  srv( 90, 30, 150, 90, 42, 33, 33, 42, 3, 1, 1, 1);
  srv(120, 60, 180, 0,  42, 33, 33, 6,  1, 1, 1, 3);
  srv(120, 60, 180, 0,  42, 33, 33, 42, 1, 1, 1, 3);
  srv(150, 90, 90,  30, 42, 33, 6,  42, 1, 1, 3, 1);
  srv(150, 90, 90,  30, 42, 33, 33, 42, 1, 1, 3, 1);
  srv(180, 0,  120, 60, 42, 6,  33, 42, 1, 3, 1, 1);
  srv(180, 0,  120, 60, 42, 33, 33, 42, 1, 3, 1, 1);
}



void center_servos()
{
  myServo1.write(90);
  myServo2.write(90);
  myServo3.write(90);
  myServo4.write(90);
  myServo5.write(90);
  myServo6.write(90);
  myServo7.write(90);
  myServo8.write(90);

  int s11 = 90; 
  int s12 = 90; 
  int s21 = 90; 
  int s22 = 90;
  int s31 = 90; 
  int s32 = 90; 
  int s41 = 90; 
  int s42 = 90; 
}



void increase_speed()
{
  if (spd > 3)
    spd--;
}



void decrease_speed()
{
  if (spd < 50)
    spd++;
}


void srv( int  p11, int p21, int p31, int p41, int p12, int p22, int p32, int p42, int sp1, int sp2, int sp3, int sp4)
{


  p12 = p12 + high * 3;
  p22 = p22 + high * 3;
  p32 = p32 + high * 3;
  p42 = p42 + high * 3;

  while ((s11 != p11) || (s21 != p21) || (s31 != p31) || (s41 != p41) || (s12 != p12) || (s22 != p22) || (s32 != p32) || (s42 != p42))
  {

 
    if (s11 < p11)     
    {
      if ((s11 + sp1) <= p11)
        s11 = s11 + sp1;   
      else
        s11 = p11;
    }

    if (s11 > p11)        
    {
      if ((s11 - sp1) >= p11)
        s11 = s11 - sp1;    
      else
        s11 = p11;
    }

    if (s21 < p21)
    {
      if ((s21 + sp2) <= p21)
        s21 = s21 + sp2;
      else
        s21 = p21;
    }

    if (s21 > p21)
    {
      if ((s21 - sp2) >= p21)
        s21 = s21 - sp2;
      else
        s21 = p21;
    }

    
    if (s31 < p31)
    {
      if ((s31 + sp3) <= p31)
        s31 = s31 + sp3;
      else
        s31 = p31;
    }

    if (s31 > p31)
    {
      if ((s31 - sp3) >= p31)
        s31 = s31 - sp3;
      else
        s31 = p31;
    }

    
    if (s41 < p41)
    {
      if ((s41 + sp4) <= p41)
        s41 = s41 + sp4;
      else
        s41 = p41;
    }

    if (s41 > p41)
    {
      if ((s41 - sp4) >= p41)
        s41 = s41 - sp4;
      else
        s41 = p41;
    }

   
    if (s12 < p12)
    {
      if ((s12 + sp1) <= p12)
        s12 = s12 + sp1;
      else
        s12 = p12;
    }

    if (s12 > p12)
    {
      if ((s12 - sp1) >= p12)
        s12 = s12 - sp1;
      else
        s12 = p12;
    }

   
    if (s22 < p22)
    {
      if ((s22 + sp2) <= p22)
        s22 = s22 + sp2;
      else
        s22 = p22;
    }

    if (s22 > p22)
    {
      if ((s22 - sp2) >= p22)
        s22 = s22 - sp2;
      else
        s22 = p22;
    }

    
    if (s32 < p32)
    {
      if ((s32 + sp3) <= p32)
        s32 = s32 + sp3;
      else
        s32 = p32;
    }

    if (s32 > p32)
    {
      if ((s32 - sp3) >= p32)
        s32 = s32 - sp3;
      else
        s32 = p32;
    }

    
    if (s42 < p42)
    {
      if ((s42 + sp4) <= p42)
        s42 = s42 + sp4;
      else
        s42 = p42;
    }

    if (s42 > p42)
    {
      if ((s42 - sp4) >= p42)
        s42 = s42 - sp4;
      else
        s42 = p42;
    }

  
    myServo1.write(s11 + da);
    myServo3.write(s21 + db);
    myServo5.write(s31 + dc);
    myServo7.write(s41 + dd);

    
    myServo2.write(s12);
    myServo4.write(s22);
    myServo6.write(s32);
    myServo8.write(s42);

    delay(spd); 

  }
} 
