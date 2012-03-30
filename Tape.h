/*
 * Tape.h
 *
 *  Created on: 30.03.2012
 *      Author: tobias
 */

#ifndef TAPE_H_
#define TAPE_H_

#include <iostream>
#include "ITape.h"


class Field {
public:
	Field(char v, Field* p = 0, Field* n = 0) : prev(p), next(n), val(v) {
		if (p) p->next = this;
		if (n) n->prev = this;
	};

	~Field() {
		delete next;
		next = 0;
	}

	Field* prev;
	Field* next;
	char val;
};

class Tape: public ITape {
	Field* head;
	Field* mostLeft;
public:
	Tape(std::istream* initStream);
	virtual ~Tape();

	virtual void moveLeft();
	virtual void moveRight();
	virtual char val();
	virtual void setVal(char newValue);
	virtual void dump(std::ostream& out);
};

#endif /* TAPE_H_ */
