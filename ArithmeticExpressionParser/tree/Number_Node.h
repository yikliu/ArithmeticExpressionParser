/**
* @file    	Number_Node.h
* @brief    
* @details 
* @author   yikliu@umail.iu.edu
* @date     2012/04/07
*/
#pragma once
#ifndef NUMBER_NODE_H_
#define NUMBER_NODE_H_

#include "Expr_Node.h"
#include "Expr_Node_Visitor.h"

template<typename T>
class Expr_Node;

template<typename T>
class Expr_Node_Visitor;

template<typename T>
class Number_Node : public Expr_Node<T>
{
public:
	// Constructor
	Number_Node(T num);

	// Destructor
	virtual ~Number_Node(void);
	
	/**
	* @name  getNum     
	* @brief   get the number from this number node
	* @param[in] void  	   
	* @return  T the actual value of the number node   
	* @exception  
	*/
	T getNum(void) const;
	
	/**
	* @name  accept     
	* @brief   accept a visitor in order to let it visit this number node
	* @param[in]  Expr_Node_Visitor<T> reference to the visitor 	   
	* @return   void  
	* @exception  
	*/
	bool accept(Expr_Node_Visitor<T> & v);

private:
	/// The actual number
	T number_; 
};

#include "Number_Node.cpp"
#endif // NUMBER_NODE_H_