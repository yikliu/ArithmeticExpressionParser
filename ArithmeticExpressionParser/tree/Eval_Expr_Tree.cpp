/**
* @file    	Eval_Expr_Tree.cpp
* @brief    
* @details 
* @author   yikliu@umail.iu.edu
* @date     2012/04/07
*/
#pragma once
#ifndef EVAL_EXPR_TREE_CPP_
#define EVAL_EXPR_TREE_CPP_

#include "Eval_Expr_Tree.h"

template<typename T>
Eval_Expr_Tree<T>::Eval_Expr_Tree(void)
{
	this->operands_ = new Stack<T>();
}

template<typename T>
Eval_Expr_Tree<T>::~Eval_Expr_Tree(void)
{
	if( 0 != this->operands_)
	{
		delete operands_;
	}
}

template<typename T>
void Eval_Expr_Tree<T>::Visit_Addition_Node(const Addition_Node<T> & node)
{	
	this->visitChildren(&node);

	T left = this->operands_->top();
	this->operands_->pop();
	T right = this->operands_->top();
	this->operands_->pop();
	result_ = left + right;
	this->operands_->push(result_);
}

template<typename T>
void Eval_Expr_Tree<T>::Visit_Subtraction_Node(const Subtraction_Node<T> & node)
{	
	this->visitChildren(&node);
	T left = this->operands_->top();
	this->operands_->pop();
	T right = this->operands_->top();
	this->operands_->pop();
	result_ = right - left;
	this->operands_->push(result_);
}

template<typename T>
void Eval_Expr_Tree<T>::Visit_Division_Node(const Division_Node<T> & node)
{	
	this->visitChildren(&node);
	
	T left = this->operands_->top();
	this->operands_->pop();

	T right = this->operands_->top();
	this->operands_->pop();

	if (left == 0)
		throw std::exception("Divide By Zero!");		
	
	result_ = right / left ;
	this->operands_->push(result_);
}

template<typename T>
void Eval_Expr_Tree<T>::Visit_Multiplication_Node(const Multiplication_Node<T> & node)
{
	this->visitChildren(&node);
	
	T left = this->operands_->top();
	this->operands_->pop();

	T right = this->operands_->top();
	this->operands_->pop();

	result_ = left * right;

	this->operands_->push(result_);
}

template<typename T>
void Eval_Expr_Tree<T>::Visit_Modulation_Node(const Modulation_Node<T> & node)
{	
	this->visitChildren(&node);
	
	T left = this->operands_->top();
	this->operands_->pop();

	T right = this->operands_->top();
	this->operands_->pop();

	int b = (int)left; //convert floating types to int before calculation
	if (b == 0)
		throw std::exception("Divide By Zero!");
	int a = (int)right;
	int r = a % b;
	result_ =  (T)(r * b < 0 ? r + b : r); //To account for negative operands
		
	this->operands_->push(result_);
}

template<typename T>
void Eval_Expr_Tree<T>::Visit_Number_Node(const Number_Node<T> & node)
{
	this->operands_->push(node.getNum());
}

template<typename T>
T Eval_Expr_Tree<T>::result(void) const
{
	return this->operands_->top();
}

template<typename T>
void Eval_Expr_Tree<T>::visitChildren(const Binary_Expr_Node<T> * node)
{
	Expr_Node<T> * left = node->getLeftChild();
	left->accept(*this);
	
	Expr_Node<T> * right = node->getRightChild();
	right->accept(*this);
}
#endif // EVAL_EXPR_TREE_CPP_
