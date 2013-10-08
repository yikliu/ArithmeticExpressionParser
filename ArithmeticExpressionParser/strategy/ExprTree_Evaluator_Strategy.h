//==============================================================================
/**
 * @file       ExprTree_Evaluator_Strategy..h
 * 
 * 
 *
 *
 * 
 */
//==============================================================================
#pragma once
#ifndef EXPRTREE_EVALUATOR_H_
#define EXPRTREE_EVALUATOR_H_

#include <iostream>
#include <sstream>

#include "Expr_Evaluator_Strategy.h"
#include "../datastructure/Array.h"
#include "../tree/Expr_Builder.h"
#include "../tree/Expr_Tree_Builder.h"
#include "../tree/Functor_Expr_Builder.h"
#include "../tree/Eval_Expr_Tree.h"

/**
 * @class 
 *
 * 
 */
template<typename T>
class ExprTree_Evaluator_Strategy : public Expr_Evaluator_Strategy<T>
{
public:
	/// Constructor
	ExprTree_Evaluator_Strategy(bool functor);
	// Destructor
	virtual ~ExprTree_Evaluator_Strategy();
	
	/**
	* 
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
	Expr_Node<T> * _root;
	bool  use_functor;
};

#include "ExprTree_Evaluator_Strategy.cpp"

#endif // EXPRTREE_EVALUATOR_H_
