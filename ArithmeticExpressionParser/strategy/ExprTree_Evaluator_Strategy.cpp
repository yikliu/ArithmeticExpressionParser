#pragma once
#ifndef EXPRTREE_EVALUATOR_CPP_
#define EXPRTREE_EVALUATOR_CPP_

#include "ExprTree_Evaluator_Strategy.h"

//
// ExprTree_Evaluator_Strategy(void)
//
template<typename T>
ExprTree_Evaluator_Strategy<T>::ExprTree_Evaluator_Strategy(bool functor)
	:_root(0),
	use_functor(functor)
{	
}

//
// ~ExprTree_Evaluator_Strategy(void)
//
template<typename T>
ExprTree_Evaluator_Strategy<T>::~ExprTree_Evaluator_Strategy(void)
{
	if (_root != 0)
	{
		delete _root;
	}
}

//
// parse_expression
//
template<typename T>
bool ExprTree_Evaluator_Strategy<T>::parse_expression(const std::string & expr)
{
	std::istringstream input(expr);
	std::string token;

	// Use bit operation to determine the appropriate token to follow the previous one  
	enum symbol {open_paren = 1, num, op = 4, close_paren = 8};
	unsigned char acceptable_token;
	acceptable_token = open_paren | num; // Either an open parenthesis or a number can begin an infix expression.

	Expr_Builder<T> * builder;
	if(this->use_functor)
		builder = new Functor_Expr_Builder<T>();
	else
		builder = new Expr_Tree_Builder<T>();

	try
	{		
		while (!input.eof())
		{
			input >> token;
			if (token == "(")
			{
				if(acceptable_token & open_paren)
				{
					builder->build_open_parenthesis();
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
						builder->build_add_operator();
					}
					else if(token == "-")
					{
						builder->build_subtract_operator();
					}
					else if(token == "*")
					{
						builder->build_multiply_operator();
					}
					else if(token == "/")
					{
						builder->build_divide_operator();
					}
					else if(token == "%")
					{
						builder->build_module_operator();
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
				if(acceptable_token & close_paren){				
					builder->build_close_parenthesis();
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
						builder->build_number(t);
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
		builder->build_end();
	}
	catch (std::exception & e)
	{
		if (builder != 0)
			delete builder;
		std::cout<<e.what()<<std::endl;
		return false;
	}
	
	_root = builder->get_expression();

	if(builder != 0)
		delete builder;
	return true;
}

template<typename T>
bool ExprTree_Evaluator_Strategy<T>::evaluate_expression(T & result)
{
	if( 0 == _root)
		return false;
	
	Eval_Expr_Tree<T> visitor;

	if(!_root->accept(visitor))
		return false;

	result = visitor.result();
	return true;
}

#endif // EXPRTREE_EVALUATOR_CPP_
