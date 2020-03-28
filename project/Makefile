COMMON_OBJECTS 	=

CPU 		= msp430g2553

CFLAGS		= -mmcu=${CPU} -I../project/h

LDFLAGS		= -L/opt/ti/msp430_gcc/include



CC		= msp430-elf-gcc

AS		= msp430-elf-as



all:
	(cd /home/student/arch1-project2-lmartinez50/project/timerLib; make install)

	(cd /home/student/arch1-project2-lmartinez50/project/lcdLib; make install)

	(cd /home/student/arch1-project2-lmartinez50/project; make project2.elf)



project2.elf: ${COMMON_OBJECTS} buzzer.o p2_interrupt_handler.o stateMachines.o led.o switches.o main.o ../project/lib/libTimer.a ../project/lib/libLcd.a

	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^



load: project2.elf

	msp430loader.sh project2.elf



clean:

	rm -f *.o *.elf

	rm -rf lib h
