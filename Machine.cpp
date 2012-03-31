/*
 * Machine.cpp
 *
 *  Created on: 30.03.2012
 *      Author: tobias
 */

#include <stdio.h>
#include <string>
#include "Machine.h"

Machine::Machine() : tape(0) {

}

Machine::~Machine() {
	std::map<std::string, std::map<int, Action*>* >::iterator it = states.begin();
	while(it != states.end()) {
		std::map<int, Action*>* submap = it->second;
		if (submap) {
			std::map<int, Action*>::iterator it2 = submap->begin();
			while(it2 != it->second->end()) {
				delete it2->second;
				it2++;
			}
			delete it->second;
		}
		it++;
	}
}

void Machine::loadRules(std::istream* rules) {
	do {
		std::string startState;
		std::getline(*rules,startState,',');

		std::string readStr;
		std::getline(*rules,readStr,',');

		std::string writeStr;
		std::getline(*rules,writeStr,',');

		std::string moveToStr;
		std::getline(*rules,moveToStr,',');

		std::string nextState;
		std::getline(*rules,nextState);

		char read = (readStr.size() > 0) ? readStr[0] : '?' ;
		char write = (writeStr.size() > 0) ? writeStr[0] : '!' ;
		Direction moveTo = LEFT;
		if (moveToStr.size() > 0 && (moveToStr[0] == 'r' || moveToStr[0] == 'R')) {
			moveTo = RIGHT;
		}
		addRule(startState, read, write, moveTo, nextState);

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
			return false;
		}
	} else {
		return false;
	}

	return true;
}

void Machine::setTape(ITape* t) {
	tape = t;
};
