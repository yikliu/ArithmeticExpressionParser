/**
* @file    	Expr_Tree_Builder.cpp
* @brief    
* @details 
* @author   yikliu@umail.iu.edu
* @date     2012/04/07
*/
#pragma once
#ifndef EXPR_TREE_BUILDER_CPP_
#define EXPR_TREE_BUILDER_CPP_

#include "Expr_Tree_Builder.h"

template<typename T>
Expr_Tree_Builder<T>::Expr_Tree_Builder(void)
{
	operators_ = new Stack<std::string *>();
	operands_ = new Stack<Expr_Node<T> *>();
}

template<typename T>
Expr_Tree_Builder<T>::~Expr_Tree_Builder(void)
{
	if (operators_ != 0)
	{
		while(!operators_->is_empty())
		{
			std::string * str = operators_->top();
			if(str !=0 )
				delete str;
			operators_->pop();
		}		
		delete operators_;
	}
	if (operands_ != 0)
	{
		delete operands_;
	}	
}

template<typename T>
void Expr_Tree_Builder<T>::pop_and_push(void)
{  
	std::string *  token = this->operators_->top();
	this->operators_->pop();
	
	Binary_Expr_Node<T> * binary_node = NULL;
	
	if(*token == "+")
	{
		binary_node = new Addition_Node<T>();
	}
	else if(*token == "-")
	{
		binary_node = new Subtraction_Node<T>();
	}
	else if(*token == "*")
	{
		binary_node = new Multiplication_Node<T>();
	}
	else if(*token == "/")
	{
		binary_node = new Division_Node<T>();
	}
	else if(*token == "%")
	{
		binary_node = new Modulation_Node<T>();
	}
		
	delete token; // avoid memory leak
	token = 0;
	
	if(operands_->size() < 2)
	{
		throw std::exception("Wrong Infix Format");
	}

	Expr_Node<T> * right_node = operands_->top();
	operands_->pop();

	Expr_Node<T> * left_node =  operands_->top();
	operands_->pop();

	if(0 != binary_node) 
	{
		binary_node->setLefChild(left_node);
		binary_node->setRightChild(right_node);
		operands_->push(binary_node);
	}	
}


template<typename T>
Expr_Node<T> * Expr_Tree_Builder<T>::get_expression(void)
{
	return operands_->top(); 
}

template<typename T>
void Expr_Tree_Builder<T>::build_number(T n)
{
	Number_Node<T> * node = new Number_Node<T>(n);
	operands_->push(node);
}

template<typename T>
int Expr_Tree_Builder<T>::priority(const std::string& op) const
{
	int temp;
	if (op == "*" || op == "/" || op == "%")
		temp = 1;
	else  if (op == "+" || op == "-")
		temp = 2;
	return temp;
}

template<typename T>
void Expr_Tree_Builder<T>::build_add_operator(void)
{
	std::string token("+");
	this->build_operator(token);
}

template<typename T>
void Expr_Tree_Builder<T>::build_subtract_operator(void)
{
	this->build_operator(std::string("-"));
}

template<typename T>
void Expr_Tree_Builder<T>::build_multiply_operator(void)
{
	this->build_operator(std::string("*"));
}

template<typename T>
void Expr_Tree_Builder<T>::build_divide_operator(void)
{
	this->build_operator(std::string("/"));
}

template<typename T>
void Expr_Tree_Builder<T>::build_module_operator(void)
{
	this->build_operator(std::string("%"));
}

template<typename T>
void Expr_Tree_Builder<T>::build_operator(std::string & token)
{	
	if (operators_->is_empty() || *operators_->top() == "(" || (this->priority(*operators_->top()) > this->priority(token)))
    {
		std::string * op= new std::string(token); 
		operators_->push(op);
    }
    else // clear operator stack and push new one onto it
    {
      do
      {
        pop_and_push();
      }
      while ( !operators_->is_empty() && *operators_->top() != "(" && (this->priority(*operators_->top()) <= this->priority(token)));

	  std::string * op = new std::string(token);
	  operators_->push(op);
    }    
}

template<typename T>
void Expr_Tree_Builder<T>::build_open_parenthesis(void)
{
	operators_->push(new std::string("("));
}

template<typename T>
void Expr_Tree_Builder<T>::build_close_parenthesis(void)
{
	while ((!operators_->is_empty())&&(*operators_->top() != "("))
    {		
		this->pop_and_push();
    }
	if(operators_->is_empty())
	{
		throw std::exception("Unbalanced Parentheses");	
	}
	std::string * token = operators_->top();
	operators_->pop();
	if (token != 0)
	{
		delete token;
		token = 0;
	}
}

template<typename T>
void Expr_Tree_Builder<T>::build_end(void)
{
	while (!operators_->is_empty())
	{
		if(*operators_->top() == "(")
		{
			throw std::exception("Unbalanced Parentheses");
		}
		this->pop_and_push();
	}
}

#endif // EXPR_TREE_BUILDER_CPP_
