#include<ros/ros.h>
#include<topic_demo/gps.h>

int main(int argc, char** argv)
{
   ros::init(argc, argv, "talker");   //解析参数，命名节点
   ros::NodeHandle nh;   //创建句柄

   topic_demo::gps msg;   //创建gps消息
   msg.x = 1.0;
   msg.y = 1.0;
   msg.state = "working";

   ros::Publisher pub = nh.advertise<topic_demo::gps>("gps_info", 1);   //创建publisher，第二个参数为queue_size

   ros::Rate loop_rate(1.0);   //定义循环发布的频率，1Hz
   while(ros::ok()){
      msg.x = 1.03 * msg.x;
      msg.y = 1.01 * msg.y;
      ROS_INFO("Talker: GPS: x = %f, y = %f", msg.x, msg.y);   //ROS_INFO类似于print
      pub.publish(msg);   //发布消息
      loop_rate.sleep();   //根据定义的发布频率sleep
   }
   return 0;
}
