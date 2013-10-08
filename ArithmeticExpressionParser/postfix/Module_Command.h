/**
* @file     Module_Command.h
* @brief    Module Command
* @details 
* @author   yikliu@umail.iu.edu
* @date     3/17/2012
*/
#ifndef MODULE_COMMAND_H
#define MODULE_COMMAND_H

#include "Binary_Op_Command.h"

// Author, do not implement the methods in the header file. Instead,
// place the implementation in a separate source file, or an inline
// file.
// 
// REPLY: Implementation has been moved to CPP file.

/**
 * @class Module_Command 
 * @Base Class Bindary_Op_Command
 */
template<typename T>
class Module_Command : public Binary_Op_Command<T>
{
public:
	/// Default Constructor
	Module_Command(void);/*{}*/
	
	/// Destructor
	virtual ~Module_Command(void);/*{}*/

	/**
	* @brief   evaluate th modulation of the two operands
	* @param[in]  T   n1  
	* @param[in]  T   n2  
	* @return     T   remainder
	* @exception  if the n1 is zero, throw exception
	*/
	virtual T evaluate (T n1, T n2) const;
	/*{		
		int b = (int)n1; //convert floating types to int before calculation
		if (b == 0)
			throw std::exception("Divide By Zero!");
		int a = (int)n2;
		int r = a % b;
		return (T)(r * b < 0 ? r + b : r); //To account for negative operands
	}*/
};

#include "Module_Command.cpp"
#endif
