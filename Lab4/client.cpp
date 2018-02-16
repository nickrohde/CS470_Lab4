/*
 * client.cpp
 *
 *  Created on: Feb 15, 2018
 *      Author: nick rohde
 */
#include "client.h"
#include <math.h>

Client::Client(string& server, int port)
{
	s_server = server;
	i_port = port;
	current_job = NULL;
	current_result = NULL;
} // end Constructor


int Client::run(void)
{
	for(;;)
	{
		try
		{
			getWork();
			
			if(current_job.b_stop)
			{
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
		} // end try
		catch(exception)
		{
			return 2;
		} // end catch

		sendBackResult();
	} // end for
} // end method run


void Client::getWork(void)
{
	for(;;)
	{
		// poll TCP/IP port for available task
	} // end for
} // end method getWork

void Client::factorNumber(void)
{
	
	// TODO
	current_result = Result(0,0,true);
}

void Client::sendBackResult(void)
{
	// send result back to server
}