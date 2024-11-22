#include "config.h"

extern void setAngle(uint8_t pin, char value);

extern char init_motors(uint8_t servo_yaw, 
                        uint8_t servo_rudder, 
                        uint8_t servo_roll, 
                        uint8_t trottle_ctrl);