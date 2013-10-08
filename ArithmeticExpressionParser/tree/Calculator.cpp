#pragma once
#ifndef CALCULATOR_CPP_
#define CALCULATOR_CPP_

#include <istream>
#include <bitset>
#include "Calculator.h"

/// Default constructor
template<typename T>
Calculator<T>::Calculator(void){}

/// Destructor
template<typename T>
Calculator<T>::~Calculator(void)
{
}

/// do_calculation
template<typename T>
bool Calculator<T>::do_calculation(std::istream & source, T & result)
{	
	std::string infix;					
	getline(source, infix);			
	
	// Author, there is no need to dynamically allocate the visitor
	// here since it is not being used past the scope of this function.
	//
	// Expr_Tree_Builder<T> * pbuilder = new Expr_Tree_Builder<T>();
	//
	// REPLY: builder is now constructed without dynamic allocation 
	Expr_Tree_Builder<T> builder;

	// infix-to-tree conversion
	if(!this->parse_expr(infix, builder))
	{
		return false;
	}
	
	Expr_Node<T> * root = builder.get_expression();

	if( 0 == root)
		return false;
	
	// Author, there is no need to dynamically allocate the visitor
	// here since it is not being used past the scope of this function.
	// 
	// Eval_Expr_Tree<T> * visitor = new Eval_Expr_Tree<T>();
	//
	// REPLY visitor now is constructed locally without dynamic allocation.
	Eval_Expr_Tree<T> visitor;

	if(!root->accept(visitor))
		return false;

	result = visitor.result();
	
	return true;
}

template<typename T>
bool Calculator<T>::parse_expr(const std::string & infix, Expr_Builder<T> & builder)
{
	std::istringstream input(infix);
	std::string token;

	// Use bit operation to determine the appropriate token to follow the previous one in a corret infix format
	enum symbol {open_paren = 1, num, op = 4, close_paren = 8};
	unsigned char acceptable_token;
	acceptable_token = open_paren | num; // Either an open parenthesis or a number can begin an infix expression.

	try
	{		
		while (!input.eof())
		{
			input >> token;
			if (token == "(")
			{
				if(acceptable_token & open_paren)
				{
					builder.build_open_parenthesis();
					acceptable_token = open_paren | num; //only an open parenthesis or a number can follow a open parenthesis.
				}
				else
				{
					throw std::exception("Bad Infix Format");					
				}
			}
			else if(token == "+" || token == "-" || token == "*" || token == "/" || token == "%")
			{
				if(acceptable_token & op)
				{
					if(token == "+")
					{
						builder.build_add_operator();
					}
					else if(token == "-")
					{
						builder.build_subtract_operator();
					}
					else if(token == "*")
					{
						builder.build_multiply_operator();
					}
					else if(token == "/")
					{
						builder.build_divide_operator();
					}
					else if(token == "%")
					{
						builder.build_module_operator();
					}
					acceptable_token = open_paren | num; //only an open parenthesis or a number can follow an operator.
				}
				else
				{
					throw std::exception("Bad Infix Format");
				}				
			}
			else if(token == ")")
			{
				if(acceptable_token & close_paren)
				{
					builder.build_close_parenthesis();
					acceptable_token = op | close_paren; //Only operator and close parenthesis can follow a close parenthesis.
				}
				else
				{
					throw std::exception("Bad Infix Format");
				}		
			}
			else //it's a number or contains wrong character
			{
				if(acceptable_token & num)
				{
					std::istringstream stream (token);
					T t;
					if(stream >> t)			
						builder.build_number(t);
					else
						throw std::exception("Unrecognized Character");
					
					acceptable_token = op | close_paren;//Only operator and close parenthesis can follow a number.
				}
				else
				{
					throw std::exception("Bad Infix Format");
				}					
			}		
		}
		builder.build_end();
	}
	catch (std::exception & e)
	{
		std::cout<<e.what()<<std::endl;
		return false;
	}

	return true;
}



#endif // calculator_cpp__
