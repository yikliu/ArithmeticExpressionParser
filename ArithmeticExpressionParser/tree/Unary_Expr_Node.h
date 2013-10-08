/**
* @file    	Unary_Expr_Node.h
* @brief    
* @details 
* @author   yikliu@umail.iu.edu
* @date     2012/04/07
*/
#pragma once
#ifndef UNARY_EXPR_NODE_H_
#define UNARY_EXPR_NODE_H_

#include "Expr_Node.h"

template<typename T>
class Unary_Expr_Node : public Expr_Node<T>
{
public:
	// Constructor
	Unary_Expr_Node(Expr_Node<T> * child);
	
	// Destructor
	virtual ~Unary_Expr_Node(void);

	virtual void accept(Expr_Node_Visitor<T> & v);

	virtual void visitNode(Expr_Node_Visitor<T> & v) = 0;
	
private:
	/// Unary Node only has one child
	Expr_Node<T> * child;

};

#include "Unary_Expr_Node.cpp"
#endif // UNARY_EXPR_NODE_H_

