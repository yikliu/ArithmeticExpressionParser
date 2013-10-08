#ifndef MULTIPLY_COMMAND_CPP
#define MULTIPLY_COMMAND_CPP

#include "Multiply_Command.h"

/// Default constructor
template<typename T>
Multiply_Command<T>::Multiply_Command(void)
{
}

/// Destructor
template<typename T>
Multiply_Command<T>::~Multiply_Command(void)
{
}

/// evaluate
template<typename T> 
T Multiply_Command<T>::evaluate (T n1, T n2) const 
{
	return n2 * n1;
}


#endif