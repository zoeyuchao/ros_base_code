#include<ros/ros.h>
#include<topic_demo/gps.h>   //编译后由gps.msg自动生成的头文件
#include<std_msgs/Float32.h>

void gpsCallback(const topic_demo::gps::ConstPtr &msg)
{
   std_msgs::Float32 distance;   //std::msg::Float32是一个只有一个元素data构成的结构体，此处也可用C++自带的float
   distance.data = sqrt(pow(msg->x,2) + pow(msg->y,2));
   ROS_INFO("Listener: Distance to origin = %f, state = %s", distance.data, msg->state.c_str());
}

int main(int argc, char** argv)
{
   ros::init(argc, argv, "listener");
   ros::NodeHandle nh;
   ros::Subscriber sub = nh.subscribe("gps_info", 1, gpsCallback);   //创建subscriber，第二个参数为queue_size，第三个参数为回调函数指针
   ros::spin();   //反复调用当前可触发的回调函数直至清空消息队列，没有消息时阻塞，如果只希望接收一次，使用函数ros::spinOnce()非阻塞
   
   return 0;   
}   
