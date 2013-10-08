/**
* @file    	Negative_Unary_Node.h
* @brief    
* @details 
* @author   yikliu@umail.iu.edu
* @date     2012/04/07
*/
#pragma once
#ifndef NEGATIVE_UNARY_NODE_H_
#define NEGATIVE_UNARY_NODE_H_

#include "Unary_Expr_Node.h"

template<typename T>
class Negative_Unary_Node : public Unary_Expr_Node<T>
{
public:
	// Constructor
	Negative_Unary_Node(Expr_Node<T> & child);

	// Destructor
	virtual ~Negative_Unary_Node(void);
	
	/**
	* @name       
	* @brief   
	* @param[in]   	   
	* @return     
	* @exception  
	*/
	virtual void visitNode(Expr_Node_Visitor<T> & v);
	int priority (void);
};

#include "Negative_Unary_Node.cpp"
#endif // NEGATIVE_UNARY_NODE_H_