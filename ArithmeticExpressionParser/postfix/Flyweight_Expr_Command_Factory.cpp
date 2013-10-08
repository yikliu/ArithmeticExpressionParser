#pragma once
#ifndef FLYWEIGHT_EXPR_COMMAND_FACTORY_CPP_
#define FLYWEIGHT_EXPR_COMMAND_FACTORY_CPP_

#include "Flyweight_Expr_Command_Factory.h"

//
// Flyweight_Expr_Command_Factory(void)
//
template<typename T>
Flyweight_Expr_Command_Factory<T>::Flyweight_Expr_Command_Factory(void)
	:add_(0),
	subtract_(0),
	multiply_(0),
	divide_(0),
	module_(0)
{
	add_ = new Add_Command<T>();
	subtract_ = new Subtract_Command<T>();
	multiply_ = new Multiply_Command<T>();
	divide_ = new Divide_Command<T>();
	module_ = new Module_Command<T>();
}

//
// ~Flyweight_Expr_Command_Factory(void)
//
template<typename T>
Flyweight_Expr_Command_Factory<T>::~Flyweight_Expr_Command_Factory(void)
{
	if( 0 != add_ )
	{
		delete add_;
		add_ = 0;
	}
		
	if( 0 != subtract_)
	{
		delete subtract_;
		subtract_ = 0;
	}
	if( 0 != multiply_)
	{
		delete multiply_;
		multiply_ = 0;
	}
	if( 0 != divide_)
	{
		delete divide_;
		divide_ = 0;
	}
	if( 0 != module_)
	{
		delete module_;
		module_ = 0;
	}
}

/// create_num_command
template<typename T>
Num_Command<T> * Flyweight_Expr_Command_Factory<T>::create_num_command (T num)
{
	return new Num_Command<T>(num);
}

/// create_add_command
template<typename T>
Add_Command<T> * Flyweight_Expr_Command_Factory<T>::create_add_command (void) 
{
	return this->add_;
}

/// create_subtract_command
template<typename T>
Subtract_Command<T> * Flyweight_Expr_Command_Factory<T>::create_subtract_command (void) 
{
	return this->subtract_; 
}

/// create_multiply_command
template<typename T>
Multiply_Command<T> * Flyweight_Expr_Command_Factory<T>::create_multiply_command (void) 
{
	return this->multiply_; 
}

/// create_divide_command
template<typename T>
Divide_Command<T> * Flyweight_Expr_Command_Factory<T>::create_divide_command (void) 
{
	return this->divide_; 
}

/// create_module_command
template<typename T>
Module_Command<T> * Flyweight_Expr_Command_Factory<T>::create_module_command (void) 
{
	return this->module_;
}

#endif // FLYWEIGHT_EXPR_COMMAND_FACTORY_CPP_
