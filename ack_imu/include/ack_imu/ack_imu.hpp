#ifndef IMU_SENSOR_BROADCASTER__IMU_SENSOR_BROADCASTER_HPP_
#define IMU_SENSOR_BROADCASTER__IMU_SENSOR_BROADCASTER_HPP_

#include <memory>
#include <string>
#include <vector>

#include "controller_interface/controller_interface.hpp"
#include "imu_sensor_broadcaster/visibility_control.h"
// auto-generated by generate_parameter_library
#include "imu_sensor_broadcaster_parameters.hpp"
#include "rclcpp_lifecycle/node_interfaces/lifecycle_node_interface.hpp"
#include "rclcpp_lifecycle/state.hpp"
#include "realtime_tools/realtime_publisher.h"
#include "semantic_components/imu_sensor.hpp"
#include "sensor_msgs/msg/imu.hpp"

namespace imu_sensor_broadcaster
{
class IMUSensorBroadcaster : public controller_interface::ControllerInterface
{
public:
  IMU_SENSOR_BROADCASTER_PUBLIC
  controller_interface::InterfaceConfiguration command_interface_configuration() const override;

  IMU_SENSOR_BROADCASTER_PUBLIC
  controller_interface::InterfaceConfiguration state_interface_configuration() const override;

  IMU_SENSOR_BROADCASTER_PUBLIC controller_interface::CallbackReturn on_init() override;

  IMU_SENSOR_BROADCASTER_PUBLIC
  controller_interface::CallbackReturn on_configure(
    const rclcpp_lifecycle::State & previous_state) override;

  IMU_SENSOR_BROADCASTER_PUBLIC
  controller_interface::CallbackReturn on_activate(
    const rclcpp_lifecycle::State & previous_state) override;

  IMU_SENSOR_BROADCASTER_PUBLIC
  controller_interface::CallbackReturn on_deactivate(
    const rclcpp_lifecycle::State & previous_state) override;

  IMU_SENSOR_BROADCASTER_PUBLIC
  controller_interface::return_type update(
    const rclcpp::Time & time, const rclcpp::Duration & period) override;

protected:
  std::shared_ptr<ParamListener> param_listener_;
  Params params_;

  std::unique_ptr<semantic_components::IMUSensor> imu_sensor_;

  using StatePublisher = realtime_tools::RealtimePublisher<sensor_msgs::msg::Imu>;
  rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr sensor_state_publisher_;
  std::unique_ptr<StatePublisher> realtime_publisher_;
};

}  // namespace imu_sensor_broadcaster

#endif  // IMU_SENSOR_BROADCASTER__IMU_SENSOR_BROADCASTER_HPP_