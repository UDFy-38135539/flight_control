/**
 * UDF-381 UAV config file.
 * 
 * All the "magic numbers", configuration/calculation values, precalculated units MUST BE HERE
 * Maintainer should shortly describe the purpose of the macro. 
 * 
 * 
 * DO NOT change values of the CONFIG MACROS unless you know what you are doing!
 *                                    (e.g. configuring throttle values for compatibillity with your motor driver)
 * DO NOT change values of the SYSTEM MACROS unless you REALLY know what you are doing!
 *                                    (e.g. you are porting the firmware to another chip rn) 
 * 
 */


/** ============================================================================================
 *                                         CONFIG MACROS
 *  ============================================================================================ */

//TODO

/** ============================================================================================
 *                                         SYSTEM MACROS
 *  ============================================================================================ */

#define MOTOR_CTRL    0//TODO Motor ctrl pin
#define SERVO_PITCH   0//TODO pin for the elevator servo
#define SERVO_YAW     0//TODO pin for the rudder servo
#define SERVO_ROLL    0//TODO pin for the aileron servo

#define CSRF_TX       0//TODO USART TX FOR RECEIVER
#define CSRF_RX       0//TODO USART RX FOR RECEIVER

/* Time to wait for the packet frames from the RX*/
#define PAIRING_TIMEOUT_S 60

/* STATUS FLAGS (CODES) */
#define FLAG_OK              0b00000000
#define FLAG_ERR_UNKN        0b11111111
#define FLAG_PAIRING_TIMEOUT 0b10000000

//TODO