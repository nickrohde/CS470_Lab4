/*
 * runMode.h
 *
 *  Created on: Feb 15, 2018
 *      Author: nicola
 */
#ifndef TASK_H_
#define TASK_H_

class Task
{
public:
	long long l_num;
	long long l_factor;
	bool b_stop;
	
	Task(bool stop)
	{
		b_stop = stop;
	} // end Constructor
	
	Task(long long number, long long factor)
	{
		l_factor = factor;
		l_num = number;
	} // end Constructor
}; // end Class Task

#endif

#ifndef RESULT_H_
#define RESULT_H_

class Result
{
public:
	long long l_factor  ;
	int       i_exponent;
	bool      b_isFactor;
	
	Result(long long factor, int exponent, bool valid)
	{
		if(valid)
		{
			l_factor   = factor;
			i_exponent = exponent;
			b_isFactor = true;
		} // end if
		else
		{
			l_factor   = 0;
			i_exponent = 0;
			b_isFactor = false;
		} // end else
	} // end Constructor
}; // end Class Result

#endif


#ifndef RUNMODE_H_
#define RUNMODE_H_

class RunMode
{
public:
	virtual ~RunMode(void) = 0;
	virtual int run(void) = 0;
}; // end Class RunMode

#endif /* RUNMODE_H_ */
