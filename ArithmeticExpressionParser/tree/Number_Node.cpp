/**
* @file    	Number_Node.cpp
* @brief    
* @details 
* @author   yikliu@umail.iu.edu
* @date     2012/04/07
*/
#pragma once
#ifndef NUMBER_NODE_CPP_
#define NUMBER_NODE_CPP_

#include "Number_Node.h"
#include "Expr_Node_Visitor.h"

template<typename T>
Number_Node<T>::Number_Node(T num)
	:number_(num)
{	
}

template<typename T>
Number_Node<T>::~Number_Node(void){}

template<typename T>
bool Number_Node<T>::accept(Expr_Node_Visitor<T> & v)
{
	v.Visit_Number_Node(*this);
	return true;
}

template<typename T>
T Number_Node<T>::getNum(void) const
{
	return this->number_;
}

#endif // NUMBER_NODE_CPP_