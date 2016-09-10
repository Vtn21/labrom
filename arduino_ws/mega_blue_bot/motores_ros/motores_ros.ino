#include <ros.h>
#include <std_msgs/Int16.h>

#define motorL1 5
#define motorL2 6
#define motorR1 9
#define motorR2 10

ros::NodeHandle node;

void callbackL(const std_msgs::Int16 &msgL) {
  if(msgL.data >= 0) {
    analogWrite(motorL1, msgL.data);
    digitalWrite(motorL2, 0);
  }
  else { 
    analogWrite(motorL2, -msgL.data);
    digitalWrite(motorL1, 0);
  }
} 

void callbackR(const std_msgs::Int16 &msgR) {
  if(msgR.data >= 0) {
    analogWrite(motorR1, msgR.data);
    digitalWrite(motorR2, 0);
  }
  else { 
    analogWrite(motorR2, -msgR.data);
    digitalWrite(motorR1, 0);
  }
} 

ros::Subscriber<std_msgs::Int16> subL("mega_blue_bot/speedL", &callbackL);
ros::Subscriber<std_msgs::Int16> subR("mega_blue_bot/speedR", &callbackR);

void setup() {
  pinMode(motorL1, OUTPUT);
  pinMode(motorL2, OUTPUT);
  pinMode(motorR1, OUTPUT);
  pinMode(motorR2, OUTPUT);
  node.initNode();
  node.subscribe(subL);
  node.subscribe(subR);
}

void loop() {
  node.spinOnce(); 
}
