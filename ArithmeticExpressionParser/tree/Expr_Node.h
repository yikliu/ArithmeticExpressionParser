/**
* @file    	Expr_Node.h
* @brief    
* @details 
* @author   yikliu@umail.iu.edu
* @date     2012/04/08
*/
#pragma once
#ifndef EXPR_NODE_H_
#define EXPR_NODE_H_

#include "Expr_Node_Visitor.h"

template<typename T>
class Expr_Node_Visitor;

template<typename T>
class Expr_Node
{
public:
	//Constructor
	Expr_Node(void);
	
	//Destructor
	virtual ~Expr_Node(void);
		
	
	/**
	* @name       accept a visitor
	* @brief   
	* @param[in]  the visitor 	   
	* @return     
	* @exception  
	*/
	virtual bool accept(Expr_Node_Visitor<T> & v) = 0;
};

#include "Expr_Node.cpp"

#endif // EXPR_NODE_H_

