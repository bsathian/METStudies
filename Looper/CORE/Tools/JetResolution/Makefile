ROOTCFLAGS   := $(shell root-config --cflags)
ROOTLIBS     := $(shell root-config --libs) -lGenVector
CXXFLAGS      = -O -fPIC $(ROOTCFLAGS)
CXX           = g++
LD            = g++
LDFLAGS       = -O $(ROOTLIBS)
SOFLAGS       = -fPIC -shared

SOURCES=JetResolution.cxx
OBJECTS=$(SOURCES:.cxx=.o)
LIB=libJetResolution.so

%.o:	%.cxx
	$(CXX) $(CXXFLAGS) -c $< -o $@

all:	$(OBJECTS)
	$(LD) $(SOFLAGS) $(LDFLAGS) $(OBJECTS) -o $(LIB)

clean:
	rm -f *.o \
	rm -f *.d \
	rm -f *.so \
	rm -f *.exe

test:	test_me.C
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -L./ -Wl,-rpath -Wl,. -lJetResolution ../../CMS3_CORE.so test_me.C -o test_me.exe
