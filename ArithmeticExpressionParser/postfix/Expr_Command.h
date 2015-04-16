/**
* @file     Expr_Command.h
* @brief	Interface for expression commands
* @details 
* @author   yikliu@umail.iu.edu
* @date     3/17/2012
*/
#ifndef EXPR_COMMAND_H
#define EXPR_COMMAND_H

#include "../datastructure/Stack.h"

/**
 * @class Expr_Command
 * @brief
 */
template<typename T>
class Expr_Command
{
public:
	/// Default Constructor
	Expr_Command(void);/*{}*/	
	
	/// Destructor
	virtual ~Expr_Command(void);/*{}*/

	/**
	* @brief   method for execute the command with stack
	* @param   Stack<T> stack working with the commands
	* @return  flag indicating success of failure
	*/
	virtual bool execute (Stack<T> & stack) = 0;
};

#include "Expr_Command.cpp"

#endif