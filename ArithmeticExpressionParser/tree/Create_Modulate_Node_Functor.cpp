#pragma once
#ifndef CREATE_MODULATE_NODE_FUNCTOR_CPP_
#define CREATE_MODULATE_NODE_FUNCTOR_CPP_

#include "Create_Modulate_Node_Functor.h"

//
// Create_Modulate_Node_Functor(void)
//
template<typename T>
Create_Modulate_Node_Functor<T>::Create_Modulate_Node_Functor(void)
{
}

//
// ~Create_Modulate_Node_Functor(void)
//
template<typename T>
Create_Modulate_Node_Functor<T>::~Create_Modulate_Node_Functor(void)
{
}

template<typename T>
int Create_Modulate_Node_Functor<T>::priority(void)
{
	return 1; 
}

template<typename T>
Binary_Expr_Node<T> * Create_Modulate_Node_Functor<T>::operator()(void)
{
	return new Modulation_Node<T>();
}

#endif // CREATE_MODULATE_NODE_FUNCTOR_CPP_
