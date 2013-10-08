/**
* @file     Binary_Op_Command.h
* @brief	Abstract class for commands that take two operands
* @details 
* @author   yikliu@umail.iu.edu
* @date     3/17/2012
*/

#ifndef BINARY_OP_COMMAND_H
#define BINARY_OP_COMMAND_H

#include "Expr_Command.h"

// Author, do not implement the methods in the header file. Instead,
// place the implementation in a separate source file, or an inline
// file.
// 
// REPLY: Implementation has been moved to CPP file.

// Author, since this class has a virtual method, then you need to 
// explicitly declare the destructor as virtual.
// 
// REPLY: Declared destructor as virtual

/**
 * @class Binary_Op_Command
 * @Base Class Expr_Command
 *
 * @brief Abstract class describing interfaces for two operand commands
 */
template<typename T>
class Binary_Op_Command : public Expr_Command<T>
{
public:
	///Default Constructor
	Binary_Op_Command(void);/*{}*/
	
	///Destructor
	virtual ~Binary_Op_Command(void);/*{}*/

	/**
	* @brief   execute two operand commands
	* @param   Stack<T>   stack for postfix evaluation
	* @return  flag indicating success or failure
	*/
	bool execute(Stack<T> & s);
	/*
	{
		T n1 = s.top(); 
		s.pop();
		T n2 = s.top();
		s.pop();
		
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
	}*/

	/**
	* @brief   interface to get result for any binary operand commands
	* @param[in]  n1
	* @param[in]  n2
	* @return  result
	* @exceptoin throw std::exception when arguments are not legal for calculation
	*			 such as dividing by zero
	*/
	virtual T evaluate (T n1, T n2) const  = 0;
};

#include "Binary_Op_Command.cpp"

#endif