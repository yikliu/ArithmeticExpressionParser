#pragma once
#ifndef CREATE_DIVIDE_NODE_FUNCTOR_CPP_
#define CREATE_DIVIDE_NODE_FUNCTOR_CPP_

#include "Create_Divide_Node_Functor.h"

//
// Create_Divide_Node_Functor(void)
//
template<typename T>
Create_Divide_Node_Functor<T>::Create_Divide_Node_Functor(void)
{
}

//
// ~Create_Divide_Node_Functor(void)
//
template<typename T>
Create_Divide_Node_Functor<T>::~Create_Divide_Node_Functor(void)
{
}

template<typename T>
int Create_Divide_Node_Functor<T>::priority(void)
{
	return 1; 
}

template<typename T>
Binary_Expr_Node<T> * Create_Divide_Node_Functor<T>::operator()(void)
{
	return new Division_Node<T>();
}

#endif // CREATE_DIVIDE_NODE_FUNCTOR_CPP_
