
#******************************
# Make file for EasyTrace
# Made by Robert Goes (2018)
#******************************

CC = g++
CFLAGS = -ggdb -Wall
MAIN_INCLUDES = util.h
MAIN_NAME = test.cpp
FILENAME = NN2
TARNAME=goes1944

.PHONY: all clean debug
#*****************************

all: clean $(FILENAME)

debug: CFLAGS += -g
debug: $(FILENAME)

clean:
	-rm -f *.o $(FILENAME) $(TARNAME).tar
#******************************
$(FILENAME): main.o $(MAIN_INCLUDES)
	$(CC) $(CFLAGS) -o $(FILENAME) main.o $(MAIN_INCLUDES)

main.o: $(MAIN_NAME)
	$(CC) $(CFLAGS) -c -o main.o $(MAIN_NAME)

tar:
	tar -cvzf $(TARNAME).tar makefile *.cpp *.h Eigen
	ls -l $(TARNAME).tar

