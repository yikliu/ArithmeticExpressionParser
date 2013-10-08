/**
* @file    	Division_Node.h
* @brief    
* @details 
* @author   yikliu@umail.iu.edu
* @date     2012/04/07
*/
#ifndef DIVISION_NODE_H_
#define DIVISION_NODE_H_
#include "Expr_Node_Visitor.h"
#include "Binary_Expr_Node.h"

template<typename T>
class Expr_Node_Visitor;

template<typename T>
class Division_Node : public Binary_Expr_Node<T>
{
public:
	// Default Constructor
	Division_Node(void);
	
	// Destructor
	virtual ~Division_Node(void);

	static Division_Node<T>* _create(void);

	/**
	* @name  accept     
	* @brief   accept the visitor
	* @param[in]  Expr_Node_Visitor<T>& reference to the visitor
	* @return  void   
	* @exception  
	*/
	virtual bool accept(Expr_Node_Visitor<T> & v);
	//void visitNode(Expr_Node_Visitor<T> & v);
};

#include "Division_Node.cpp"
#endif // DIVISION_NODE_H_