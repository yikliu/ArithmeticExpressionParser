/**
* @file    	Subtraction_Node.h
* @brief    
* @details 
* @author   yikliu@umail.iu.edu
* @date     2012/04/07
*/
#pragma once
#ifndef SUBTRACTION_NODE_H_
#define SUBTRACTION_NODE_H_
#include "Expr_Node_Visitor.h"
#include "Binary_Expr_Node.h"

template<typename T>
class Expr_Node_Visitor;

template<typename T>
class Binary_Expr_Node;

template<typename T>
class Subtraction_Node : public Binary_Expr_Node<T>
{
public:
	// Default Constructor
	Subtraction_Node(void);
	
	// Destructor
	virtual ~Subtraction_Node(void);

	static Subtraction_Node<T>* _create(void);

	/**
	* @name  accept     
	* @brief   accept the visitor
	* @param[in]  Expr_Node_Visitor<T>& reference to the visitor
	* @return  void   
	* @exception  
	*/
	bool accept(Expr_Node_Visitor<T> & v);
};

#include "Subtraction_Node.cpp"

#endif // SUBTRACTION_NODE_H_
