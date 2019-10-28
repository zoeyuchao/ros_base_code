#include<ros/ros.h>
#include<service_demo/Greeting.h>

bool handle_function(service_demo::Greeting::Request &req, service_demo::Greeting::Response &res)   //编译后srv文件自动生成了req和res
{
   ROS_INFO("Request from %s with age %d.", req.name.c_str(), req.age);   //显示请求者信息
   res.feedback = "Hi," + req.name + ". I'm server!";   //处理请求，将结果写入feedback
   
   return true;   //返回true表示正确处理了请求
}

int main(int argc, char** argv)
{
   ros::init(argc, argv, "greetings_server");   //解析参数，命名节点
   ros::NodeHandle nh;   //创建句柄，实例化node
   ros::ServiceServer service = nh.advertiseService("greetings", handle_function);   //提供服务，handle_function为具体提供service的函数
   ros::spin();

   return 0;
}
   

