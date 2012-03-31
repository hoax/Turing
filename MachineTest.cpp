/*
 * MachineTest.cpp
 *
 *  Created on: 30.03.2012
 *      Author: tobias
 */

#include <sstream>
#include <iostream>
#include <unistd.h>
#include "IMachine.h"
#include "Machine.h"
#include "Tape.h"

int main() {
	std::cout << "\033[?25l";
	std::istringstream in("abbbbbd");
	Tape t(&in);

	IMachine* m = new Machine();

	std::istringstream rules("z1,a,b,left,z2\nz3,b,c,right,z3\nz2,-,X,right,z3");
	m->loadRules(&rules);
	m->setTape(&t);

	m->setState("unknown");
	m->step();

	m->setState("z1");

	do {
		t.dump(std::cout);
		sleep(1);
	} while(m->step());

	m->step();

	delete m;

	std::cout << "\033[?25h" << std::endl;
}


