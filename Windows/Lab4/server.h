#include "runMode.h"
#include <string>

using namespace std;

#ifndef SERVER_H_
#define SERVER_H_

class Server : public RunMode
{
public:
	Server(const string& s_IP="127.0.0.1", const int i_port = 1234, const int i_iterations=10);
	~Server(void);

	int run(void);


private:
	static const int MAX = 316; 
	static const int SIZE = 100000;


	int n;

	bool primes[SIZE];

	void setupTCPHost(void);
	void sievePrimes(void);

};



#endif /* SERVER_H_ */
