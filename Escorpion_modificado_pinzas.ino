

/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                    Robot Escorpion                                              //
//                         Primera Secuencia del Modulo PCA96850                                   //
//                    modulo PWM para controlar los Servos del Escorpion                           //
// Bluetooth HC-06 para la comunicacion del escorpion y dispositivi de sistema opertivo android    // 
/////////////////////////////////////////////////////////////////////////////////////////////////////

//Notas importantes:
//El escopion sera alimentado con la fuente de 5V a 2.2A
//Programacion para que camine el Escopion

/////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Servo.h>

#include <Wire.h>                                                                                  //Llamada para abrir librería específica
#include <Adafruit_PWMServoDriver.h>                                                               //Incluimos la libreria anexa de modulo PWM

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();                                           //Llamado de esta forma para la direccion predeterminada de 0x40
                                                                                                   //Puedes llamarlo en la direccion que desees
                                                                                                   //También puedes llamarlo con la interfaz I2C

#define SERVOMIN  150                                                                              //Este es el conteo de longitud de pulso minimo (de 4096)
#define SERVOMAX  600                                                                              //Este es el conteo de longitud de pulso maximo (de 4096)

uint8_t servonum = 0;                                                                              //Declaramos el servonum como cero
int tiempo01 = 700;                                                                               //Declaramos el tiempo en milisegundos
int tiempo02 = 4000;                                                                               //Declaramos el tiempo en milisegundos
int tiempo03 = 4000;                                                                               //Declaramos el tiempo en milisegundos

char lectura;

int ang = 0;
int tiempo01 = 5000;
int tiempo02 = 20;

Servo cola01;
Servo cola02;
Servo cola03;

Servo pinza01;
Servo izq02;
Servo der03;


 /////////////////////////////////////////////////////////////////////////////////////////////////////


void setup() 
{
  Serial.begin(9600); 
  Serial.println("Prueba de 12 Canales");                                                          //Prueba de servo de 12 Canales

  pwm.begin();
  
  pwm.setPWMFreq(60);                                                                              //Los servos analogicos funcionan a 60Hz de pulso
  delay(10);                                                                                       //Declaramos el tiempo de 10 milisegundos
  sec_home();
  
  cola01.attach( 9);
  cola02.attach(10);
  cola03.attach(11);
  
  cola01.write(130);
  cola02.write( 90);
  cola03.write( 70);
    delay(tiempo01);
    
 pinza01.attach(3);
  izq02.attach(5);
  der03.attach(6);
    
  pinza01.write(55);                         // limite 55 a 140 para abrir 
  izq02.write(55);                            //limite 40 para adentro a 90
  der03.write(55);                            // limite 25 para afuera a 85
    delay(tiempo01);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void loop() 
{
  
     //sec_adelante();
     //delay(tiempo02);
     if(Serial.available())
     {
      lectura=Serial.read();
  
      if(lectura=='A')
       sec_adelante();
       
       if(lectura=='C')
       sec_home();
       
       if(lectura=='B')
       sec_atras();
       
       if(lectura=='E')
       sec_izquierda();
       
       if(lectura=='D')
       sec_derecha();
       
       if(lectura=='F')
       sec_picotazo();
       
       if(lectura=='G')
       sec_pinza_izq();
       
       if(lectura=='H')
       sec_pinza_der();
       
       if(lectura=='I')
       sec_griper abierto();
       
       if(Lectura=='J')
       sec_griper cerrado();
     }
     
   } 

void sec_adelante()
{
pwm.setPWM( 0, 0, 220);                                        //Servo Hombro01 en origen
 pwm.setPWM( 1, 0, 495);
 pwm.setPWM( 2, 0, 230);
 pwm.setPWM( 3, 0, 305);
 pwm.setPWM( 4, 0, 260);
 pwm.setPWM( 5, 0, 340);
 pwm.setPWM( 6, 0, 450);
 pwm.setPWM( 7, 0, 515);
 pwm.setPWM( 8, 0, 385);
 pwm.setPWM( 9, 0, 350);
 pwm.setPWM( 10, 0, 200);
 pwm.setPWM( 11, 0, 470);
 delay(tiempo01); 
 
 pwm.setPWM( 1, 0, 280);
 pwm.setPWM( 3, 0, 220);
 pwm.setPWM( 5, 0, 220);
 delay(tiempo01); 
 
 pwm.setPWM( 0, 0, 270);
 pwm.setPWM( 2, 0, 190);
 pwm.setPWM( 4, 0, 320);
 delay(tiempo01);

 pwm.setPWM( 1, 0, 195);
 pwm.setPWM( 3, 0, 305);
 pwm.setPWM( 5, 0, 340);
 delay(tiempo01);

 pwm.setPWM( 0, 0, 170);
 pwm.setPWM( 2, 0, 280);
 pwm.setPWM( 4, 0, 210);
 delay(tiempo01);
 
 pwm.setPWM( 1, 0, 280); 
 pwm.setPWM( 3, 0, 220);
 pwm.setPWM( 5, 0, 220); 
 delay(tiempo01);

 pwm.setPWM( 0, 0, 220);
 pwm.setPWM( 2, 0, 230);
 pwm.setPWM( 4, 0, 260);
 delay(tiempo01);  
 
 pwm.setPWM( 1, 0, 495);
 pwm.setPWM( 3, 0, 305);
 pwm.setPWM( 5, 0, 340);
 delay(tiempo01); 
 
 pwm.setPWM( 6, 0, 450);
 pwm.setPWM( 7, 0, 515);
 pwm.setPWM( 8, 0, 385);
 pwm.setPWM( 9, 0, 350);
 pwm.setPWM( 10, 0, 200);
 pwm.setPWM( 11, 0, 470);
 delay(tiempo01);
 
 pwm.setPWM( 7, 0, 270);
 pwm.setPWM( 9, 0, 250);
 pwm.setPWM( 11,0, 300);
 delay(tiempo01);
 
 pwm.setPWM( 6, 0, 380);
 pwm.setPWM( 8, 0, 415);
 pwm.setPWM( 10, 0, 130);
 delay(tiempo01);
 
 pwm.setPWM( 7, 0, 515);
 pwm.setPWM( 9, 0, 350);
 pwm.setPWM( 11, 0, 470);
 delay(tiempo01);
 
 pwm.setPWM( 6, 0, 510);
 pwm.setPWM( 8, 0, 320);
 pwm.setPWM( 10, 0, 235);
 delay(tiempo01);
 
 pwm.setPWM( 7, 0, 270);
 pwm.setPWM( 9, 0, 250);
 pwm.setPWM( 11, 0, 300);
 delay(tiempo01);
 
 pwm.setPWM( 6, 0, 450);
 pwm.setPWM( 8, 0, 385);
 pwm.setPWM( 10, 0, 200);
 delay(tiempo01);
 
 pwm.setPWM( 7, 0, 515);
 pwm.setPWM( 9, 0, 350);
 pwm.setPWM( 11, 0, 470);
 delay(tiempo01);
}

void sec_home()
{
pwm.setPWM( 0, 0, 220);                                        //Servo Hombro01 en origen
 pwm.setPWM( 1, 0, 495);
 pwm.setPWM( 2, 0, 230);
 pwm.setPWM( 3, 0, 305);
 pwm.setPWM( 4, 0, 260);
 pwm.setPWM( 5, 0, 340);
 pwm.setPWM( 6, 0, 450);
 pwm.setPWM( 7, 0, 515);
 pwm.setPWM( 8, 0, 385);
 pwm.setPWM( 9, 0, 350);
 pwm.setPWM( 10, 0, 200);
 pwm.setPWM( 11, 0, 470);
 delay(tiempo01); 
 
}

void sec_atras()
{
 pwm.setPWM( 1, 0, 280);
 pwm.setPWM( 3, 0, 220);
 pwm.setPWM( 5, 0, 220);
 delay(tiempo01); 
 
 pwm.setPWM( 0, 0, 170);
 pwm.setPWM( 2, 0, 280);
 pwm.setPWM( 4, 0, 210);
 delay(tiempo01);
 
 pwm.setPWM( 1, 0, 495);
 pwm.setPWM( 3, 0, 305);
 pwm.setPWM( 5, 0, 340);
 delay(tiempo01);
 
 pwm.setPWM( 0, 0, 270);
 pwm.setPWM( 2, 0, 190);
 pwm.setPWM( 4, 0, 320);
 delay(tiempo01);
 
 pwm.setPWM( 1, 0, 280);
 pwm.setPWM( 3, 0, 220);
 pwm.setPWM( 5, 0, 220);
 delay(tiempo01); 
 
 pwm.setPWM( 0, 0, 220);
 pwm.setPWM( 2, 0, 230);
 pwm.setPWM( 4, 0, 260);
 delay(tiempo01);  

 pwm.setPWM( 1, 0, 495);
 pwm.setPWM( 3, 0, 305);
 pwm.setPWM( 5, 0, 340);
 delay(tiempo01); 
 
 
 pwm.setPWM( 7, 0, 270);
 pwm.setPWM( 9, 0, 250);
 pwm.setPWM( 11,0, 300);
 delay(tiempo01);
 
 pwm.setPWM( 6, 0, 510);
 pwm.setPWM( 8, 0, 320);
 pwm.setPWM( 10, 0, 235);
 delay(tiempo01);
 
 pwm.setPWM( 7, 0, 515);
 pwm.setPWM( 9, 0, 350);
 pwm.setPWM( 11, 0, 470);
 delay(tiempo01);
 
 pwm.setPWM( 6, 0, 380);
 pwm.setPWM( 8, 0, 415);
 pwm.setPWM( 10, 0, 130);
 delay(tiempo01);
 
 pwm.setPWM( 7, 0, 270);
 pwm.setPWM( 9, 0, 250);
 pwm.setPWM( 11,0, 300);
 delay(tiempo01);
 
 pwm.setPWM( 6, 0, 450);
 pwm.setPWM( 8, 0, 385);
 pwm.setPWM( 10, 0, 200);
 delay(tiempo01);
 
 pwm.setPWM( 7, 0, 515);
 pwm.setPWM( 9, 0, 350);
 pwm.setPWM( 11, 0, 470);
 delay(tiempo01);
}
 
 void sec_izquierda()
 {
 pwm.setPWM( 1, 0, 280);
 pwm.setPWM( 5, 0,  220);
 pwm.setPWM( 11, 0, 300);
 delay(tiempo01);
 
 pwm.setPWM( 0, 0, 270);
 pwm.setPWM( 4, 0, 320);
 delay(tiempo01);
 
 pwm.setPWM( 1, 0, 195);
 pwm.setPWM( 5, 0, 340);
 delay(tiempo01);
 
 pwm.setPWM( 0, 0, 170);
 pwm.setPWM( 4, 0, 210);
 delay(tiempo01);
 
 pwm.setPWM( 1, 0, 280);
 pwm.setPWM( 5, 0, 220); 
 delay(tiempo01); 
 
 pwm.setPWM( 0, 0, 220);
 pwm.setPWM( 4, 0, 260);
 delay(tiempo01); 
 
 pwm.setPWM( 1, 0, 495);
 pwm.setPWM( 5, 0, 340);
 pwm.setPWM( 11, 0, 470);
 delay(tiempo01);
 }
 
 void sec_derecha()
 {
  pwm.setPWM( 7, 0, 270);
  pwm.setPWM( 11, 0,300);
  pwm.setPWM( 5, 0, 220); 
 delay(tiempo01);
 
  pwm.setPWM( 6, 0, 380);
  pwm.setPWM( 10, 0, 130);
 delay(tiempo01);
 
 pwm.setPWM( 7, 0, 515); 
 pwm.setPWM( 11, 0, 470);
 delay(tiempo01);
 
pwm.setPWM( 6, 0, 510);
 pwm.setPWM( 10, 0, 235);
 delay(tiempo01);
 
 pwm.setPWM( 7, 0, 270);
 pwm.setPWM( 11, 0, 300);
 delay(tiempo01);
 
 pwm.setPWM( 6, 0, 450);
 pwm.setPWM( 10, 0, 200);
 delay(tiempo01);
 
 pwm.setPWM( 7, 0, 515);
 pwm.setPWM( 11, 0, 470);
 pwm.setPWM( 5, 0, 340);
 delay(tiempo01);
}

  void sec_picotazo()
{
  
  for(ang=130; ang>40; ang--)
      {
        cola01.write(ang);
          delay(tiempo02);
      }
   
   
  for(ang=90; ang>40; ang--)
      {
        cola02.write(ang);
          delay(tiempo02);
      }

  for(ang=70; ang<130; ang++)
      {
        cola03.write(ang);
          delay(tiempo02);
      }       
    delay(tiempo01);
    
  cola01.write(130);
  cola02.write( 90);
  cola03.write( 70);
    delay(tiempo01);
    
}

void sec_griper abierto()
 {
   pinza01.write(140); 
 } 
 
 void sec_griper cerrado()
 {
   pinza01.write(55);
 }  

/////////////////////////////////////////////////////////
// Funcion para pinza izquierda
/////////////////////////////////////////////////////////  
void sec_pinza_izq()
{
        delay(10);   
        while (Serial.available()) 
        {                  
          char lectura2 = Serial.read();  
          readString += lectura2;          
        }
        
        if (readString.length()>0) 
        {   
          //Serial.println(readString.toInt());  
          izq02.write(readString.toInt());
          readString=""; 
        }
}

/////////////////////////////////////////////////////////
// Funcion para pinza derecha
/////////////////////////////////////////////////////////  
void sec_pinza_der()
{
        delay(10);   
        while (Serial.available()) 
        {                  
          char lectura2 = Serial.read();  
          readString += lectura2;          
        }
        
        if (readString.length()>0) 
        {   
          //Serial.println(readString.toInt());  
          der03.write(readString.toInt());
          readString=""; 
        }
}



