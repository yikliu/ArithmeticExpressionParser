#ifndef MODULE_COMMAND_CPP
#define MODULE_COMMAND_CPP

#include "Module_Command.h"

/// Default constructor
template<typename T>
Module_Command<T>::Module_Command(void)
{
}

/// Destructor
template<typename T>
Module_Command<T>::~Module_Command(void)
{
}

/// evaluate
template<typename T> 
T Module_Command<T>::evaluate (T n1, T n2) const 
{
	int b = (int)n1; //convert floating types to int before calculation
	if (b == 0)
		throw std::exception("Divide By Zero!");
	int a = (int)n2;
	int r = a % b;
	return (T)(r * b < 0 ? r + b : r); //To account for negative operands
}


#endif