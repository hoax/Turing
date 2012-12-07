Turing
======

Interpreter for turing machines

Compile 
-------
To compile run `make all`

The binaries can also be built with debug information by setting the option withDebug `make all withDebug=1`

Usage
-----
There are three programs doing more or less the same:

+ *turingSpeed* Runs the interpreter and finally prints the content of the tape.
+ *turing* Shows the tape's content + head position and sleeps 0.5s after every step.
+ *turingStep* Shows the tape's content + head position and waits for the user to press a key after every step.

All programs expect at least one parameter: The name of the containing the turing machine rules.
The second parameter is optional and defines the initial content of the tape. If the parameter is not supplied the program will prompt the user on the console.

Rules
-----
The rules are read from a file, where each line defines one rule. Reading the rules ends by reaching the end of the file or an empty line.
A rule consists of five parts separated by comma. For example: `A,-,1,R,B`

The five parts are:

1. current state, one character
2. input char, one character
3. output char, one character
4. movement, *r* for right, *l* for left
5. next state, one character

Execution of the rules starts with the current state being the start state of the first rule.

Test
----
Tests exist for 100% code coverage measured by gcov. These tests can be run by executing `make test`. If the target executes without an error, the code is covered 100% otherwise the last lines starting with ### indicate which lines are not covered.