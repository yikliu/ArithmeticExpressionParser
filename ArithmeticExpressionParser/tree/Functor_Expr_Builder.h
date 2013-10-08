//==============================================================================
/**
 * @file       Functor_Expr_Builder.h
 * 
 * 
 *
 *
 * 
 */
//==============================================================================
#pragma once
#ifndef FUNCTOR_EXPR_BUILDER_H_
#define FUNCTOR_EXPR_BUILDER_H_

#include <string>
#include "../datastructure/Stack.h"
#include "Expr_Node.h"
#include "Number_Node.h"
#include "Expr_Builder.h"

#include "Create_Node_Functor.h"
#include "Create_Add_Node_Functor.h"
#include "Create_Subtract_Node_Functor.h"
#include "Create_Multiply_Node_Functor.h"
#include "Create_Divide_Node_Functor.h"
#include "Create_Modulate_Node_Functor.h"
#include "Create_OP_Node_Functor.h"

/**
 * @class 
 *
 * 
 */
template<typename T>
class Functor_Expr_Builder : public Expr_Builder<T>
{
public:

	/// Default Constructor
	Functor_Expr_Builder(void);
	// Destructor
	virtual ~Functor_Expr_Builder(void);
	
	
	/**
	* @name  build_number     
	* @brief   build the number operand into tree
	* @param[in]  T n the number 	   
	* @return     
	* @exception  
	*/
	virtual void build_number(T n);
	
	/**
	* @name  build_add_operator     
	* @brief   build the add operator into the tree
	* @param[in]   	   
	* @return     
	* @exception  
	*/
	virtual void build_add_operator(void);

	/**
	* @name   build_subtract_opeartor    
	* @brief   build the subtract operator into the tree
	* @param[in]   	   
	* @return     
	* @exception  
	*/
	virtual void build_subtract_operator(void);

	/**
	* @name  build_multiply_operator     
	* @brief   build the multply operator into the tree
	* @param[in]   	   
	* @return     
	* @exception  
	*/
	virtual void build_multiply_operator(void);

	/**
	* @name    build_divide_operator   
	* @brief   build the divide operator into the tree 
	* @param[in]   	   
	* @return     
	* @exception  
	*/
	virtual void build_divide_operator(void);

	/**
	* @name     build_module_operator  
	* @brief    build the modulation operator into the tree
	* @param[in]   	   
	* @return     
	* @exception  
	*/
	virtual void build_module_operator(void);
	
	/**
	* @name  build_operator     
	* @brief   A method for handling all the bindary operators
	* @param[in]   	   
	* @return     
	* @exception  
	*/
	virtual void build_operator(Create_Node_Functor<T> * functor);
	
	/**
	* @name   build_open_parenthesis    
	* @brief   handle the open parenthesis
	* @param[in]   	   
	* @return     
	* @exception  
	*/
	virtual void build_open_parenthesis(void);

	/**
	* @name   build_close_parenthesis      
	* @brief  handle the close parenthesis  
	* @param[in]   	   
	* @return     
	* @exception  
	*/
	virtual void build_close_parenthesis(void);

	/**
	* @name   build_end    
	* @brief  finalising the tree construction after reading the last token from infix 
	* @param[in]   	   
	* @return     
	* @exception  
	*/
	virtual void build_end(void);

	/**
	* @name    get_expression   
	* @brief   return the root node in order to let the client access the expression tree.
	* @param[in]   	   
	* @return     
	* @exception  
	*/
	virtual Expr_Node<T> * get_expression (void);

private:
	/**
	* @name    pop_and_push   
	* @brief   private method to make two pops from operand stack, one pop from operator stack, make a parent node with the				*		   operator and assign the previous two operands as its left and right chilren.
	* @param[in]   	   
	* @return     
	* @exception  
	*/
	void pop_and_push(void);

	/**
	* @name   priority    
	* @brief   give relative priority for operators
	* @param[in]  string& operator 	   
	* @return     
	* @exception  
	*/
	int priority(const std::string & op) const;
private:
	/// A stack for storing operands
	Stack<Expr_Node<T> *> * operands_;
	
	/// A stack for storing operators (as fucntors)
	Stack<Create_Node_Functor<T> *> * operators_; 

};

#include "Functor_Expr_Builder.cpp"

#endif // FUNCTOR_EXPR_BUILDER_H_
