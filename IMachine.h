/*
 * IMachine.h
 *
 *  Created on: 30.03.2012
 *      Author: tobias
 */

#ifndef IMACHINE_H_
#define IMACHINE_H_

#include <iostream>
#include <string>
#include "ITape.h"

enum Direction {
	LEFT, RIGHT
};

class IMachine {
public:
	virtual ~IMachine() {};
	virtual void setTape(ITape* tape) = 0;
	virtual void loadRules(std::istream* rules) = 0;
	virtual void setState(std::string state) = 0;
	virtual void addRule(std::string state, char read, char write, Direction moveTo, std::string newState) = 0;
	virtual bool step() = 0;
};

#endif /* IMACHINE_H_ */
