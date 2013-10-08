#pragma once
#ifndef NODE_FACTORY_CPP_
#define NODE_FACTORY_CPP_

#include "Node_Factory.h"

//
// Node_Factory(void)
//
template<typename T>
Node_Factory<T>::Node_Factory(void)
{
}

//
// ~Node_Factory(void)
//
template<typename T>
Node_Factory<T>::~Node_Factory(void)
{
}

template<typename T>
Expr_Node<T> * Node_Factory<T>::create_add_node(void)
{
	return new Addition_Node<T>();
}

template<typename T>
Expr_Node<T> * Node_Factory<T>::create_subtract_node(void)
{
	return new Subtraction_Node<T>();
}

template<typename T>
Expr_Node<T> * Node_Factory<T>::create_multiply_node(void)
{
	return new Multiplicaiton_Node<T>();
}

template<typename T>
Expr_Node<T> * Node_Factory<T>::create_divide_node(void)
{
	return new Division_Node<T>();
}

template<typename T>
Expr_Node<T> * Node_Factory<T>::create_modulate_mode(void)
{
	return new Modulation_Node<T>();
}

#endif // NODE_FACTORY_CPP_
