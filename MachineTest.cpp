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
	std::istringstream in("abbbbbb");
	Tape t(&in);

	IMachine* m = new Machine();
	m->addRule("z1", 'a', 'b', RIGHT, "z2");
	m->addRule("z2", 'b', 'c', RIGHT, "z2");
	m->setTape(&t);
	m->setState("z1");

	do {
		t.dump(std::cout);
		sleep(1);
	} while(m->step());

	delete m;
}


