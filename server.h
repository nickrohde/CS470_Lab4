/*
 * server.h
 *
 *  Created on: Feb 15, 2018
 *      Author: nick rohde
 */
#include "runMode.h"


#ifndef SERVER_H_
#define SERVER_H_

class Server : public RunMode
{
public:
	Server(void);
	~Server(void);

	int run(void);


private:
	unsigned long long l_number;

};



#endif /* SERVER_H_ */
