//==============================================================================
/**
 * @file       Create_OP_Node_Functor.h
 * 
 * 
 *
 *
 * 
 */
//==============================================================================
#pragma once
#ifndef CREATE_OP_NODE_FUNCTOR_H_
#define CREATE_OP_NODE_FUNCTOR_H_

#include "Create_Node_Functor.h"
/**
 * @class 
 *
 * 
 */
template<typename T>
class Create_OP_Node_Functor : public Create_Node_Functor<T>
{
public:
	/// Default Constructor
	Create_OP_Node_Functor(void);
	// Destructor
	virtual ~Create_OP_Node_Functor(void);

	virtual int priority(void);
	
	//Not implementing () operator overload

protected:
	
private:
};

#include "Create_OP_Node_Functor.cpp"

#endif // CREATE_OP_NODE_FUNCTOR_H_
