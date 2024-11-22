/**
 * UDF-381 UAV firmware.
 * 
 * "Written by amateurs for amateurs"
 * 
 * Product is developed for Atmega328p MCU but can be ported to another architectures as well.
 * Consider to use standart ELRS RX receiver (or tinker your own) with CSRF protocol.
 * Before uploading the firmware, double-check the config.h file.
 * Your motor's driver may be different from one we actually use, so maybe you need to find another trottle values. 
 * Please consider to test all the systems carefully before flying.
 * 
 * Active Developers:
 * @SamcraftSam
 * @abell1835IR
 * 
 * (you can become the maintainer as well!)
 * 
 * =======================================================================================================
 * This firmware is intended for use in entertaining and/or educational purposes ONLY
 * Authors are not responsible for any harm/damage/legal issues caused by using this code in your projects 
 * 
 * USE THIS SOFTWARE FOR YOUR OWN RISK 
 * =======================================================================================================
 * 
 * --------motors\ - folder with main motor/servos controlling module and handlers
 * --------rx\ - folder with CSRF decoder module
 * --------config.h - put all the macros here
 * --------fcs.ino - main file
 */

#include "receiver.h"
#include "motors.h"
#include "config.h"
#include "log.h"
#include "stdio.h"
//#include "Serial.h" 

void setup()
{
    Serial.begin(115200); /* may be uncompatible with second UART initialization (RX)*/
    //Serial.flush();
    printf_begin();
    Serial.println("text");
    LOGV("%s","Starting initialization of the hardware!...");

    char receiver_flag = init_receiver(CSRF_TX, CSRF_RX);
    char motors_flag   = init_motors(SERVO_YAW, SERVO_PITCH, SERVO_ROLL, MOTOR_CTRL);

    if (receiver_flag != FLAG_OK)
    {
        LOGE("Receiver initialization failed, error code: %3i", receiver_flag);       
        while(1) {} /* loop until the device's reset*/
    }
    else
    {
        LOGI("Receiver is OK...");
    }
    if (motors_flag != FLAG_OK)
    {
        LOGE("Motors initialization failed, error code: %3i", motors_flag);       
        while(1) {} 
    }
    else
    {
        LOGI("Motors are OK...");
    }

    char pairing_status = receiver_wait2pair(PAIRING_TIMEOUT_S);

    if (pairing_status != FLAG_OK || pairing_status != FLAG_PAIRING_TIMEOUT)
    {
        LOGE("Receiver pairing failed, error code: %3i", motors_flag);       
        while(1) {} 
    }
    else if (pairing_status == FLAG_PAIRING_TIMEOUT)
    {
        LOGW("Packet timeout reached! Check your remote, then reset the system!");
        while(1) {}
    }
    else
    {
        LOGI("Device connected!");
    }
}

void loop()
{
    //TODO actual code here
}

int serial_putc(char c, FILE *) 
{
  Serial.write(c);

  return c;
} 

void printf_begin(void)
{
  fdevopen(&serial_putc, 0);
}