/**
* @file    	Binary_Expr_Node.cpp
* @brief    
* @details 
* @author   yikliu@umail.iu.edu
* @date     2012/04/07
*/
#pragma once
#ifndef BINARY_EXPR_NODE_CPP_
#define BINARY_EXPR_NODE_CPP_

#include "Binary_Expr_Node.h"
#include "Expr_Node_Visitor.h"	

template<typename T>
Binary_Expr_Node<T>::Binary_Expr_Node(void)
{
	this->left_child = 0;
	this->right_child = 0;
}

template<typename T>
Binary_Expr_Node<T>::~Binary_Expr_Node(void)
{
	if(0 != this->left_child)
		delete this->left_child;
	if(0 != this->right_child)
		delete this->right_child;
}

template<typename T>
void Binary_Expr_Node<T>::setLefChild(Expr_Node<T> * left)
{
	this->left_child = left;
}	

template<typename T>
void Binary_Expr_Node<T>::setRightChild(Expr_Node<T> * right)
{
	this->right_child = right;
}

template<typename T>
Expr_Node<T> * Binary_Expr_Node<T>::getLeftChild(void) const
{
	return this->left_child;	
}

template<typename T>
Expr_Node<T> * Binary_Expr_Node<T>::getRightChild(void) const
{
	return this->right_child;	
}

#endif // BINARY_EXPR_NODE_CPP_