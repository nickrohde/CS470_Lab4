#include "runMode.h"
#include <stdlib.h>
#include <string.h>

using namespace std;

#ifndef CLIENT_H_
#define CLIENT_H_

class Client : public RunMode
{
public:
	Client(const string& server = "127.0.0.1", const int port = 1234, const time_t _timeout = 3000);
	~Client(void);

	int run(void);

private:
	time_t t_timeout;
	Task current_task;
	Result current_result;

	void getWork(void);
	void factorNumber(void);
	void sendBackResult(void);
};



#endif /* CLIENT_H_ */
