
OBJ 	 = 	application/core/main.c application/core/startup/startup.c 	
CRTED	 =  build/main.o build/startup.o
LDSCRIPT =	application/core/linker/link.ld
LOADPATH =  D:\Embedded\env\STM32mx\bin\STM32_Programmer_CLI.exe
SRC		 =  D:\Embedded\EmbeddedLab-Stack\build\firmware.elf
# USE VARIABLR REPLACE LINK RUN
CC = arm-none-eabi-gcc 
CFLAGS = -mcpu=cortex-m3 -mthumb
CONDITION = -nostdlib -nostartfiles

all : build/firmware.elf flash

build/firmware.elf : $(CRTED) $(LDSCRIPT)
	$(CC) $(CFLAG) $(CRTED) -T $(LDSCRIPT) -o $@ $(CONDITION)

build/main.o : application/core/main.c
	$(CC) -c $(CFLAG) application/core/main.c -o $@

build/startup.o : application/core/startup/startup.c
	$(CC) -c $(CFLAG) application/core/startup/startup.c -o $@

flash : build/firmware.elf
	$(LOADPATH) -c port=SWD freq=4000 -d $(SRC) 0x08000000 -v -rst -y
clean : 
	rm -f build/*.*