/**
* @file     Expr_Command_Factory.h
* @brief	Abstract Factory for generating Expr_Command
* @details 
* @author   yikliu@umail.iu.edu
* @date     3/17/2012
*/
#ifndef EXPR_COMMAND_FACTORY_H
#define EXPR_COMMAND_FACTORY_H

#include "Num_Command.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Module_Command.h"

// Author, do not implement the methods in the header file. Instead,
// place the implementation in a separate source file, or an inline
// file.
//
// REPLY: Implementation has been moved to CPP file.


/**
 * @class Expr_Command_Factory
 * @brief
 */
template<typename T>
class Expr_Command_Factory
{
public:
	Expr_Command_Factory();/*{}*/

	virtual ~Expr_Command_Factory (void);/*{}*/

	///Interfaces for creating commands
	virtual Num_Command<T> * create_num_command (T num) = 0;

	virtual Add_Command<T> * create_add_command (void) = 0;

	virtual Subtract_Command<T> * create_subtract_command (void) = 0;

	virtual Multiply_Command<T> * create_multiply_command (void) = 0;

	virtual Divide_Command<T> * create_divide_command (void) = 0;

	virtual Module_Command<T> * create_module_command (void) = 0;

// Prohibit copy constructor and assignment
private:
	Expr_Command_Factory (const Expr_Command_Factory<T> &);
	const Expr_Command_Factory & operator = (const Expr_Command_Factory<T> &);
};

#include "Expr_Command_Factory.cpp"

#endif