DEBUG = -ggdb
CXXFLAGS += $(WFLAGS) $(DEBUG)

all: TapeTest

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

TapeTest: Tape.o TapeTest.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^
	
MachineTest: Machine.o Tape.o MachineTest.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	$(RM) TapeTest
	$(RM) MachineTest
	$(RM) *.o