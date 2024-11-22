#include "config.h"
#include "Servo.h"

Servo servoYaw;
Servo servoRud;
Servo servoRol;
Servo throttle;

void setAngle(uint8_t pin, char value)
{
  if (pin = SERVO_YAW)
  {
    servoYaw.write(value);
  }
  else if (pin == SERVO_ROLL)
  {
    servoRol.write(value);
  }
  else if (pin == SERVO_PITCH)
  {
    servoRud.write(value);
  }
  else if (pin == MOTOR_CTRL)
  {
    throttle.write(value);
  }
}

char init_motors(uint8_t servo_yaw, uint8_t servo_rudder, uint8_t servo_roll, uint8_t trottle_ctrl)
{
  servoYaw.attach();
  servoRud.attach();
  servoRol.attach();
  throttle.attach();

  throttle.write(THROTTLE_ZERO);
  servoYaw.write(YAW_NORMAL);
  servoRud.write(RUD_NORMAL);
  servoRol.write(ROLL_NORMAL);

  return FLAG_OK;
}