#ifndef SUBTRACT_COMMAND_CPP
#define SUBTRACT_COMMAND_CPP

#include "Subtract_Command.h"

/// Default constructor
template<typename T>
Subtract_Command<T>::Subtract_Command(void)
{
}

/// Destructor
template<typename T>
Subtract_Command<T>::~Subtract_Command(void)
{
}

/// evaluate
template<typename T> 
T Subtract_Command<T>::evaluate (T n1, T n2) const 
{
	return n2 - n1;
}


#endif