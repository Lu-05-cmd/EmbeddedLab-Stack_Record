
OBJ 	 = 	application/core/main.c application/core/startup/startup.c 	
LDSCRIPT =	application/core/linker/link.ld

# USE VARIABLR REPLACE LINK RUN
CC = arm-none-eabi-gcc 
CFLAG = -mcpu=cortex-m3 -mthumb
CONDITION = -nostdlib -nostartfiles

# 
all : build/firmware.elf

build/firmware.elf : $(OBJ) $(LDSCRIPT)
	$(CC) $(CFLAG) build/startup.o build/main.o -T $(LDSCRIPT) -o build/firmware.elf $(CONDITION)

build/startup.o : application/core/startup/startup.c
	$(CC) -c $(CFLAG) application/core/startup/startup.c -o build/startup.o
build/main.o : application/core/main.c
	$(CC) -c $(CFLAG) application/core/main.c -o build/main.o


clean : 
	rm -f build/*.o