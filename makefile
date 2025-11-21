
OBJ 	 = 	application/core/main.c application/core/startup/startup.c 	
CRTED	 =  build/main.o build/startup.o
LDSCRIPT =	application/core/linker/link.ld

# USE VARIABLR REPLACE LINK RUN
CC = arm-none-eabi-gcc 
CFLAG = -mcpu=cortex-m3 -mthumb
CONDITION = -nostdlib -nostartfiles

all : build/firmware.elf

build/firmware.elf : $(CRTED) $(LDSCRIPT)
	$(CC) $(CFLAG) $(CRTED) -T $(LDSCRIPT) -o $@ $(CONDITION)

build/main.o : application/core/main.c
	$(CC) -c $(CFLAG) application/core/main.c -o $@

build/startup.o : application/core/startup/startup.c
	$(CC) -c $(CFLAG) application/core/startup/startup.c -o $@


clean : 
	rm -f build/*.o