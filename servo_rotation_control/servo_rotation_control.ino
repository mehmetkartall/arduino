#include <Servo.h>
Servo sg90; 
int pos = 35; 
void setup() 
{
sg90.attach(13);
}
void loop()
{


sg90.write(pos);

}