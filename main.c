#include <kipr/wombat.h>
void move(int a, int b, int c);
void ap(int d,int e); 

int main()
{
    
    create_connect();
    enable_servos();
    //starting postions for servos
    ap(0,334);
    wait_for_milliseconds(1000);
    ap(2,2047);
    msleep(1000);
    
    //grabs ring set
    ap(0,1755);
    msleep(1000);
    ap(2,1252);
    msleep(1000);


    //backwards towards the pole
    move(-100,-100,1000);
    move(-100,100,300);
    move(-250,-260,2950);
    move(100,-100,440);
    move(-150,-150,3150);
    move(-85,85,975);
    move(75,75,1700);
    
    
    //letting go of the ring set
    ap(2,2047);
    wait_for_milliseconds(1000);
    move(0,0,1000);
    wait_for_milliseconds(1000);
    
    
    //grab the RED and ORANGE rings and put them in the pole
    ap(0,1280);
    wait_for_milliseconds(1000);
    wait_for_milliseconds(1000);
    ap(2,1755);
    wait_for_milliseconds(1000);
    ap(0,600);
    wait_for_milliseconds(1000);
    ap(0,900);
    
    wait_for_milliseconds(1000);
    ap(2,1230);

    
    return(0);
}
void move(int a, int b, int c)
    
{
    create_drive_direct(a,b);
    msleep(c);
}
void ap(int d,int e)
{
    set_servo_position(d,e);
}
