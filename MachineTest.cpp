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
	std::istringstream in("abbbbbb");
	Tape t(&in);

	IMachine* m = new Machine();
	//m->addRule("z1", 'a', 'b', RIGHT, "z2");
	//m->addRule("z2", 'b', 'c', RIGHT, "z2");

	std::istringstream rules("z1,a,b,right,z2\nz2,b,c,right,z2");
	m->loadRules(&rules);

	m->setTape(&t);
	m->setState("z1");

	do {
		t.dump(std::cout);
		sleep(1);
	} while(m->step());

	delete m;

	std::cout << "\033[?25h" << std::endl;
}


