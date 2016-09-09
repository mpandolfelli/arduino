// defino las teclas
#define keyUp     'w'
#define keyDown   's'
#define keyLeft   'a'
#define keyRight  'd'

//Motor traccion
int IN3 = 5; 
int IN4 = 4;

//Motor doblar
int IN1 = ;
int IN2 = ;

void left()
{
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  delay(200);
  digitalWrite (IN2, LOW);
}

void right()
{
  digitalWrite (IN2, LOW);
  digitalWrite (IN1, HIGH);
  delay(200);
  digitalWrite (IN1, LOW);
}


void forward()
{
  digitalWrite (IN4, LOW);
  digitalWrite (IN3, HIGH);
  delay(200);
  digitalWrite (IN3, LOW);
}

void backward()
{
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  delay(200);
  digitalWrite (IN4, LOW);
}

void setup()
{
  // configurar el pin 13 como pin de salida
  //pinMode(pinLED, OUTPUT);
  // abrir la comunicacion serial a 9600 bps
  Serial.begin(9600);
}

void loop()
{
  // si hay bytes en el buffer
  if (Serial.available() > 0)
  {
    byte lectura = Serial.read();
        //lectura = lectura.toUpperCase();
    
    // si se presiona la letra W muevo hacia adelante
    if (lectura == keyUp)
    {
      //digitalWrite(pinLED, HIGH);
      Serial.write(lectura);
      forward();
      Serial.write(lectura);     
    }
    else if (lectura == keyDown)// si se presiona la S muevo hacia atras
      {
        //digitalWrite(pinLED, LOW);
        Serial.write(lectura);
        backward();
        Serial.write(lectura);

      }else if(lectura == keyLeft)// si se presiona la A muevo hacia la izquierda
      {
        Serial.write(lectura);
        left();
        Serial.write(lectura);

      }else if(lectura == keyRight)// si se presiona la D muevo hacia la derecha
      {
        Serial.write(lectura);
        right();
        Serial.write(lectura);
      }
      else
      {
        Serial.print("Lectura incorrecta.");
      }
    
  }
  
}
