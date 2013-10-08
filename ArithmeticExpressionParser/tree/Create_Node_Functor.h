//==============================================================================
/**
 * @file       Create_Node.h
 * 
 * 
 *
 *
 * 
 */
//==============================================================================
#pragma once
#ifndef CREATE_NODE_H_
#define CREATE_NODE_H_

#include "Binary_Expr_Node.h"

/**
 * @class 
 *
 * 
 */
template<typename T>
class Create_Node_Functor
{

public:
	/// Default Constructor
	Create_Node_Functor(void);
	// Destructor
	virtual ~Create_Node_Functor(void);	
	
	virtual int priority(void) = 0;

	virtual Binary_Expr_Node<T> * operator () (void);
	
protected:
	
private:	

};

#include "Create_Node_Functor.cpp"

#endif // CREATE_NODE_H_
