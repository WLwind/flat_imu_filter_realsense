#include <flat_imu_filter_realsense/flat_world_imu_node.h>

FlatWorldImuNode::FlatWorldImuNode()
{
  bool init_result = init();
  ROS_ASSERT(init_result);
}

FlatWorldImuNode::~FlatWorldImuNode()
{
}

bool FlatWorldImuNode::init()
{
  ROS_INFO("laser_imu_node starts.");
  return true;
}

void FlatWorldImuNode::msgCallback(const sensor_msgs::ImuConstPtr imu_in)
{
  if (last_published_time_.isZero() || imu_in->header.stamp > last_published_time_)
  {
    last_published_time_ = imu_in->header.stamp;
    sensor_msgs::Imu imu_out = *imu_in;
    imu_out.header.frame_id="front_laser";
    publisher_.publish(imu_out);
  }
}

int main(int argc, char* argv[])
{
  ros::init(argc, argv, "laser_imu_node");

  FlatWorldImuNode flat_world_imu_node;

  ros::spin();

  return 0;
}
