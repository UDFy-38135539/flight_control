# flight_control
Firmware for the UDFy-381* RC Plane Flight controller chip. Hardware is based on Atmega328p MCU and generic ELRS Receiver. Designed for FPV hobbyists and RC planes modelling enthusiasts. 

# Hardware
    //TODO

# Structure
 * hw\ - Hardware blueprints, images, PCB's (not a part of the firmware)
 * motors\ - folder with main motor/servos controlling module and handlers
 * rx\ - folder with CSRF decoder module
 * config.h - put all the macros here
 * fcs.ino - main file

# Dependencies
If using external Arduino libraries (not the standart ones like "Serial" or "Servo"), add them in the list below:
  * - 
