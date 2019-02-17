


# Example makefile for using the mat libraries
BIN=test

# what you want to name your tar/zip file:
TARNAME=goes1944
CXX=g++

##CXXFLAGS=-O3 -Wall   # optimize
CXXFLAGS= -std=c++11 -ggdb -Wall # debug
##LIBS = -lm

EXAMPLES=

EXTRAS=\


SRCS=\
$(BIN).cpp\
dataset.cpp

HDRS=\
dataset.h

OBJS=\
$(BIN).o\
dataset.o\

$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(LIBS) -o $(BIN)

clean:
	/bin/rm -f *.o $(BIN)*.tar *~ core gmon.out a.out

tar:
	tar -cvzf $(TARNAME).tar makefile $(EXAMPLES) $(SRCS) $(HDRS) $(EXTRAS) Eigen
	ls -l $(TARNAME).tar

zip:
	zip $(TARNAME).zip makefile $(EXAMPLES) $(SRCS) $(HDRS) $(EXTRAS)
	ls -l $(TARNAME).zip
