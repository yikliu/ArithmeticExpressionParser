/**
* @file     calculator.h
* @brief	Wrapper class for representing calculator
* @details 
* @author   yikliu@umail.iu.edu
* @date     3/17/2012
*/
#pragma once
#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include <iostream>
#include <sstream>

#include "../datastructure/Array.h"
#include "Expr_Builder.h"
#include "Expr_Tree_Builder.h"
#include "Eval_Expr_Tree.h"


/**
 * @class Calculator
 *
 * @brief Class representing Calculator
 */
template<typename T>
class Calculator{
public:
	///Default Constructor	
	Calculator(void);

	///Destructor
	~Calculator(void);
	
	/**
	* @brief   Actual calculation command
	* @param[in]      source          STDIN source
	* @param[out]     result          output parameter for placing the result.
	* @return		  bool			  flag indicating success or not.	
	*/
	bool do_calculation(std::istream & source, T & result);
	
	/**
	* @name  parse_expr     
	* @brief  parse the infix to tree
	* @param[in]   	   
	* @return     
	* @exception  
	*/
	bool parse_expr(const std::string & infix, Expr_Builder<T> & builder);
	
};

#include "calculator.cpp"

#endif // calculator_h__
