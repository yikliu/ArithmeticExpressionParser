#ifndef NUM_COMMAND_CPP
#define NUM_COMMAND_CPP

#include "Num_Command.h"

/// Default constructor
template<typename T>
Num_Command<T>::Num_Command(T n)
	:n_(n)
{
}

/// Destructor
template<typename T>
Num_Command<T>::~Num_Command(void)
{
}

/// execute
template<typename T>
bool Num_Command<T>::execute(Stack<T> & s)
{
	s.push(this->n_);
	return true;
}

#endif