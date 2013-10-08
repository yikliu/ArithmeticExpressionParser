#pragma once
#ifndef CREATE_NODE_CPP_
#define CREATE_NODE_CPP_

#include "Create_Node_Functor.h"

//
// Create_Node(void)
//
template<typename T>
Create_Node_Functor<T>::Create_Node_Functor(void)	
{
}

//
// ~Create_Node(void)
//
template<typename T>
Create_Node_Functor<T>::~Create_Node_Functor(void)	
{
}

template<typename T>
Binary_Expr_Node<T> * Create_Node_Functor<T>::operator()(void)
{
	return 0;
}


#endif // CREATE_NODE_CPP_
