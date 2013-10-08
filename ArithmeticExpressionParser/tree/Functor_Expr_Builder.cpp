#pragma once
#ifndef FUNCTOR_EXPR_BUILDER_CPP_
#define FUNCTOR_EXPR_BUILDER_CPP_

#include "Functor_Expr_Builder.h"

//
// Functor_Expr_Builder(void)
//
template<typename T>
Functor_Expr_Builder<T>::Functor_Expr_Builder(void)
{
	operators_ = new Stack<Create_Node_Functor<T> *>();
	operands_ = new Stack<Expr_Node<T> *>();
}

//
// ~Functor_Expr_Builder(void)
//
template<typename T>
Functor_Expr_Builder<T>::~Functor_Expr_Builder(void)
{
	if (operators_ != 0)
	{
		while(!operators_->is_empty())
		{
			Create_Node_Functor<T> * functor = operators_->top();
			if(functor !=0 )
				delete functor;
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
void Functor_Expr_Builder<T>::pop_and_push(void)
{  
	Create_Node_Functor<T> *  creat_node_functor = this->operators_->top();
	this->operators_->pop();
	
	Binary_Expr_Node<T> * binary_node = NULL;
	
	binary_node = (*creat_node_functor)(); // why we use functor in the first place
	
	if(operands_->size() < 2)
	{
		throw std::exception("Wrong Infix Format");
	}
		
	delete creat_node_functor; // avoid memory leak
	creat_node_functor = 0;
	
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
Expr_Node<T> * Functor_Expr_Builder<T>::get_expression(void)
{
	return operands_->top(); 
}

template<typename T>
void Functor_Expr_Builder<T>::build_number(T n)
{
	Number_Node<T> * node = new Number_Node<T>(n);
	operands_->push(node);
}

template<typename T>
int Functor_Expr_Builder<T>::priority(const std::string& op) const
{
   // empty function, use functor.priority instead	
}

template<typename T>
void Functor_Expr_Builder<T>::build_add_operator(void)
{	 
	Create_Node_Functor<T> * add_create_node = new Create_Add_Node_Functor<T>();
	this->build_operator(add_create_node);
}

template<typename T>
void Functor_Expr_Builder<T>::build_subtract_operator(void)
{
	Create_Node_Functor<T> * subtract_create_node = new Create_Subtract_Node_Functor<T>();
	this->build_operator(subtract_create_node);
}

template<typename T>
void Functor_Expr_Builder<T>::build_multiply_operator(void)
{
	Create_Node_Functor<T> * multiply_create_node = new Create_Multiply_Node_Functor<T>();
	this->build_operator(multiply_create_node);
}

template<typename T>
void Functor_Expr_Builder<T>::build_divide_operator(void)
{
	Create_Node_Functor<T> * divide_create_node = new Create_Divide_Node_Functor<T>();
	this->build_operator(divide_create_node);
}

template<typename T>
void Functor_Expr_Builder<T>::build_module_operator(void)
{
	Create_Node_Functor<T> * module_create_node = new Create_Modulate_Node_Functor<T>();
	this->build_operator(module_create_node);
}

template<typename T>
void Functor_Expr_Builder<T>::build_operator(Create_Node_Functor<T> * functor)
{	
	if (operators_->is_empty() || operators_->top()->priority() == 0 || operators_->top()->priority() > functor->priority())
    {
		operators_->push(functor);
    }
    else // clear operator stack and push new one onto it
    {
      do
      {
        pop_and_push();
      }
      while ( !operators_->is_empty() && (operators_->top()->priority() != 0) && (operators_->top()->priority() <= functor->priority()));
	  	 
	  operators_->push(functor);
    }    
}

template<typename T>
void Functor_Expr_Builder<T>::build_open_parenthesis(void)
{
	Create_Node_Functor<T> * open_paren_create_node = new Create_OP_Node_Functor<T>();
	operators_->push(open_paren_create_node);
}

template<typename T>
void Functor_Expr_Builder<T>::build_close_parenthesis(void)
{
	while ((!operators_->is_empty())&&(operators_->top()->priority() != 0))
    {		
		this->pop_and_push();
    }
	if(operators_->is_empty())
	{
		throw std::exception("Unbalanced Parentheses");	
	}
	Create_Node_Functor<T> * functor = operators_->top();
	operators_->pop();
	if (functor != 0)
	{
		delete functor;
		functor = 0;
	}
}

template<typename T>
void Functor_Expr_Builder<T>::build_end(void)
{
	while (!operators_->is_empty())
	{
		if(operators_->top()->priority() == 0)
		{
			throw std::exception("Unbalanced Parentheses");
		}
		this->pop_and_push();
	}
}

#endif // FUNCTOR_EXPR_BUILDER_CPP_
