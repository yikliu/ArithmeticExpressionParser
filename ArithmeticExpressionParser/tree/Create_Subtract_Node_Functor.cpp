#pragma once
#ifndef CREATE_SUBTRACT_NODE_FUNCTOR_CPP_
#define CREATE_SUBTRACT_NODE_FUNCTOR_CPP_

#include "Create_Subtract_Node_Functor.h"

//
// Create_Subtract_Node_Functor(void)
//
template<typename T>
Create_Subtract_Node_Functor<T>::Create_Subtract_Node_Functor(void)
{
}

//
// ~Create_Subtract_Node_Functor(void)
//
template<typename T>
Create_Subtract_Node_Functor<T>::~Create_Subtract_Node_Functor(void)
{
}


template<typename T>
int Create_Subtract_Node_Functor<T>::priority(void)
{
	return 2; 
}

template<typename T>
Binary_Expr_Node<T> * Create_Subtract_Node_Functor<T>::operator()(void)
{
	return new Subtraction_Node<T>();
}

#endif // CREATE_SUBTRACT_NODE_FUNCTOR_CPP_
