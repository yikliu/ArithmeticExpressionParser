#ifndef EXPR_COMSTACK_EXPR_COMMAND_FACTORY_CPPMAND_FACTORY_CPP
#define EXPR_COMSTACK_EXPR_COMMAND_FACTORY_CPPMAND_FACTORY_CPP

#include "Stack_Expr_Command_Factory.h"

/// Default constructor
template<typename T>
Stack_Expr_Command_Factory<T>::Stack_Expr_Command_Factory(void)
{
}

/// Destructor
template<typename T>
Stack_Expr_Command_Factory<T>::~Stack_Expr_Command_Factory(void)
{
}

/// create_num_command
template<typename T>
Num_Command<T> * Stack_Expr_Command_Factory<T>::create_num_command (T num)
{
	return new Num_Command<T>(num);
}

/// create_add_command
template<typename T>
Add_Command<T> * Stack_Expr_Command_Factory<T>::create_add_command (void) 
{
	return new Add_Command<T>();
}

/// create_subtract_command
template<typename T>
Subtract_Command<T> * Stack_Expr_Command_Factory<T>::create_subtract_command (void) 
{
	return new Subtract_Command<T>();
}

/// create_multiply_command
template<typename T>
Multiply_Command<T> * Stack_Expr_Command_Factory<T>::create_multiply_command (void) 
{
	return new Multiply_Command<T>();
}

/// create_divide_command
template<typename T>
Divide_Command<T> * Stack_Expr_Command_Factory<T>::create_divide_command (void) 
{
	return new Divide_Command<T>();
}

/// create_module_command
template<typename T>
Module_Command<T> * Stack_Expr_Command_Factory<T>::create_module_command (void) 
{
	return new Module_Command<T>();
}


#endif