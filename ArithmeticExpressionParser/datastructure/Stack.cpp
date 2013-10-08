#pragma once
#ifndef _CS507_STACK_CPP_
#define _CS507_STACK_CPP_

#define DEFAULT_STACK_ALLOC_SIZE 20  //Default size to initialize the underlying array
#define STACK_INCREMENT 5 

#include <stdexcept>  // for std::out_of_bounds exception
#include "Stack.h"

//
// Stack
//
template <typename T>
Stack <T>::Stack (void)
	:array_(0),
	top_(-1)
{
	this->array_ = new Array<T>(DEFAULT_STACK_ALLOC_SIZE);
}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
	:array_(0),
	top_(-1)
{
	this->array_ = new Array<T>(*stack.array_);
	this->top_ = stack.top_;
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{	
	if (array_ != 0)
	{
		delete array_;
	}
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
	//if the stack is full, resize the underlying array to a larger size.
	if (this->top_ >= ((int)(array_->max_size() - 1)))
	{
		size_t new_size = array_->max_size() + STACK_INCREMENT;
		this->array_->resize(new_size);
	}	
	this->top_++;	
	try
	{
		this->array_->set(top_, element);
	}	
	catch (std::out_of_range  e)
	{
	}	
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
	if (this->is_empty())
	{
		throw empty_exception("Stack is empty");
	}	
	this->top_--;	
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	
	*this->array_ = *rhs.array_;
	this->top_ = rhs.top_;
	return *this;
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
	this->top_ = -1;
}

#endif
