/**
* @file    	Negative_Unary_Node.cpp
* @brief    
* @details 
* @author   yikliu@umail.iu.edu
* @date     2012/04/07
*/
#pragma once
#ifndef NEGATIVE_UNARY_NODE_CPP_
#define NEGATIVE_UNARY_NODE_CPP_

#include "Negative_Unary_Node.h"

template<typename T>
Negative_Unary_Node<T>::Negative_Unary_Node(Expr_Node<T> & child)
{
	this->child = child;
}

template<typename T>
Negative_Unary_Node<T>::~Negative_Unary_Node(void){}

template<typename T>
void Negative_Unary_Node<T>::visitNode(Expr_Node_Visitor<T> & v)
{
	v.Visit_Negative_Unary_Node(*this);		
}

template<typename T>
int Negative_Unary_Node<T>::priority(void)
{
	return 2;
}

#endif // NEGATIVE_UNARY_NODE_CPP_
