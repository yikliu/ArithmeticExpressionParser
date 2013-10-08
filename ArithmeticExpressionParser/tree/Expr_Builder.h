/**
* @file    	Expr_Builder.h
* @brief    
* @details 
* @author   yikliu@umail.iu.edu
* @date     2012/04/07
*/
#pragma once
#ifndef EXPR_BUILDER_H_
#define EXPR_BUILDER_H_

#include <string>
#include "Expr_Node.h"

template<typename T>
class Expr_Builder
{
public:
	// Default Constructor
	Expr_Builder(void);
	
	// Destructor
	virtual ~Expr_Builder(void);
	
	/**
	* @name  build_number     
	* @brief   build the number operand into tree
	* @param[in]  T n the number 	   
	* @return     
	* @exception  
	*/
	virtual void build_number(T n);
	
	// Author, your builder should be building concrete products and
	// not an operator. I understand why you are trying to do this 
	// based on your design, but you should have explicit functions
	// for building each type of supported operator. Then, you let
	// the actual builder implementation determine how to best handle
	// all the operators. Likewise, you are forcing each builder to 
	// parse the token string and determine the correct operator. This
	// is going result in duplicated code across all builders, and defeats
	// one of its purposes.
	// 
	// REPLY: I made the interface generating all the concrete operator types 
	//		  and I made build_operator(string&) an internal method for the concrete builder 
	//		  to handle all the similar operations for all the operators.
	//
	//virtual void build_operator(std::string & token);
	
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
	virtual void build_end();
	
	/**
	* @name    get_expression   
	* @brief   return the root node in order to let the client access the expression tree.
	* @param[in]   	   
	* @return     
	* @exception  
	*/
	virtual Expr_Node<T> * get_expression (void);
};

#include "Expr_Builder.cpp"
#endif // EXPR_BUILDER_H_