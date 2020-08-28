
#!/usr/bin/env bash

#Setup directory for avr atmega projects
#Author: Mohammed Ahmed

#Creating project directories
mkdir APP &> /dev/null
mkdir HAL &> /dev/null
mkdir MCAL &> /dev/null
mkdir UTIL &> /dev/null

#Getting files for drivers library
get-avr makef dio timer0 adc interrupts syscntrl uart twi lcd rtc keypad settings makef-layered

#Moving files to their suitable directories
mv DIO* ./MCAL
mv TIMER0* ./MCAL
mv INTERRUPTS* ./MCAL
mv UART* ./MCAL
mv TWI* ./MCAL
mv ADC* ./MCAL
mv SYSCNTRL* ./MCAL
mv SETTINGS* ./MCAL

mv Std_Types.h ./SERVICES
mv Macros.h ./SERVICES


rm Makefile
mv Makefile-layered Makefile

mv LCD* ./HAL
mv RTC* ./HAL
mv KEYPAD* ./HAL
mv SERVICES* ./UTIL
