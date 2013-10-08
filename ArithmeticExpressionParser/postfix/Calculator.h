/**
* @file     calculator.h
* @brief	Wrapper class for representing calculator
* @details 
* @author   yikliu@umail.iu.edu
* @date     3/17/2012
*/
#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include <iostream>

#include "../datastructure/Array.h"
#include "Expr_Command.h"
#include "Stack_Expr_Command_Factory.h"
#include "Infix_Postfix_Parser.h"
#include "Postfix_Evaluator.h"

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
	* @brief   get the postfix string after conversion, only to be called
	*		   after do_calculation is successful
	* @param   void
	* @return  std::string  the result of infix-to-postfix conversion
	*/
	std::string & get_postfix(void) const;

	/**
	* @brief   Reset the calculator to initial state
	* @param   void
	* @return  void
	*/
	void reset(void);

private:
	/// pointer to an Array storing pointers to Expr_Command
	Array<Expr_Command<T>*> * p_postfix_array_;
	
	/// pointer to an Array_Iterator associated with Array
	Array_Iterator<Expr_Command<T> *> * p_iter_;
	
	/// pointer to Infix_Postfix_Parser
	Infix_Postfix_Parser<T> * p_parser_;
	
	/// pointer to postfix evaluator
	Postfix_Evaluator<T> * p_evaluator_;
	
	/// pointer to Abstract Factory for generating Expr_Command
	Expr_Command_Factory<T> * p_factory_;
};

#include "calculator.cpp"

#endif // calculator_h__
