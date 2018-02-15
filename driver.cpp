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
		} // end elif
		else if(argv[0] == CLIENT)
		{
			mode = new Client();
		} // end elif
		else
		{
			cout << "Invalid option selected. Use -s for server mode, -c for client mode." << endl;
			cout << "Exiting." << endl;
			exit(EXIT_FAILURE);
		} // end else

		mode->run();
		delete mode;
	} // end try
	catch(exception& e)
	{
		cout << "An exception occurred during execution. Message: " << e.what() << "\nExiting." << endl;
		exit(EXIT_FAILURE);
	} // end catch

	return 0;
} // end Main
