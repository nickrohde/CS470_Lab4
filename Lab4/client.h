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
	Client(string&, int);
	~Client(void);

	int run(void);

private:
	int i_port;
	long long l_factor;
	string s_server;
	Task current_job;
	Result current_result;

	void getWork(void);
	void factorNumber(void);
	void sendBackResult(void);
};



#endif /* CLIENT_H_ */
