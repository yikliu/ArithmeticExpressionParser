/**
* @file     Num_Command.h
* @brief	Push a operand into stack
* @details 
* @author   yikliu@umail.iu.edu
* @date     3/17/2012
*/
#ifndef NUM_COMMAND_H
#define NUM_COMMAND_H

#include "Expr_Command.h"

/**
 * @class  Num_Command
 * @Base Class Expr_Command
 *
 * @brief push a operand into stack
 */
template<typename T>
class Num_Command : public Expr_Command<T> 
{
public:
	Num_Command (T n);
	virtual ~Num_Command(void);

	/**
	* @brief   push the operand into stack
	* @param[in/out] Stack s that helps the evaluation   
	* @return  flag indicating success of failure
	*/
	virtual bool execute(Stack<T> & s);

private:
	/// operand	
	T n_;
}; 

#include "Num_Command.cpp"

#endif