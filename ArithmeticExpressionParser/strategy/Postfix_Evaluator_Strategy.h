//==============================================================================
/**
 * @file       Postfix_Evaluator_Strategy.h
 * 
 * 
 *
 *
 * 
 */
//==============================================================================
#pragma once
#ifndef POSTFIX_EVALUATOR_STRATEGY_H_
#define POSTFIX_EVALUATOR_STRATEGY_H_

#include "../datastructure/Array.h"
#include "../datastructure/Array_Iterator.h"
#include "../datastructure/Stack.h"
#include "../postfix/Expr_Command.h"
#include "../postfix/Expr_Command_Factory.h"
#include "../postfix/Stack_Expr_Command_Factory.h"
#include "../postfix/Flyweight_Expr_Command_Factory.h"
#include "ExprTree_Evaluator_Strategy.h"

/**
 * @class 
 *
 * 
 */
template<typename T>
class Postfix_Evaluator_Strategy : public Expr_Evaluator_Strategy<T>
{
public:
	/// Default Constructor
	Postfix_Evaluator_Strategy();
	// Destructor
	virtual ~Postfix_Evaluator_Strategy();
	
	/**
	* Constructor to determine whether to use a flyweight factory
	* 
	* @param[in]   	   
	* @return     
	* @exception  
	*/
	Postfix_Evaluator_Strategy(bool use_flyweight);

	/**
	* 
	* @param[in]   	   
	* @return     
	* @exception  
	*/
	virtual bool parse_expression(const std::string & expr);
	
	/**
	* 
	* 
	* @param[in]   	   
	* @return     
	* @exception  
	*/
	virtual bool evaluate_expression(T & result);

private:
	int priority(const std::string& op) const;
	bool create_command(const std::string & token); 

private:
	/// pointer to an Array storing pointers to Expr_Command
	Array<Expr_Command<T>*> * p_postfix_array_;
	
	/// pointer to Abstract Factory for generating Expr_Command
	Expr_Command_Factory<T> * p_factory_;

	Stack<std::string *> * p_operator_stack_;		

	bool flyweight;
};

#include "Postfix_Evaluator_Strategy.cpp"

#endif // POSTFIX_EVALUATOR_STRATEGY_H_