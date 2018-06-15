ROOTLIBS = $(shell root-config --libs) -lMinuit -lMLP -lXMLIO -lTMVA -lGenVector

CC = g++
CFLAGS = -g -std=c++1y

TARGET = makePlots make_runF_comparisons 

all: $(TARGET)

makePlots: makePlots.cpp PlotHelper.h
	$(CC) $(CFLAGS) -I${ROOTSYS}/include -o makePlots makePlots.cpp $(ROOTLIBS)
make_runF_comparisons: make_runF_comparisons.cpp PlotHelper.h
	$(CC) $(CFLAGS) -I${ROOTSYS}/include -o make_runF_comparisons make_runF_comparisons.cpp $(ROOTLIBS)
