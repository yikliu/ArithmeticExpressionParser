//==============================================================================
/**
 * @file       Expr_Evaluator_Strategy.h
 * 
 * 
 *
 *
 * 
 */
//==============================================================================
#pragma once
#ifndef EXPR_EVALUATOR_STRATEGY_H_
#define EXPR_EVALUATOR_STRATEGY_H_

#include <string>
#include <iostream>

/**
 * @class 
 *
 * 
 */
template<typename T>
class Expr_Evaluator_Strategy
{
public:
	/// Default Constructor
	Expr_Evaluator_Strategy();
	// Destructor
	virtual ~Expr_Evaluator_Strategy();

	/**
	* @param[in]   	   
	* @return     
	* @exception  
	*/
	virtual bool parse_expression(const std::string & expr) = 0;
	
	/**
	* @param[in]   	   
	* @return     
	* @exception  
	*/
	virtual bool evaluate_expression (T & result) = 0;
	
};

#include "Expr_Evaluator_Strategy.cpp"
#endif // EXPR_EVALUATOR_STRATEGY_H_


