//==============================================================================
/**
 * @file       Node_Factory.h
 * 
 * 
 *
 *
 * 
 */
//==============================================================================
#pragma once
#ifndef NODE_FACTORY_H_
#define NODE_FACTORY_H_


#include "Expr_Node.h"
#include "Addition_Node.h"
#include "Subtraction_Node.h"
#include "Multiplication_Node.h"
#include "Modulation_Node.h"
#include "Division_Node.h"

/**
 * @class 
 *
 * 
 */
template<typename T>
class Node_Factory
{
public:
	/// Default Constructor
	Node_Factory(void);
	// Destructor
	virtual ~Node_Factory(void);

	Expr_Node<T> * create_add_node(void);
	Expr_Node<T> * create_subtract_node(void);
	Expr_Node<T> * create_multiply_node(void);
	Expr_Node<T> * create_divide_node(void);
	Expr_Node<T> * create_modulate_mode(void);

	
protected:
	
private:
};

#include "Node_Factory.cpp"

#endif // NODE_FACTORY_H_
