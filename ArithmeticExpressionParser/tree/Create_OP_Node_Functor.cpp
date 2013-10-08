#pragma once
#ifndef CREATE_OP_NODE_FUNCTOR_CPP_
#define CREATE_OP_NODE_FUNCTOR_CPP_

#include "Create_OP_Node_Functor.h"

//
// Create_OP_Node_Functor(void)
//
template<typename T>
Create_OP_Node_Functor<T>::Create_OP_Node_Functor(void)
{
}

//
// ~Create_OP_Node_Functor(void)
//
template<typename T>
Create_OP_Node_Functor<T>::~Create_OP_Node_Functor(void)
{
}

template<typename T>
int Create_OP_Node_Functor<T>::priority(void)
{
	return 0; 
}

#endif // CREATE_OP_NODE_FUNCTOR_CPP_
