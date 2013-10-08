/**
* @file    	Modulation_Node.cpp
* @brief    
* @details 
* @author   yikliu@umail.iu.edu
* @date     2012/04/07
*/
#pragma once
#ifndef MODULATION_NODE_CPP_
#define MODULATION_NODE_CPP_

#include "Modulation_Node.h"
#include "Expr_Node_Visitor.h"
template<typename T>
Modulation_Node<T>::Modulation_Node()
{
}

template<typename T>
Modulation_Node<T>::~Modulation_Node()
{
}

template<typename T>
static Modulation_Node<T> * Modulation_Node<T>:: _create(void)
{
	return new Modulation_Node<T>();
}

template<typename T>
bool Modulation_Node<T>::accept(Expr_Node_Visitor<T> & v)
{
	try
	{
		v.Visit_Modulation_Node(*this);
		return true;
	}
	catch(std::exception & e)
	{
		std::cout<<e.what()<<std::endl;
		return false;
	}
}

#endif // MODULATION_NODE_CPP_