/*
 * Machine.cpp
 *
 *  Created on: 30.03.2012
 *      Author: tobias
 */

#include <stdio.h>
#include <string>
#include "Machine.h"

Machine::Machine() : tape(0), stop(0) {

}

Machine::~Machine() {
	std::map<std::string, std::map<int, Action*>* >::iterator it = states.begin();
	while(it != states.end()) {
		std::map<int, Action*>::iterator it2 = it->second->begin();
		while(it2 != it->second->end()) {
			delete it2->second;
			it2++;
		}
		delete it->second;
		it++;
	}
}

void Machine::loadRules(std::istream* rules) {
	do {
		std::string startState;
		std::getline(*rules,startState,',');

		std::string read;
		std::getline(*rules,read,',');

		std::string write;
		std::getline(*rules,write,',');

		std::string moveTo;
		std::getline(*rules,moveTo,',');

		std::string nextState;
		std::getline(*rules,nextState);

		printf("rule: %s %s %s %s %s\n", startState.c_str(), read.c_str(), write.c_str(), moveTo.c_str(), nextState.c_str());

	} while(!rules->eof());

}

void Machine::addRule(std::string state, char read, char write, Direction moveTo, std::string newState) {
	std::map<int, Action*>* actions = states[state];
	if (!actions) {
		actions = new std::map<int, Action*>();
		states[state] = actions;
	}

	Action* action = new Action(write, moveTo, newState);
	(*actions)[(int)read] = action;
}

void Machine::setState(std::string state) {
	currentState = state;
}

bool Machine::step() {
	if (stop)
		return false;

	int c = tape->val();

	std::map<int, Action*>* actions = states[currentState];
	if (actions) {
		std::map<int, Action*>::iterator it = actions->find(c);

		if (it != actions->end()) {
			Action* a = actions->find(c)->second;
			tape->setVal(a->write);
			if (a->moveTo == LEFT) {
				tape->moveLeft();
			} else {
				tape->moveRight();
			}
			setState(a->newState);
		} else {
			stop = true;
		}
	} else {
		stop = true;
	}

	return !stop;
}

void Machine::setTape(ITape* t) {
	tape = t;
};
