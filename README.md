# AVR ATMega32 drivers and tools
Personal repository of all C activities I did during embedded software course in IMT School.

The lib directory contains drivers for various components inside the AVR ATmega32 (also working with ATMega16), like timers, interrupts, ADC, and DIO, along with drivers for character LCD, RTC, External EEPROM and other components. The drivers have been built during and mostly after taking the diploma. Also, in this directory you will find a Makefile that is used to build code into executables that run on the MCU. The makefile contains a rule to upload the executable to the MCU too.

This repo also contains a template of FreeRTOS to the AVR ATMega32 MCU.

## Useful note
In the tooling directory, you will find `get-avr` and `setup-avr-project`. These two bash scripts can be used to start a new project, provided that you put the whole parent directory containing lib in a directory called programming; or change the script if you put the parent directory in a different directory.
