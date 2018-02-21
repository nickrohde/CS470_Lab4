#include "server.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

Server::Server(const string& IP, const int _port, const int i_iterations)
{
	if (_port < 1 || i_iterations < 1)
	{
		cout << "You supplied invalid arguments in the .ini file." << endl;
		cout << "Port and number of iterations (n) must be positive integers." << endl;
		cout << "You supplied port: " << _port << " and iterations: " << i_iterations << "." << endl;
		cout << "Exiting." << endl;
		exit(EXIT_FAILURE);
	} // end if

	s_IP = IP;
	i_port = _port;
	n = i_iterations;

	memset(primes, true, sizeof(bool)*SIZE);
	sievePrimes();
} // end Constructor

Server::~Server(void)
{

}

int Server::run(void)
{
	return 0;
} // end method run


void Server::sievePrimes(void)
{
	primes[0] = false;
	primes[1] = false;
	primes[2] = true;

	// set all evens to false
	for (int i = 4; i < MAX; i += 2)
	{
		primes[i] = false;
	} // end for

	// set remaining no-primes to false
	for (int i = 3; i < MAX; i+=2)
	{
		if (primes[i])
		{
			for (int j = i * i; j < SIZE; j += i)
			{
				primes[j] = false;
			} // end for
		} // end if
	} // end for
} // end method sievePrimes

