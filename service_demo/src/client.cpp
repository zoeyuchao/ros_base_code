#include<ros/ros.h>
#include<service_demo/Greeting.h>

int main(int argc, char** argv)
{
   ros::init(argc, argv, "greetings_client");   //解析参数，命名节点
   ros::NodeHandle nh;   //创建句柄，实例化node
   ros::ServiceClient client = nh.serviceClient<service_demo::Greeting>("greetings");
   
   service_demo::Greeting srv;
   srv.request.name = "WANG";
   srv.request.age = 22;

   if(client.call(srv))   //client.call()会返回一个bool值，即在server.cpp中定义的handle_function的返回值
   {
      ROS_INFO("Feedback from server: %s", srv.response.feedback.c_str());
   }
   else
   {
      ROS_ERROR("Failed to call service greetings");
      return 1;
   }

   return 0;
}