#pragma once
#ifndef INFIX_PARSER_CPP
#define INFIX_PARSER_CPP

#include <iostream>
#include <sstream>
#include <string>

#include "Infix_Postfix_Parser.h"

/// Default constructor
template<typename T>
Infix_Postfix_Parser<T>::Infix_Postfix_Parser(void)	
	:p_postfix_string(0)
{	
	p_postfix_string = new std::string();
}

/// Destructor
template<typename T>
Infix_Postfix_Parser<T>::~Infix_Postfix_Parser(void)
{
	if (p_postfix_string != 0)
		delete p_postfix_string;
}

/// infix_to_postfix
template<typename T>
bool Infix_Postfix_Parser<T>::inflix_to_postfix(const std::string & infix, 
												Expr_Command_Factory<T> & factory,
												Array<Expr_Command<T>*> & postfix_array)
{
	std::istringstream input (infix);
	std::string token;	
	Stack<std::string *> temp;		

	while (!input.eof())
	{		
		input >> token;
		// if token is an operator
		if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%")
		{
			while (!temp.is_empty() && !(*temp.top()=="(") && this->priority(*temp.top()) <= this->priority(token))
			{
				this->output_to_array(*temp.top(), factory, postfix_array);
				temp.pop();
			}
			temp.push(new std::string(token));
		} 
		else if (token == "(") 
		{
			temp.push(new std::string(token));
		} 
		else if (token == ")") 
		{
			while (*temp.top() != "(") 
			{					
				this->output_to_array(*temp.top(), factory,postfix_array);
				temp.pop();
			}
			temp.pop();
		} 
		else // if token is a number
		{
			this->output_to_array(token, factory, postfix_array);
		}
	}

	while (!temp.is_empty()) 
	{
		this->output_to_array(*temp.top(), factory, postfix_array);
		temp.pop();
	}
	
	return true;
}

/// output_to_array
template<typename T>
bool Infix_Postfix_Parser<T>::output_to_array(const std::string & token,
											  Expr_Command_Factory<T> & factory,
											  Array<Expr_Command<T>*> & postfix_array) const
{	
	Expr_Command<T> * cmd = 0;
	
	// creating appropriate command object based on token
	if (token == "+")
		cmd = factory.create_add_command();
	else if (token == "-")
		cmd = factory.create_subtract_command();
	else if (token == "*")
		cmd = factory.create_multiply_command();
	else if (token == "/")
		cmd = factory.create_divide_command();
	else if (token == "%")
		cmd = factory.create_module_command();
	else
	{
		//Using isstringstream for converting string to numeric values
		std::istringstream stream (token);
		T t;
		stream >> t;
		cmd = factory.create_num_command(t);
	}		

	p_postfix_string->append(token);
	postfix_array.add(cmd);
	return true;
}

/// priority
template<typename T>
int Infix_Postfix_Parser<T>::priority(const std::string& op) const
{
	int temp;
	if (op == "*" || op == "/" || op == "%")
		temp = 1;
	else  if (op == "+" || op == "-")
		temp = 2;
	return temp;
}

/// get_postfix
template<typename T>
std::string & Infix_Postfix_Parser<T>::get_postfix(void) const
{
	return * p_postfix_string;
}

/// clear_postfix_string
template<typename T>
void Infix_Postfix_Parser<T>::clear_postfix_string(void)
{
	p_postfix_string->clear();
}

#endif