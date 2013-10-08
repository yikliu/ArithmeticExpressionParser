/**
* @file    	Subtraction_Node.cpp
* @brief    
* @details 
* @author   yikliu@umail.iu.edu
* @date     2012/04/07
*/
#pragma once
#ifndef SUBTRACTION_NODE_CPP_
#define SUBTRACTION_NODE_CPP_

#include "Subtraction_Node.h"
#include "Expr_Node_Visitor.h"

template<typename T>
Subtraction_Node<T>::Subtraction_Node(void)
{
}

template<typename T>
Subtraction_Node<T>::~Subtraction_Node(void)
{
}

template<typename T>
static Subtraction_Node<T> * Subtraction_Node<T>:: _create(void)
{
	return new Subtraction_Node<T>();
}

template<typename T>
bool Subtraction_Node<T>::accept(Expr_Node_Visitor<T> & v)
{
	v.Visit_Subtraction_Node(*this);
	return true;
}

#endif // SUBTRACTION_NODE_CPP_