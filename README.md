HDD-Laser-Shutter
=================

This project is to create a laser shutter made out of a hdd read head. It is based on the indestructables article http://www.instructables.com/id/DIY-Laser-Shutter/

Parts
------------------
*1x Ardumoto  
*1x Ardunio Leonardo  
*1x HDD head from a western digital HDD  
*1x 9 volt power supply  

Method
------------------
### HDD head
The doner HDD was disassembled and the base plate was cut to remove excess material from around the bracket holding the magnets and pivot point. The electronics for the HDD were also removed from the head and new leads soldered on. It may be preferable to leave the original leads for the motor attached. The head and magnets were then resassembled onto the base plate.

### Arduino
The Arduino was connected to an Ardumoto sheild and connected to the HDD head. The voltage to drive the motor was 9 volts. The code used on the Arduino is based on examples from Sparkfun.
