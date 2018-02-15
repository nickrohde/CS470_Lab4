/*
 * runMode.h
 *
 *  Created on: Feb 15, 2018
 *      Author: nicola
 */

#ifndef RUNMODE_H_
#define RUNMODE_H_

class RunMode
{
public:
	virtual ~RunMode(void) = 0;
	virtual int run(void) = 0;
};




#endif /* RUNMODE_H_ */
