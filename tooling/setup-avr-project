
#!/usr/bin/env bash

#Setup directory for avr atmega projects
#Author: Mohammed Ahmed

#Creating project directories
mkdir APP &> /dev/null
mkdir HAL &> /dev/null
mkdir MCAL &> /dev/null
mkdir UTIL &> /dev/null

#Getting files for drivers library
get-avr main std macros makef dio timer0 adc interrupts syscntrl uart twi lcd rtc keypad settings eeprom makef-layered 

#Moving files to their suitable directories

#Moving MCAL drivers to directory MCAL
mv DIO* ./MCAL
mv TIMER0* ./MCAL
mv INTERRUPTS* ./MCAL
mv UART* ./MCAL
mv TWI* ./MCAL
mv ADC* ./MCAL
mv SYSCNTRL* ./MCAL
mv SETTINGS* ./MCAL

rm Makefile
mv Makefile-layered Makefile

#Moving HAL drivers to directory HAL
mv LCD* ./HAL
mv RTC* ./HAL
mv KEYPAD* ./HAL
mv EEPROM_EXTERNAL_* ./HAL

#Moving UTIL drivers io directory UTIL
mv Std_Types.h ./UTIL
mv Macros.h ./UTIL
mv SERVICES* ./UTIL

#Moving APP drivers to diretory APP
mv main.c ./APP

