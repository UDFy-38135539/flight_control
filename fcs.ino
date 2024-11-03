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
 * @Aldik314
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

#include "rx/receiver.h"
#include "motors/motors.h"

void setup()
{
    //TODO init stuff here
}

void loop()
{
    //TODO actual code here
}