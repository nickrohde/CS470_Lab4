/*
 * client.h
 *
 *  Created on: Feb 15, 2018
 *      Author: nick rohde
 */
#include "runMode.h"


#ifndef CLIENT_H_
#define CLIENT_H_

class Client : public RunMode
{
public:
	Client(void);
	~Client(void);

	int run(void);

private:
	unsigned long long l_factor;

};



#endif /* CLIENT_H_ */
