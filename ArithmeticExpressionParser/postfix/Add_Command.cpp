#ifndef ADD_COMMAND_CPP
#define ADD_COMMAND_CPP

#include "Add_Command.h"

///
/// Constructor
///
template<typename T>
Add_Command<T>::Add_Command(void)
{
}

///
/// Destructor
///
template<typename T>
Add_Command<T>::~Add_Command(void)
{
}

///
/// evaluate
///
template<typename T> 
T Add_Command<T>::evaluate (T n1, T n2) const 
{
	return n2 + n1;
}

#endif