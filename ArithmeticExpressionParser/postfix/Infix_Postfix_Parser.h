/**
* @file     Infix_Postfix_Parser.h
* @brief	Parser for convert infix format to postfix format
* @details 
* @author   yikliu@umail.iu.edu
* @date     3/17/2012
*/
#pragma once
#ifndef INFIX_PARSER_H
#define INFIX_PARSER_H

#include "../datastructure/Array.h"
#include "../datastructure/Array_Iterator.h"
#include "Expr_Command.h"
#include "Expr_Command_Factory.h"

/**
 * @class Infix_Postfix_Parser
 * @Base Class 
 *
 * @brief Parser for convert infix format to postfix format
 */
template<typename T>
class Infix_Postfix_Parser
{
public:	
	/// Default Constructor
	Infix_Postfix_Parser(void);

	/// Destructor
	~Infix_Postfix_Parser(void);
	
	/**
	* @brief method to do the actual conversion  
	* @param[in]  infix  input infix string
	* @param[in]  factory  Ref to Expr_Command factory object
	* @param[out] postfix_array  output array for storing Expr_Command in postfix order
	* @return   flag indicating success or failure of conversion 
	*/
	bool inflix_to_postfix(const std::string & infix, 
						   Expr_Command_Factory<T> & factory,
						   Array<Expr_Command<T>*> & postfix_array);

	/**
	* @brief   get the postfix string
	* @param   void
	* @return  postfix string
	*/
	std::string & get_postfix(void) const;
	
	/**
	* @brief   clear the string to empty
	* @param   void
	* @return  void
	*/
	void clear_postfix_string(void);
private:	
	/**
	* @brief   output intermediary results to Array 
	* @param[in]  token	   string token representing command type
	* @param[in]  factory  Ref to Expr_Command factory object
	* @param[out] postfix_array  output array for storing Expr_Command in postfix order  
	* @return  flag indicating success or failure of conversion
	*/
	bool output_to_array(const std::string & token,
						 Expr_Command_Factory<T> & factory,
						 Array<Expr_Command<T>*> & postfix_array) const;
	
	/**
	* @brief   get the precedence of operators
	* @param   op   operators
	* @return  int  relative priority of operators
	*/
	int priority(const std::string & op) const;

private:
	/// string that tracks and stores postfix string
	std::string * p_postfix_string;
};

#include "Infix_Postfix_Parser.cpp"
#endif