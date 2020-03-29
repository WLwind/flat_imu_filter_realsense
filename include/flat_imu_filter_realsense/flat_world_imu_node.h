#pragma once

#include <ros/ros.h>
#include <sensor_msgs/Imu.h>

#define GRAVITY 9.80665

class FlatWorldImuNode
{
 public:
  FlatWorldImuNode();
  ~FlatWorldImuNode();
  bool init();

 private:
  ros::NodeHandle nh_;
  ros::Time last_published_time_{0.0};
  ros::Publisher publisher_{nh_.advertise<sensor_msgs::Imu>("imu_out", 10)};
  ros::Subscriber subscriber_{nh_.subscribe("imu_in", 150, &FlatWorldImuNode::msgCallback, this)};
  void msgCallback(const sensor_msgs::ImuConstPtr imu_in);
};
