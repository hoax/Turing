DEBUG = -ggdb
CXXFLAGS += $(WFLAGS) $(DEBUG)

all: TapeTest

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

TapeTest: Tape.o
	$(CXX) $(CXXFLAGS) -o $@ $^ TapeTest.cpp
	
clean:
	$(RM) TapeTest
	$(RM) *.o