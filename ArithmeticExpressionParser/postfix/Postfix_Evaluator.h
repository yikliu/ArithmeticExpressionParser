/**
* @file     Postfix_Evaluator.h
* @brief	Evaluate the postfix expression to get the result
* @details 
* @author   yikliu@umail.iu.edu
* @date     3/17/2012
*/
#ifndef POSTFIX_EVALUATOR_H
#define POSTFIX_EVALUATOR_H

#include "Expr_Command.h"
#include "../datastructure/Array_Iterator.h"

/**
 * @class Postfix_Evaluator
 * @Base Class 
 *
 * @brief Evaluate the postfix expression to get the result
 */
template<typename T>
class Postfix_Evaluator
{
public:
	/// Default Constructor
	Postfix_Evaluator(void);/*{}*/
	
	/// Destructor
	~Postfix_Evaluator(void);/*{}*/

	/**
	* @brief   Actual Evaluation
	* @param[in]  iter   Array_Iterator for accessing the Array storing Expr_Command 
	* @param[out] result Ref to the result
	* @return   flag indicating success of failure of evaluation
	*/
	bool postfix_evalute(Array_Iterator<Expr_Command<T> *> & iter, T & result);
};

#include "Postfix_Evaluator.cpp"

#endif