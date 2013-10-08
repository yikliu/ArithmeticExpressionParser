//==============================================================================
/**
 * @file       Create_Divide_Node_Functor.h
 * 
 * 
 *
 *
 * 
 */
//==============================================================================
#pragma once
#ifndef CREATE_DIVIDE_NODE_FUNCTOR_H_
#define CREATE_DIVIDE_NODE_FUNCTOR_H_
#include "Create_Node_Functor.h"

/**
 * @class 
 *
 * 
 */
template<typename T>
class Create_Divide_Node_Functor : public Create_Node_Functor<T>
{
public:
	/// Default Constructor
	Create_Divide_Node_Functor(void);
	// Destructor
	virtual ~Create_Divide_Node_Functor(void);

	virtual int priority(void);

	virtual Binary_Expr_Node<T> * operator () (void);
	
protected:
	
private:
};

#include "Create_Divide_Node_Functor.cpp"

#endif // CREATE_DIVIDE_NODE_FUNCTOR_H_
