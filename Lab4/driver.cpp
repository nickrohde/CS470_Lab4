/*
 * driver.cpp
 *
 *  Created on: Feb 15, 2018
 *      Author: nick rohde
 */
#include <stdlib.h>
#include <iostream>
#include "runMode.h"
#include "server.h"
#include "client.h"


using namespace std;

const char* SERVER = "-s";
const char* CLIENT = "-c";

int main(int argc, char* argv)
{
	try
	{
		RunMode * mode = NULL;
		bool b_server;

		if(argc < 1)
		{
			cout << "You must supply either the argument -s or -c when starting the application." << endl;
			cout << "Use -s for server, and -c for client." << endl;
			cout << "Exiting." << endl;
			exit(EXIT_FAILURE);
		} // end if
		else if(argv[0] == SERVER)
		{
			mode = new Server();
			server = true;
		} // end elif
		else if(argv[0] == CLIENT)
		{
			int port;
			server = false;
			
			if(argc < 3)
			{
				cout << "You must supply the IP address of the server, and TCPIP port to use to run in Client mode." << endl;
				cout << "Example call: ./driver -c localhost 45723" << endl;
				cout << "Exiting." << endl;
				exit(EXIT_FAILURE);
			} // end if
			
			try
			{
				port = atoi(argv[2]);
			} // end try
			catch(exception)
			{
				cout << "The port you supplied was not valid. The port must be an integer between 1 and 65536." << endl;
				cout << "Example call: ./driver -c localhost 45723" << endl;
				cout << "Exiting." << endl;
				exit(EXIT_FAILURE);
			} // end catch
			
			mode = new Client(argv[1], port);
		} // end elif
		else
		{
			cout << "Invalid option selected. Use -s for server mode, -c for client mode." << endl;
			cout << "Exiting." << endl;
			exit(EXIT_FAILURE);
		} // end else

		int exit = mode->run();
		
		switch(exit)
		{
			case 0:
			cout << "Execution was successful." << endl;
			break;
			
			case 1:
			if(b_server)
			{
				cout << "TODO" << endl;
			} // end if
			else
			{
				cout << "Execution failed, client failed to receive tasks from server." << endl;
			} // end else
			break;
			
			case 2:
			if(b_server)
			{
				cout << "TODO" << endl;
			} // end if
			else
			{
				cout << "Execution failed, client failed to complete factoring the task." << endl;
			} // end else
			break;
		} // end switch
		
		delete mode;
	} // end try
	catch(exception& e)
	{
		cout << "An exception occurred during execution. Message: " << e.what() << "\nExiting." << endl;
		exit(EXIT_FAILURE);
	} // end catch

	return 0;
} // end Main
