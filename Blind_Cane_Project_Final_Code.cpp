#include "mbed.h"
#include "HCSR04.h"
Serial pc(USBTX,USBRX);
Serial device(PTC17,NC);

DigitalOut buzzer(D10);
DigitalIn button(D11);

int main()
{ 
bool value=false;
pc.baud(115200);
device.baud(115200);

HCSR04 sensor(D8,D9);
int cnt = 0;
while(1)
{
if(button)
{

while(button)
{
long a = sensor.distance(CM);
pc.printf("Distance=%d \r\n",a);
wait(1);

if(sensor.distance(CM)<=15)
{
pc.printf("WATCH OUT!\n");
buzzer=1;
wait(2);
buzzer=0;
wait(1);
}
if(sensor.distance(CM)>15 && sensor.distance(CM)<=25)
{
pc.printf("OBJECT DETECTED\n");
buzzer=1;
wait(0.2);
buzzer=0;
wait(0.2);
buzzer=1;
wait(0.2);
buzzer=0;
wait(0.2);
buzzer=1;
wait(0.2);
buzzer=0;
wait(0.2);
}
}
}
}
}