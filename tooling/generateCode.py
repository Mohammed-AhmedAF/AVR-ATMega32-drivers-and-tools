#first tooling in python

func = "DIO_vidSetPinValue(DIO_PORT"
cont = list()
fhandle = open("conf.txt",'r')
out = open("code.txt",'w')
for line in fhandle:
    if (line.startswith('A') | line.startswith('B') | line.startswith('C') | line.startswith('D')):
        cont = line.split();
        if (cont[2] == 'output'):
            dir = 1
        else:
            dir = 0
        out.write(func+cont[0]+','+cont[1]+','+str(dir)+')\n')
fhandle.close()
out.close()
