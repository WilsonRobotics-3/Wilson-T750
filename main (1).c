#include <kipr/wombat.h>
void move(int a,int b,int c);// int a is port 1 and 0 is right
void ap(int d,int e);// ap stands for arm position
int main()
{
    int rsensor = 0; //right sensor is port 0
	int lsensor = 4; //left sensor is port 4
    
    enable_servos();
	
    //starting position of the arm
    set_servo_position(1,869);
    wait_for_milliseconds(500);
    
    //move the RED and GREEN cubes out of the Sample Isolation
    move(100,30,1220);//towards the sample isolation
    move(20,100,1000);//turns a very sharp left
    move(0,92,1520);//even more to the left
    move(100,100,696);//goes fowards to put the RED and GREEN cubes on to the side
    move(-99,-100,350);// Goes backwards
    move(-96,98,1996);//turns to align itself to the black and white line
    move(100,100,1000);//goes foward for 1 second (1000 milliseconds)
    
      //line follow coding to get the poms and then return
    while (((analog(rsensor)) < 1700) && ((analog(lsensor) > 500)))//port 1 is left and port 0 is right
    {
        motor(0,97);
        motor(1,100);
    }
    
    
  
          return 0;

}
void move(int a,int b,int c)
{
    motor(1,a);
    motor(0,b);
    msleep(c);
}
void ap(int d,int e)
{
    enable_servos();
    set_servo_position(1,d);
    msleep(e);
}