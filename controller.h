#ifndef CONTROLLER_H

#define CONTROLLER_H

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <std_msgs/Empty.h>
#include <ardrone_autonomy/Navdata.h>
#include <geometry_msgs/Twist.h>
#include <cv.h>
#include <highgui.h>
using namespace std;
using namespace cv;

namespace controller{
	class Controller
	{
		public:
			Controller();
			void takeoff();
			void reset();
            void init();
			void land();
			void control(double dt);
			void wait(double tid);
			void update_state(Point2f center);
			void auto_hover();


		//private:
			ros::NodeHandle node;
  			ros::Publisher pub_empty_land;
			ros::Publisher pub_twist;
			ros::Publisher pub_empty_takeoff;
			ros::Publisher pub_empty_reset;
			ros::Subscriber nav_sub;
			geometry_msgs::Twist twist_msg;
			geometry_msgs::Twist twist_msg_hover;
			geometry_msgs::Twist twist_msg_pshover;
			std_msgs::Empty emp_msg;
			ardrone_autonomy::Navdata msg_in_global;
			vector<double> previous_error;
  			vector<double> error;
  			vector<double> output;
  			vector<double> derivative;
  			vector<double> integral;
  			vector<double> target;
			vector<double> Kp;
			vector<double> Ki;
			vector<double> Kd;
			vector<double> measured;
			void nav_callback(const ardrone_autonomy::Navdata& msg_in);
        
            double getPosX(int pixErrorX);
            double getPosY(int pixErrorY);
	};
}

#endif