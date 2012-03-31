DEBUG = -ggdb
COVERAGE_FLAGS = -fprofile-arcs -ftest-coverage
CXXFLAGS += $(WFLAGS) $(DEBUG)

all: TapeTest MachineTest turing

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

TapeTest: Tape.o TapeTest.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^
	
MachineTest: Machine.o Tape.o MachineTest.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

turing: Machine.o Tape.o main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^
	
test: CXXFLAGS+=${COVERAGE_FLAGS}
test: clean all runTest

runTest:
	./MachineTest
	./TapeTest
	./turing rules1.txt aabbcc
	gcov Tape.cpp | grep -B1 -A0 %
	gcov Machine.cpp | grep -B1 -A0 %
	./removeUselessGCov.sh

clean:
	$(RM) turing
	$(RM) TapeTest
	$(RM) MachineTest
	$(RM) *.o *.gcov *.gcda *.gcno
