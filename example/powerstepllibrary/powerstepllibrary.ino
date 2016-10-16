#include <powerstep.h>

PowerStep stepper(10);
PowerStep stepper2(9);

#define ss1     10
#define ss2     9 



void setup() {
 Serial.begin(9600);

 initSpi();
 initStepper1();
 initStepper2();
  
}

void loop(){  
 
  
  stepper2.goTo(2000000);
  stepper.run(1,2000);
  while(stepper2.isBusy()==0){  //when stepper2 reached its postiion stepper 1 turn in the otherside
    stepper.run(0,2000);
  }

}

void initSpi()
{

  
  pinMode(MOSI, OUTPUT);
  pinMode(MISO, INPUT);
  pinMode(SCK, OUTPUT);
  pinMode(RESET, OUTPUT);
  pinMode(ss1, OUTPUT);
  pinMode(ss2,OUTPUT);
  
  digitalWrite(RESET, HIGH);
  delay(10);
  digitalWrite(RESET, LOW);
  delay(10);
  digitalWrite(RESET, HIGH);
  delay(10);

  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.setClockDivider(SPI_CLOCK_DIV4); // or 2, 8, 16, 32, 64
  SPI.setDataMode(SPI_MODE3);
  
}

void initStepper1()
{

  stepper.SetParam(KVAL_RUN, 255);
  stepper.SetParam(KVAL_ACC, 255);
  stepper.SetParam(KVAL_DEC, 255);

  
  stepper.SetParam(CONFIG, CONFIG_PWM_DIV_2 | CONFIG_PWM_MUL_2 | UVLOVAL0| VCCVAL0 | CONFIG_OC_SD_DISABLE | CONFIG_VS_COMP_DISABLE | CONFIG_SW_HARD_STOP | CONFIG_INT_16MHZ);

  stepper.SetParam(KVAL_RUN, 0xFF);
 
  stepper.getStatus();

  stepper.hardStop(); //engage motors

  stepper.setAcc(100); //set acceleration
  stepper.setMaxSpeed(800);
  
  
  
  stepper.setMinSpeed(1);
  stepper.setMicroSteps(8); //1,2,4,8,16,32,64 or 128
  stepper.setThresholdSpeed(1000);
  stepper.setOverCurrent(3000); //set overcurrent protection
  stepper.setStallCurrent(3000);
}

void initStepper2()
{

  stepper2.SetParam(KVAL_RUN, 255);
  stepper2.SetParam(KVAL_ACC, 255);
  stepper2.SetParam(KVAL_DEC, 255);

  
  stepper2.SetParam(CONFIG, CONFIG_PWM_DIV_2 | CONFIG_PWM_MUL_2 | UVLOVAL0| VCCVAL0 | CONFIG_OC_SD_DISABLE | CONFIG_VS_COMP_DISABLE | CONFIG_SW_HARD_STOP | CONFIG_INT_16MHZ);

  stepper2.SetParam(KVAL_RUN, 0xFF);
 
  stepper2.getStatus();

  stepper2.hardStop(); //engage motors


 
 
  
 
  stepper2.setAcc(100); //set acceleration
  stepper2.setMaxSpeed(1600);
  
  
  
  stepper2.setMinSpeed(1);
  stepper2.setMicroSteps(8); //1,2,4,8,16,32,64 or 128
  stepper2.setThresholdSpeed(1000);
  stepper2.setOverCurrent(3000); //set overcurrent protection
  stepper2.setStallCurrent(3000);

  
}


