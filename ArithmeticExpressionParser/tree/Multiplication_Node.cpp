/**
* @file    	Multiplicaiton_Node.cpp
* @brief    
* @details 
* @author   yikliu@umail.iu.edu
* @date     2012/04/07
*/
#pragma once
#ifndef MULTIPLICAITON_NODE_CPP_
#define MULTIPLICAITON_NODE_CPP_

#include "Multiplication_Node.h"
#include "Expr_Node_Visitor.h"
template<typename T>
Multiplication_Node<T>::Multiplication_Node(void)
{
}

template<typename T>
Multiplication_Node<T>::~Multiplication_Node(void)
{
}

template<typename T>
static Multiplication_Node<T> * Multiplication_Node<T>:: _create(void)
{
	return new Multiplication_Node<T>();
}


template<typename T>
bool Multiplication_Node<T>::accept(Expr_Node_Visitor<T> & v)
{
	v.Visit_Multiplication_Node(*this);
	return true;
}

#endif // MULTIPLICAITON_NODE_CPP_