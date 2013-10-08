#pragma once
#ifndef CREATE_ADD_NODE_FUNCTOR_CPP_
#define CREATE_ADD_NODE_FUNCTOR_CPP_

#include "Create_Add_Node_Functor.h"

//
// Create_Add_Node_Functor(void)
//
template<typename T>
Create_Add_Node_Functor<T>::Create_Add_Node_Functor(void)
{
}

//
// ~Create_Add_Node_Functor(void)
//
template<typename T>
Create_Add_Node_Functor<T>::~Create_Add_Node_Functor(void)
{
}

template<typename T>
int Create_Add_Node_Functor<T>::priority(void)
{
	return 2; 
}

template<typename T>
Binary_Expr_Node<T> * Create_Add_Node_Functor<T>::operator()(void)
{
	return new Addition_Node<T>();
}
#endif // CREATE_ADD_NODE_FUNCTOR_CPP_
