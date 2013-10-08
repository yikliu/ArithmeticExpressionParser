//==============================================================================
/**
 * @file       Flyweight_Expr_Command_Factory.h
 * 
 * 
 *
 *
 * 
 */
//==============================================================================
#pragma once
#ifndef FLYWEIGHT_EXPR_COMMAND_FACTORY_H_
#define FLYWEIGHT_EXPR_COMMAND_FACTORY_H_

#include "Expr_Command_Factory.h"

/**
 * @class 
 *
 * 
 */
template<typename T>
class Flyweight_Expr_Command_Factory : public Expr_Command_Factory<T>
{
public:
	/// Default Constructor
	Flyweight_Expr_Command_Factory(void);
	// Destructor
	virtual ~Flyweight_Expr_Command_Factory(void);

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
	
private:	
	Add_Command<T> * add_;
	Subtract_Command<T> * subtract_;
	Multiply_Command<T> * multiply_;
	Divide_Command<T> * divide_;
	Module_Command<T> * module_;
};

#include "Flyweight_Expr_Command_Factory.cpp"

#endif // FLYWEIGHT_EXPR_COMMAND_FACTORY_H_
