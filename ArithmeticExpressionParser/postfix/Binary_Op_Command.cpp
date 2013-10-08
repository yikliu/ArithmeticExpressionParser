#ifndef _BINARY_OP_COMMAND_CPP_
#define _BINARY_OP_COMMAND_CPP_

#include "Binary_Op_Command.h"

/// default constructor
template<typename T>
Binary_Op_Command<T>::Binary_Op_Command(void)
{
}

/// destructor
template<typename T>
Binary_Op_Command<T>::~Binary_Op_Command(void)
{
}

/// execute
template<typename T>
bool Binary_Op_Command<T>::execute(Stack<T> & s)
{
	// make to pops to get two operands
	T n1 = s.top(); 
	s.pop();
	T n2 = s.top();
	s.pop();

	// operate on the operands get th result, and push the result back to the stack.
	try
	{
		T res = this->evaluate(n1, n2);
		s.push(res);
	}		
	catch (std::exception& e)
	{			
		std::cout<<std::endl;
		std::cerr<<e.what()<<std::endl;
		return false;
	}	

	return true;
}

#endif // _BINARY_OP_COMMAND_CPP_