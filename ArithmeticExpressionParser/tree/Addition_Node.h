/**
* @file    	Addition_Node.h
* @brief    
* @details 
* @author   yikliu@umail.iu.edu
* @date     2012/04/07
*/
#ifndef ADDITION_NODE_H_
#define ADDITION_NODE_H_

#include "Expr_Node.h"
#include "Binary_Expr_Node.h"

template<typename T>
class Expr_Node_Visitor;

template<typename T>
class Binary_Expr_Node;

template<typename T>
class Addition_Node : public Binary_Expr_Node<T>
{
public:
	// Default Constructor
	Addition_Node(void);

	// Destructor
	virtual ~Addition_Node(void);

	static Addition_Node<T>* _create(void);

	/**
	* @name  accept     
	* @brief   accept the visitor
	* @param[in]  Expr_Node_Visitor<T>& reference to the visitor
	* @return  void   
	* @exception  
	*/
	bool accept(Expr_Node_Visitor<T> & v);

	//void visitNode(Expr_Node_Visitor<T> & v);
};

#include "Addition_Node.cpp"

#endif // ADDITION_NODE_H_