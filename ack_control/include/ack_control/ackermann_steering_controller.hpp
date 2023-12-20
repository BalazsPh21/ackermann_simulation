#ifndef ACKERMANN_STEERING_CONTROLLER__ACKERMANN_STEERING_CONTROLLER_HPP_
#define ACKERMANN_STEERING_CONTROLLER__ACKERMANN_STEERING_CONTROLLER_HPP_

#include <memory>

#include "ackermann_steering_controller/visibility_control.h"
#include "ackermann_steering_controller_parameters.hpp"
#include "steering_controllers_library/steering_controllers_library.hpp"

namespace ackermann_steering_controller
{
// name constants for state interfaces
static constexpr size_t STATE_TRACTION_RIGHT_WHEEL = 0;
static constexpr size_t STATE_TRACTION_LEFT_WHEEL = 1;
static constexpr size_t STATE_STEER_RIGHT_WHEEL = 2;
static constexpr size_t STATE_STEER_LEFT_WHEEL = 3;

// name constants for command interfaces
static constexpr size_t CMD_TRACTION_RIGHT_WHEEL = 0;
static constexpr size_t CMD_TRACTION_LEFT_WHEEL = 1;
static constexpr size_t CMD_STEER_RIGHT_WHEEL = 2;
static constexpr size_t CMD_STEER_LEFT_WHEEL = 3;

static constexpr size_t NR_STATE_ITFS = 4;
static constexpr size_t NR_CMD_ITFS = 4;
static constexpr size_t NR_REF_ITFS = 2;

class AckermannSteeringController : public steering_controllers_library::SteeringControllersLibrary
{
public:
  AckermannSteeringController();

  ACKERMANN_STEERING_CONTROLLER__VISIBILITY_PUBLIC controller_interface::CallbackReturn
  configure_odometry() override;

  ACKERMANN_STEERING_CONTROLLER__VISIBILITY_PUBLIC bool update_odometry(
    const rclcpp::Duration & period) override;

  ACKERMANN_STEERING_CONTROLLER__VISIBILITY_PUBLIC void
  initialize_implementation_parameter_listener() override;

protected:
  std::shared_ptr<ackermann_steering_controller::ParamListener> ackermann_param_listener_;
  ackermann_steering_controller::Params ackermann_params_;
};
}  // namespace ackermann_steering_controller

#endif  // ACKERMANN_STEERING_CONTROLLER__ACKERMANN_STEERING_CONTROLLER_HPP_