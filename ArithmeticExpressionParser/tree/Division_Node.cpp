/**
* @file    	Division_Node.cpp
* @brief    
* @details 
* @author   yikliu@umail.iu.edu
* @date     2012/04/07
*/
#pragma once
#ifndef DIVISION_NODE_CPP_
#define DIVISION_NODE_CPP_
#include "Division_Node.h"
#include "Expr_Node_Visitor.h"

template<typename T>
Division_Node<T>::Division_Node(){}

template<typename T>
Division_Node<T>::~Division_Node(){}

template<typename T>
static Division_Node<T> * Division_Node<T>:: _create(void)
{
	return new Division_Node<T>();
}

template<typename T>
bool Division_Node<T>::accept(Expr_Node_Visitor<T> & v)
{
	try
	{
		v.Visit_Division_Node(*this);
		return true;
	}	
	catch (std::exception & e)
	{
		std::cout<<e.what()<<std::endl;
		return false;
	}	
}

#endif // DIVISION_NODE_CPP_