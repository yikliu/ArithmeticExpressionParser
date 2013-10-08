#ifndef DIVIDE_COMMAND_CPP
#define DIVIDE_COMMAND_CPP

#include "Divide_Command.h"

/// Default constructor
template<typename T>
Divide_Command<T>::Divide_Command(void)
{
}

/// Destructor
template<typename T>
Divide_Command<T>::~Divide_Command(void)
{
}

/// evaluate
template<typename T> 
T Divide_Command<T>::evaluate (T n1, T n2) const 
{
	if (n1 == 0)
		throw std::exception("Divide By Zero!");		
	return n2 / n1;
}

#endif