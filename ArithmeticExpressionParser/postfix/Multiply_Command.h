/**
* @file     Multiply_Command.h
* @brief	Multiply Command
* @details 
* @author   yikliu@umail.iu.edu
* @date     3/17/2012
*/
#ifndef MULTIPLY_COMMAND_H
#define MULTIPLY_COMMAND_H

#include "Binary_Op_Command.h"

// Author, do not implement the methods in the header file. Instead,
// place the implementation in a separate source file, or an inline
// file.
//
// REPLY: Implementation has been moved to CPP file

/**
 * @class  Multiply Command
 * @Base Class  Binary_Op_Command
 */
template<typename T>
class Multiply_Command : public Binary_Op_Command<T>
{
public:
	/// Default Constructor
	Multiply_Command(void); /*{}*/
	
	/// Destructor
	virtual ~Multiply_Command(void); /*{}*/

	/**
	* @brief   evaluate the product of the two operands
	* @param[in]  T   n1 operand one
	* @param[in]  T   n2 operand two
	* @return     T   product
	*/
	virtual T evaluate (T n1, T n2) const;
	/*{
		return n2 * n1;
	}*/
};

#include "Multiply_Command.cpp"

#endif
