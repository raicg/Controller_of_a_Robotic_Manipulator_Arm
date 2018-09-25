EXEC	= demo
CXX	= gcc
MAIN	= demo.c
OPTIONS	= -O3 -Wall
LIBS	= -lufrn_lynx -lm

main:	clean
	$(CXX) $(OPTIONS) $(MAIN) -I./include/ -L./lib/ $(LIBS) -o $(EXEC)
	sudo chmod 777 /dev/ttyS0
	sudo rm /dev/ttyS0
	sudo ln -s /dev/ttyUSB0 /dev/ttyS0
clean:
	clear
	rm -f include/*~
	rm -f lib/*~
	rm -f *~

