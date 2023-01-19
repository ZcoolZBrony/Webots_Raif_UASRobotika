#include <webots/robot.h>
#include <webots/motor.h>

#define TIME_STEP 64
#define MAX_SPEED 6.28

int main(int argc, char **argv) {
  /* necessary to initialize webots stuff */
  wb_robot_init();

  // get the motor devices
  WbDeviceTag left_motor = wb_robot_get_device("left wheel motor");
  WbDeviceTag right_motor = wb_robot_get_device("right wheel motor");
  // set the target position of the motors
  // wb_motor_set_position(left_motor, 10.0);
  // wb_motor_set_position(right_motor, 10.0);
  wb_motor_set_position(left_motor, INFINITY);
  wb_motor_set_position(right_motor, INFINITY);

  // set up the motor speeds at 10% of the MAX_SPEED.
  wb_motor_set_velocity(left_motor, 0.5 * MAX_SPEED);
  wb_motor_set_velocity(right_motor, 0.5 * MAX_SPEED);
  
  while (wb_robot_step(TIME_STEP) != -1) {
  };

  /* Enter your cleanup code here */

  /* This is necessary to cleanup webots resources */
  wb_robot_cleanup();

  return 0;
}
