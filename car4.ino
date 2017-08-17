#include <AFMotor.h>
int mspeed=150; //設置速度
int sspeed=50;  //設置初始速度

/*AF_DCMotor motorname(portnum,freq)
这是一个建立一个直流电机的函数。在程序中需要声明每个电机各一次。像下面的例子中一样，每个电机必须使用不同的名字。
参数：
port num - 选择你的电机连接到电机驱动板上的接口（1-4）
freq - 选择PWM频率。如果你没有选择这个选项，默认设置为1KHZ。
适用于通道1和2的频率：
MOTOR12_64KHZ
MOTOR12_8KHZ
MOTOR12_2KHZ
MOTOR12_1KHZ
适用于通道3和4的频率：
MOTOR34_64KHZ
MOTOR34_8KHZ
MOTOR34_1KHZ
注意：更高的频率会减小电机在运动过程中的噪音，但同时也会降低扭矩。
*/

AF_DCMotor m1(1);
AF_DCMotor m2(2);
AF_DCMotor m3(3);
AF_DCMotor m4(4);

void setup() {
  /*Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");*/

  // turn on motor

/*
 setSpeed(speed)
设置电机的速度
参数：
speed-范围为0到255，0代表停止，255代表全速。
注意：直流电机的回馈并不是典型线性的，所以真正的转速并不会与程序中设定的速度成正比。
 */

  m1.setSpeed(sspeed);
  m2.setSpeed(sspeed);
  m3.setSpeed(sspeed);
  m4.setSpeed(sspeed);

/*
 *run(cmd)
设置电机的运转模式
参数：
cmd - 选择你想要的电机运转模式
可选择的模式：
FORWARD - 正转（真正的转动方向取决于你电机的连线）
BACKWARD - 反转 （转动方向与正转相反）
RELEASE - 停止。使电机断电，与setSpeed(0)函数功能相同。调用了这个函数后，电机需要一定时间才能彻底停止。
 */
 
  m1.run(RELEASE);
  m2.run(RELEASE);
  m3.run(RELEASE);
  m4.run(RELEASE);
}

void loop() {
  uint8_t i;
  
  //Serial.print("tick");
  
  m1.run(FORWARD);
  m2.run(FORWARD);
  m3.run(FORWARD);
  m4.run(FORWARD);
  for (i=0; i<mspeed; i++) {
    m1.setSpeed(i); 
    m2.setSpeed(i); 
    m3.setSpeed(i); 
    m4.setSpeed(i); 
    delay(10);
 }
 
  for (i=mspeed; i!=0; i--) {
    m1.setSpeed(i); 
    m2.setSpeed(i); 
    m3.setSpeed(i); 
    m4.setSpeed(i); 
    delay(10);
 }
 delay(1000);
  
  //Serial.print("tock");

  m1.run(BACKWARD);
  m2.run(BACKWARD);
  m3.run(FORWARD);
  m4.run(FORWARD);
  for (i=0; i<mspeed; i++) {
    m1.setSpeed(i); 
    m2.setSpeed(i); 
    m3.setSpeed(i); 
    m4.setSpeed(i);  
    delay(10);
 }
 
  for (i=mspeed; i!=0; i--) {
    m1.setSpeed(i); 
    m2.setSpeed(i); 
    m3.setSpeed(i); 
    m4.setSpeed(i);  
    delay(10);
 }

 /* m1.run(BACKWARD);
  m2.run(BACKWARD);
  m3.run(BACKWARD);
  m4.run(BACKWARD);
  for (i=0; i<mspeed; i++) {
    m1.setSpeed(i); 
    m2.setSpeed(i); 
    m3.setSpeed(i); 
    m4.setSpeed(i);  
    delay(10);
 }
 
  for (i=mspeed; i!=0; i--) {
    m1.setSpeed(i); 
    m2.setSpeed(i); 
    m3.setSpeed(i); 
    m4.setSpeed(i);  
    delay(10);
 }
  

  //Serial.print("tech");
  m1.run(RELEASE);
  m2.run(RELEASE);
  m3.run(RELEASE);
  m4.run(RELEASE);*/
  delay(1000);
}
