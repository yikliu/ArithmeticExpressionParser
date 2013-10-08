/**
* @file    	Addition_Node.cpp
* @brief    
* @details 
* @author   yikliu@umail.iu.edu
* @date     2012/04/07
*/
#pragma once
#ifndef ADDITION_NODE_CPP_
#define ADDITION_NODE_CPP_

#include "Addition_Node.h"
#include "Expr_Node_Visitor.h"

template<typename T>
Addition_Node<T>::Addition_Node(void)
{
}

template<typename T>
Addition_Node<T>::~Addition_Node(void)
{
}

template<typename T>
static Addition_Node<T> * Addition_Node<T>:: _create(void)
{
	return new Addition_Node<T>();
}

template<typename T>
bool Addition_Node<T>::accept(Expr_Node_Visitor<T> & v)
{
	v.Visit_Addition_Node(*this);
	return true;
}

#endif // ADDITION_NODE_CPP_