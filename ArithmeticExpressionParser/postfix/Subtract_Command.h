/**
* @file     Substract_Command.h
* @brief    Subtraction Command
* @details 
* @author   yikliu@umail.iu.edu
* @date     3/17/2012
*/

#ifndef SUBSTRCT_COMMAND_H
#define SUBSTRCT_COMMAND_H
#include "binary_op_command.h"

/**
 * @class Substract_Command
 * @Base Class Bindary_Op_Command
 */
template <typename T>
class Subtract_Command : 	public Binary_Op_Command<T>
{
public:
	/// Default Constructor
	Subtract_Command(void); /*{}*/
	
	/// Destructor
	virtual ~Subtract_Command(void); /*{}*/

	/**
	* @brief   evaluate th difference of the two operands
	* @param[in]  T   n1 minuend 
	* @param[in]  T   n2 subtrahend 
	* @return     T   difference 
	*/
	virtual T evaluate (T n1, T n2) const;
};

#include "Subtract_Command.cpp"

#endif
