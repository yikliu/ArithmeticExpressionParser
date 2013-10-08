#pragma once
#ifndef CREATE_MULTIPLY_NODE_FUNCTOR_CPP_
#define CREATE_MULTIPLY_NODE_FUNCTOR_CPP_

#include "Create_Multiply_Node_Functor.h"

//
// Create_Multiply_Node_Functor(void)
//
template<typename T>
Create_Multiply_Node_Functor<T>::Create_Multiply_Node_Functor(void)
{
}

//
// ~Create_Multiply_Node_Functor(void)
//
template<typename T>
Create_Multiply_Node_Functor<T>::~Create_Multiply_Node_Functor(void)
{
}

template<typename T>
int Create_Multiply_Node_Functor<T>::priority(void)
{
	return 1;
}

template<typename T>
Binary_Expr_Node<T> * Create_Multiply_Node_Functor<T>::operator()(void)
{
	return new Multiplication_Node<T>();
}


#endif // CREATE_MULTIPLY_NODE_FUNCTOR_CPP_
