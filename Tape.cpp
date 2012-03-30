/*
 * Tape.cpp
 *
 *  Created on: 30.03.2012
 *      Author: tobias
 */

#include <stdio.h>
#include "Tape.h"

Tape::Tape(std::istream* initStream) : head(0) {
	Field* h = 0;
	while(!initStream->eof()) {
		int c = initStream->get();
		if (c != -1) {
			moveRight();
			setVal((char)c);
			if (h == 0) {
				h = head;
			}
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
		head = new Field(0, 0, head);
	}
}

void Tape::moveRight() {
	if (head && head->next) {
		head = head->next;
	} else {
		head = new Field(0, head);
	}
}

void Tape::setVal(char newValue) {
	head->val = newValue;
}

char Tape::val() {
	return head->val;
}
