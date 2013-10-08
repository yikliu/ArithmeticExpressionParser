/**
* @file    	Unary_Expr_Node.cpp
* @brief    
* @details 
* @author   yikliu@umail.iu.edu
* @date     2012/04/07
*/
#pragma once
#ifndef UNARY_EXPR_NODE_CPP_
#define UNARY_EXPR_NODE_CPP_
#include "Unary_Expr_Node.h"

template<typename T>
Unary_Expr_Node<T>::Unary_Expr_Node(Expr_Node<T> * child)
{
	this->child = child;	
}

template<typename T>
Unary_Expr_Node<T>::~Unary_Expr_Node(){}

template<typename T>
void Unary_Expr_Node<T>::accept(Expr_Node_Visitor<T> & v)
{
	this->child.accept(v);
	this->visitNode(v);
}

#endif // UNARY_EXPR_NODE_CPP_
