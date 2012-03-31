/*
 * Machine.h
 *
 *  Created on: 30.03.2012
 *      Author: tobias
 */

#ifndef MACHINE_H_
#define MACHINE_H_

#include <iostream>
#include <map>
#include "IMachine.h"
#include "ITape.h"

class Action {
public:
	Action(char w, Direction m, std::string s) : write(w), moveTo(m), newState(s) {}
	char write;
	Direction moveTo;
	std::string newState;
};

class Machine: public IMachine {
	ITape* tape;
	std::string currentState;
	std::map<std::string, std::map<int, Action*>* > states;
public:
	Machine();
	virtual ~Machine();

	virtual void loadRules(std::istream* rules);
	virtual void setTape(ITape* tape);
	virtual void setState(std::string state);
	virtual void addRule(std::string state, char read, char write, Direction moveTo, std::string newState);
	virtual bool step();
};

#endif /* MACHINE_H_ */
