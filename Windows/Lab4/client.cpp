#include "client.h"
#include <math.h>
#include <iostream>

using namespace std;

Client::Client(const string& server, const int port, const time_t _timeout)
{
	if (port < 1 || _timeout < 1)
	{
		cout << "You supplied invalid arguments in the .ini file." << endl;
		cout << "Port and timeout must be positive integers." << endl;
		cout << "You supplied port: " << port << " and timeout: " << _timeout << " ms." << endl;
		cout << "Exiting." << endl;
		exit(EXIT_FAILURE);
	} // end if

	s_IP = server;
	i_port = port;
	t_timeout = _timeout;
} // end Constructor


Client::~Client(void)
{

}


int Client::run(void)
{
	for(;;)
	{
		try
		{
			getWork();
			
			if(current_task.b_stop)
			{
				cout << "Client is finished, exiting." << endl;
				return 0;
			} // end if
		} // end try
		catch(exception)
		{
			return 1;
		} // end catch
		
		try
		{
			factorNumber();

			if (current_result.b_isFactor)
			{
				cout << "Completed factoring, " << current_task.l_factor << "^" <<  current_result.i_exponent << " is a factor of " << current_task.l_num << endl;
			}
			else
			{
				cout << "Completed factoring, " << current_task.l_factor << " is not a factor of " << current_task.l_num  << endl;
			}
		} // end try
		catch(exception)
		{
			return 2;
		} // end catch

		try
		{
			sendBackResult();
		} // end try
		catch (exception)
		{
			return 3;
		} // end catch
	} // end for
} // end method run                                        


void Client::getWork(void)
{
	for(;;)
	{
		current_task = Task();
		// TODO poll TCP/IP port for available task
	} // end for
} // end method getWork

void Client::factorNumber(void)
{
	if (current_task.l_num % current_task.l_factor == 0)
	{
		int i_counter = 0;
		long long l_number = current_task.l_num;

		while (l_number % current_task.l_factor == 0)
		{
			i_counter++;
			l_number = l_number / current_task.l_factor;
		} // end while

		current_result = Result(current_task.l_factor, i_counter, true);
	} // end if
	else
	{
		current_result = Result(current_task.l_factor, 0, false);
	} // end else	
} // end method factorNumber                                      

void Client::sendBackResult(void)
{
	// TODO send result back to server
}