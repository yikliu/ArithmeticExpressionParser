/**
* @file     Add_Command.h
* @brief    Add Command 
* @details 
* @author   yikliu@umail.iu.edu
* @date     3/17/2012
*/
#ifndef ADD_COMMAND_H
#define ADD_COMMAND_H

#include "Binary_Op_Command.h"

// Author, do not implement the methods in the header file. Instead,
// place the implementation in a separate source file, or an inline
// file.
//
// REPLY: Implementation has been moved to CPP file.

/**
 * @class Add_Command
 * @Base Class Bindary_Op_Command
 *
 * @brief Command to get the sum of two operands
 */
template<typename T>
class Add_Command : public Binary_Op_Command<T>
{
public:
	///Default Constructor
	Add_Command(void);/*{}*/

	///Destructor
	virtual ~Add_Command(void);/*{}*/

	/**
	* @brief   evaluate the sum of the two operands
	* @param[in]  T   n1 operand one
	* @param[in]  T   n2 operand two
	* @return     T   sum
	*/
	virtual T evaluate (T n1, T n2) const;
};

#include "Add_Command.cpp"
#endif
