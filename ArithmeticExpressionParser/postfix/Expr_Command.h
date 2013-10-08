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

// Author, do not implement the methods in the header file. Instead,
// place the implementation in a separate source file, or an inline
// file.
//
// REPLY: Implementation has been moved to CPP file.

// Author, since you have a virtual method in this class, you need
// to explicity declare the destructor as virtual.
//
// REPLY: Destructor is declared as virtual.

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