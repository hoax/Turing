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

	while(t->val()) {
		cout << t->val();
		t->moveRight();
	}
	cout << endl;

	delete t;
	delete in;

	return 0;
}

