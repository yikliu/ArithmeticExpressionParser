/**
* @file    	Eval_Expr_Tree.h
* @brief    
* @details 
* @author   yikliu@umail.iu.edu
* @date     2012/04/07
*/
#pragma once
#ifndef EVAL_EXPR_TREE_H_
#define EVAL_EXPR_TREE_H_

#include "../datastructure/Stack.h"
#include "Expr_Node_Visitor.h"

template<typename T>
class Eval_Expr_Tree : public Expr_Node_Visitor<T>
{
public:
	// Default Constructor
	Eval_Expr_Tree(void);
	
	// Destructor
	virtual ~Eval_Expr_Tree(void);

	/**
	* @name   Visit_Addition_Node    
	* @brief   visit the addition node
	* @param[in]   	   
	* @return     
	* @exception  
	*/
	virtual void Visit_Addition_Node(const Addition_Node<T> & node); 
	
	/**
	* @name   Visit_Subtraction_Node    
	* @brief   visit the subtraction node
	* @param[in]   	   
	* @return     
	* @exception  
	*/
	virtual void Visit_Subtraction_Node(const Subtraction_Node<T> & node);
	
	/**
	* @name   Visit_Multiplication_Node    
	* @brief   visit the multiplication node
	* @param[in]   	   
	* @return     
	* @exception  
	*/
	virtual void Visit_Multiplication_Node(const Multiplication_Node<T> & node);
	
	/**
	* @name   Visit_Division_Node    
	* @brief   visit the division node
	* @param[in]   	   
	* @return     
	* @exception  
	*/
	virtual void Visit_Division_Node(const Division_Node<T> & node);
	
	/**
	* @name   Visit_Modulation_Node    
	* @brief   visit the modulation node
	* @param[in]   	   
	* @return     
	* @exception  
	*/
	virtual void Visit_Modulation_Node(const Modulation_Node<T> & node);
	
	/**
	* @name   Visit_Number_Node    
	* @brief   visit the number node
	* @param[in]   	   
	* @return     
	* @exception  
	*/
	virtual void Visit_Number_Node(const Number_Node<T> & node);

	/**
	* @name   result    
	* @brief  get the result
	* @param[in]   	   
	* @return     
	* @exception  
	*/
	T result (void) const;

private:
	/**
	* @name   visitChildren    
	* @brief   A private method for binary expression node to visit left child and then right child
	* @param[in]  const Binary_Expr_Node<T> * nod 	   
	* @return     void
	* @exception  
	*/
	void visitChildren(const Binary_Expr_Node<T> * node);

private:
	T result_;
	/// Stack for storing intermediary results
	Stack<T> * operands_;
};

#include "Eval_Expr_Tree.cpp"

#endif // EVAL_EXPR_TREE_H_