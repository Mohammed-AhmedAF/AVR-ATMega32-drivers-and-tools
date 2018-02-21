# A script to count the number of clock cycles an ISR will take to execute
# Author: Mohamed Ahmed
# Date: 20 Feb 2018
import os
cmd = 'avr-objdump -d -mavr main.o --prefix-addresses >> dump.txt'
os.system(cmd)

clkCycles = 0;
i = 1
dump_rows = list()
commands = list()
fHandler = open("dump.txt",'r')
tempFhandler = open("instr.txt",'a')
for line in fHandler:
    if line.startswith("00"):
        section = line.split()[1]
        if (section.find("<__vector_10") != -1):
            commands.append(line.split()[2])

instructions = set(commands)
instructions = sorted(instructions)
for command in instructions:
    i = i + 1
    print(command)
    if (command== "adiw"):
        clkCycles += 2
    elif (command == "brne"):
        clkCycles += 2
    elif (command == "cp"):
        clkCycles += 1
    elif (command == "cpc"):
        clkCycles += 1
    elif (command == "eor"):
        clkCycles += 1
    elif (command == "in"):
        clkCycles += 1
    elif (command == "ldi"):
        clkCycles += 1
    elif (command == "lds"):
        clkCycles += 2
    elif (command == "movw"):
        clkCycles += 1
    elif (command == "nop"):
        clkCycles += 1
    elif (command == "pop"):
        clkCycles += 2
    elif (command == "push"):
        clkCycles += 2
    elif (command == "reti"):
        clkCycles += 4
    elif (command == "st"):
        clkCycles += 2
    elif (command == "sts"):
        clkCycles += 2
    else:
        clkCycles += 1

print(clkCycles)
