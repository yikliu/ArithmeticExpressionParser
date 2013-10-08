/**
* @file     Stack_Expr_Command_Factory.h
* @brief    Concrete Expr_Command Factory
* @details 
* @author   yikliu@umail.iu.edu
* @date     3/17/2012
*/

#ifndef STACK_EXPR_COMMAND_FACTORY_H
#define STACK_EXPR_COMMAND_FACTORY_H

#include "Expr_Command_Factory.h"

/**
 * @class Stack_Expr_Command_Factory
 * @Base Class Expr_Command_Factory
 */
template<typename T>
class Stack_Expr_Command_Factory : public Expr_Command_Factory<T>
{
public:
	/// Default Constructor
	Stack_Expr_Command_Factory(void);

	/// Destructor
	virtual ~Stack_Expr_Command_Factory(void); 
	
	/**
	* @brief   create a number command object
	* @param   T  the operand
	* @return  Pointer to Num_Command object
	*/
	virtual Num_Command<T> * create_num_command (T num);

	/**
	* @brief   create a add command object
	* @param   void
	* @return  Pointer to Add_Command object
	*/
	virtual Add_Command<T> * create_add_command (void);

	/**
	* @brief   create a subtract command object
	* @param   void
	* @return  Pointer to Subtract_Command object
	*/
	virtual Subtract_Command<T> * create_subtract_command (void);

	/**
	* @brief   create a Multiply command object
	* @param   void
	* @return  Pointer to Multiply_Command object
	*/
	virtual Multiply_Command<T> * create_multiply_command (void);

	/**
	* @brief   create a Divide Command object
	* @param   void
	* @return  Pointer to Divide_Command object
	*/
	virtual Divide_Command<T> * create_divide_command (void);

	/**
	* @brief   create a modulation Command object
	* @param   void
	* @return  Pointer to Module_Command object
	*/
	virtual Module_Command<T> * create_module_command (void);
};

#include "Stack_Expr_Command_Factory.cpp"

#endif