/*
 * ITape.h
 *
 *  Created on: 30.03.2012
 *      Author: tobias
 */

#ifndef ITAPE_H_
#define ITAPE_H_

class ITape {
public:
	virtual ~ITape() {};
	virtual void moveLeft() = 0;
	virtual void moveRight() = 0;
	virtual char val() = 0;
	virtual void setVal(char newValue) = 0;
};

#endif /* ITAPE_H_ */
