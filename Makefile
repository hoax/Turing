DEBUG = -ggdb
RELEASE = -O3
COVERAGE_FLAGS = -fprofile-arcs -ftest-coverage
CXXFLAGS += $(WFLAGS) $(DEBUG)

all: TapeTest MachineTest turing turingStep turingSpeed interceptor.so

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

interceptor.so: interceptor-malloc.c
	$(CC) -fPIC -shared $(WFLAGS) -o $@ $^ -ldl

TapeTest: Tape.o TapeTest.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^
	
MachineTest: Machine.o Tape.o MachineTest.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

turing: Machine.o Tape.o main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

turingStep: Machine.o Tape.o mainStep.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

turingSpeed: Machine.o Tape.o mainSpeed.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^
	
test: CXXFLAGS+=${COVERAGE_FLAGS}
test: clean all runTest

runTest:
	./MachineTest > /dev/null
	./TapeTest > /dev/null
	./turingSpeed rules1.txt - > /dev/null
	-LD_PRELOAD=./interceptor.so ./turingSpeed beaver.txt - > /dev/null
	gcov Tape.cpp | grep -B1 -A0 %
	gcov Machine.cpp | grep -B1 -A0 %
	./removeUselessGCov.sh
	grep "###" *.gcov && false

clean:
	$(RM) turing
	$(RM) TapeTest
	$(RM) MachineTest
	$(RM) *.o *.gcov *.gcda *.gcno
