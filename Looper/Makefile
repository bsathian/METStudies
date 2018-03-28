ROOTLIBS = $(shell root-config --libs) -lMinuit -lMLP -lXMLIO -lTMVA -lGenVector

CC = g++
CFLAGS = -g -std=c++1y

TARGET = analyze

all: $(TARGET)

analyze: ScanChain.C ScanChain.h analyze.cpp
	$(CC) $(CFLAGS) -I${ROOTSYS}/include -o analyze analyze.cpp $(ROOTLIBS)

