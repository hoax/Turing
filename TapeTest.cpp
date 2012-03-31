/*
 * TapeTest.cpp
 *
 *  Created on: 30.03.2012
 *      Author: tobias
 */

#include <iostream>
#include <sstream>
#include "ITape.h"
#include "Tape.h"

using namespace std;

int main() {
	string s = "HalloWelt";
	istream* in = new istringstream(s);
	ITape* t = new Tape(in);

	t->moveLeft();

	t->moveRight();
	t->moveRight();
	t->moveRight();
	t->moveRight();
	t->moveLeft();
	t->moveRight();
	t->moveRight();

	delete t;
	delete in;

	return 0;
}

