/**
* @file    	Binary_Expr_Node.h
* @brief    
* @details 
* @author   yikliu@umail.iu.edu
* @date     2012/04/07
*/
#pragma once
#ifndef BINARY_EXPR_NODE_H_
#define BINARY_EXPR_NODE_H_

#include "Expr_Node.h"
#include "Expr_Node_Visitor.h"

template<typename T>
class Expr_Node_Visitor;

template<typename T>
class Expr_Node;

template<typename T>
class Binary_Expr_Node : public Expr_Node<T>
{
public:
	// Default Constructor
	Binary_Expr_Node(void);

	// Destructor
	virtual ~Binary_Expr_Node(void);

	/**
	* @name    accept   
	* @brief   accept the visitor
	* @param[in]   	   
	* @return     
	* @exception  
	*/
	virtual bool accept(Expr_Node_Visitor<T> & v) = 0;

	//virtual void visitNode(Expr_Node_Visitor<T> & v) = 0;

	/**
	* @name   setLefChild    
	* @brief  set the left child 
	* @param[in]  pointer to a Expr_Node<T> 	   
	* @return     
	* @exception  
	*/
	void setLefChild(Expr_Node<T> * left);

	/**
	* @name   setRightChild    
	* @brief  set the right child 
	* @param[in]  pointer to a Expr_Node<T> 	   
	* @return     
	* @exception  
	*/
	void setRightChild(Expr_Node<T> * right);

	/**
	* @name     getLeftChild  
	* @brief	get the pointer to the left child
	* @param[in]   	   
	* @return   pointer to Expr_Node<T>  
	* @exception  
	*/
	Expr_Node<T> * getLeftChild(void) const;
	
	/**
	* @name    getRightChild   
	* @brief   get the pointer to the right child
	* @param[in]   	   
	* @return     
	* @exception  
	*/
	Expr_Node<T> * getRightChild(void) const;

protected:
	/// Left child
	Expr_Node<T> * left_child;
	
	/// Right child
	Expr_Node<T> * right_child;
};

#include "Binary_Expr_Node.cpp"
#endif // BINARY_EXPR_NODE_H_