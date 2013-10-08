/**
* @file    	Modulation_Node.h
* @brief    
* @details 
* @author   yikliu@umail.iu.edu
* @date     2012/04/07
*/
#pragma once
#ifndef MODULATION_NODE_H_
#define MODULATION_NODE_H_
#include "Expr_Node_Visitor.h"
#include "Binary_Expr_Node.h"

template<typename T>
class Expr_Node_Visitor;

template<typename T>
class Binary_Expr_Node;

template<typename T>
class Modulation_Node : public Binary_Expr_Node<T>
{
public:
	// Default Constructor
	Modulation_Node(void);


	// Destructor
	virtual ~Modulation_Node(void);

	static Modulation_Node<T>* _create(void);

	/**
	* @name  accept     
	* @brief   accept the visitor
	* @param[in]  Expr_Node_Visitor<T>& reference to the visitor
	* @return  void   
	* @exception  
	*/
	bool accept(Expr_Node_Visitor<T> & v);
};

#include "Modulation_Node.cpp"

#endif // MODULATION_NODE_H_