


# Example makefile for using the mat libraries
BIN=nn

# what you want to name your tar/zip file:
TARNAME=goes1944
CXX=g++

##CXXFLAGS=-O3 -Wall   # optimize
CXXFLAGS= -std=c++11 -ggdb -Wall # debug
##LIBS = -lm

EXAMPLES=

EXTRAS=\


SRCS=\
$(BIN)oneof.cpp\
$(BIN).cpp\
dataset.cpp\
utility.cpp\
neuralnet.cpp

HDRS=\
dataset.h\
utility.h\
neuralnet.h

OBJS=\
$(BIN).o\
dataset.o\
utility.o\
neuralnet.o

OBJS2=\
$(BIN)oneof.o\
dataset.o\
utility.o\
neuralnet.o

$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(LIBS) -o $(BIN)

$(BIN)oneof: $(OBJS) $(BIN)oneof.o
	$(CXX)  $(CxxFLAGS) $(OBJS2) $(LIBS) -o $(BIN)oneof

$(BIN)oneof.o: $(BIN)oneof.cpp
	g++ -Wall -g -c $(BIN)oneof.cpp -o $(BIN)oneof.o

clean:
	/bin/rm -f *.o $(TARNAME).tar *~ core gmon.out a.out

tar:
	tar -cvf $(TARNAME).tar makefile $(EXAMPLES) $(SRCS) $(HDRS) $(EXTRAS) Eigen
	ls -l $(TARNAME).tar

zip:
	zip $(TARNAME).zip makefile $(EXAMPLES) $(SRCS) $(HDRS) $(EXTRAS)
	ls -l $(TARNAME).zip
