/*
 * Tape.cpp
 *
 *  Created on: 30.03.2012
 *      Author: tobias
 */

#include <stdio.h>
#include "Tape.h"

Tape::Tape(std::istream* initStream) : head(0), mostLeft(0) {
	Field* h = 0;
	while(!initStream->eof()) {
		int c = initStream->get();
		moveRight();
		if (h == 0) {
			h = head;
		}
		if (c != -1) {
			setVal((char)c);
		}
	}
	head = h;
}

Tape::~Tape() {
	Field* h = head;
	while(h->prev) h = h->prev;
	delete h;
}

void Tape::moveLeft() {
	if (head && head->prev) {
		head = head->prev;
	} else {
		head = new Field('-', 0, head);
		mostLeft = head;
	}
}

void Tape::moveRight() {
	if (head && head->next) {
		head = head->next;
	} else {
		head = new Field('-', head);
		if (!head->prev)
			mostLeft = head;
	}
}

void Tape::setVal(char newValue) {
	head->val[0] = newValue;
}

char Tape::val() {
	return head->val[0];
}

void Tape::dump(std::ostream& out) {
	Field* f = mostLeft;
	out << '\r';
	while(f) {
		if (f == head) {
			out << "\033[1;31;47m" << f->val[0] << "\033[0m";
		} else {
			out << f->val[0];
		}
		f = f->next;
	}
	out.flush();
}
