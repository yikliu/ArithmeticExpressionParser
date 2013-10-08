/**
* @file     Divide_Command.h
* @brief	Divide Command
* @details 
* @author   yikliu@umail.iu.edu
* @date     3/17/2012
*/

#ifndef DIVIDE_COMMAND_H
#define DIVIDE_COMMAND_H

#include "Binary_Op_Command.h"

// Author, do not implement the methods in the header file. Instead,
// place the implementation in a separate source file, or an inline
// file.
// 
// REPLY: Implementation has been moved to CPP file


/**
 * @class Divide_Command
 * @Base Class Binary_Op_Command
 *
 * @brief command to get the division result from two operands
 */

template<typename T>
class Divide_Command : public Binary_Op_Command<T>
{
public:
	///Constructor
	Divide_Command(void); /*{}*/
	
	///Destructor
	virtual ~Divide_Command(void); /*{}*/

	/**
	* @brief   evaluate th division of the two operands
	* @param[in]  T   n1  divisor
	* @param[in]  T   n2  dividend
	* @return     T   quotient
	* @exception  if the divisor is zero, throw exception
	*/
	virtual T evaluate (T n1, T n2) const;
	/*{
		if (n1 == 0)
			throw std::exception("Divide By Zero!");		
		return n2 / n1;
	}*/
};

#include "Divide_Command.cpp"

#endif
