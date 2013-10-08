/**
* @file    	Expr_Node_Visitor.h
* @brief    
* @details 
* @author   yikliu@umail.iu.edu
* @date     2012/04/07
*/
#pragma once
#ifndef EXPR_NODE_VISITOR_H_
#define EXPR_NODE_VISITOR_H_

#include "Addition_Node.h"
#include "Subtraction_Node.h"
#include "Multiplication_Node.h"
#include "Division_Node.h"
#include "Modulation_Node.h"
#include "Number_Node.h"

template<typename T>
class Addition_Node;

template<typename T>
class Subtraction_Node;

template<typename T>
class Multiplication_Node;

template<typename T>
class Division_Node;

template<typename T>
class Modulation_Node;

template<typename T>
class Number_Node;

template<typename T>
class Expr_Node_Visitor 
{
public:
	// Default Constructor
	Expr_Node_Visitor(void);
	
	// Destructor
	virtual ~Expr_Node_Visitor(void);

	/**
	* @name   Visit_Addition_Node    
	* @brief   visit the addition node
	* @param[in]   	   
	* @return     
	* @exception  
	*/
	virtual void Visit_Addition_Node(const Addition_Node<T> & node) = 0; 

	/**
	* @name   Visit_Subtraction_Node    
	* @brief   visit the subtraction node
	* @param[in]   	   
	* @return     
	* @exception  
	*/
	virtual void Visit_Subtraction_Node(const Subtraction_Node<T> & node) = 0;

	/**
	* @name   Visit_Multiplication_Node    
	* @brief   visit the multiplication node
	* @param[in]   	   
	* @return     
	* @exception  
	*/
	virtual void Visit_Multiplication_Node(const Multiplication_Node<T> & node) = 0;

	/**
	* @name   Visit_Division_Node    
	* @brief   visit the division node
	* @param[in]   	   
	* @return     
	* @exception  
	*/
	virtual void Visit_Division_Node(const Division_Node<T> & node) = 0;

	/**
	* @name   Visit_Modulation_Node    
	* @brief   visit the modulation node
	* @param[in]   	   
	* @return     
	* @exception  
	*/
	virtual void Visit_Modulation_Node(const Modulation_Node<T> & node) = 0;

	/**
	* @name   Visit_Number_Node    
	* @brief   visit the number node
	* @param[in]   	   
	* @return     
	* @exception  
	*/
	virtual void Visit_Number_Node(const Number_Node<T> & node) = 0;
};

#include "Expr_Node_Visitor.cpp"

#endif // EXPR_NODE_VISITOR_H_