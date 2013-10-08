#pragma once
#ifndef _ARRAY_ITERATOR_CPP_
#define _ARRAY_ITERATOR_CPP_

#include "Array_Iterator.h"

/// Copy Constructor
template<typename T>	
Array_Iterator<T>::Array_Iterator (Array<T> & a)
	:array_(a), curr_(0)
{
}
	
/// Destructor
template<typename T>
Array_Iterator<T>::~Array_Iterator(void)
{
}

/// is_done
template<typename T>
bool Array_Iterator<T>::is_done (void)
{
	return this->curr_ >= this->array_.cur_size_;
}
	
/// advance
template<typename T>
void Array_Iterator<T>::advance (void) 
{ 
	++this->curr_; 
}

/// clear
template<typename T>
void Array_Iterator<T>:: clear   (void) 
{
	this->curr_ = 0;
}

/// dereferencing	
template<typename T>
T & Array_Iterator<T>::operator * (void) 
{
	return this->array_.data_[this->curr_]; 
}
	
/// get pointer
template<typename T>
T * Array_Iterator<T>::operator & (void) 
{
	return &this->array_.data_[this->curr_]; 
}

#endif // _ARRAY_ITERATOR_CPP
