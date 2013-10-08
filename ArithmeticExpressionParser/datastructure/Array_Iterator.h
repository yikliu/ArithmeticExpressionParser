/**
* @file     Array_Iterator.h
* @brief	Iterator bound to Array Class
* @details  
* @author   Originate from Dr.Hill's CSCI507 Slides
* @date     3/17/2012
*/
#pragma once
#ifndef ARRAY_ITERATOR_H
#define ARRAY_ITERATOR_H

#include "Array.h"

/**
 * @class Array_Iterator 
 *
 * @brief Iterate through an Array object
 */
template<typename T>
class Array_Iterator{
public:
	/// Copy Constructor
	Array_Iterator (Array<T> & a);
	
	/// Destructor
	~Array_Iterator(void);

	/**
	* @brief   check if iteration is reaching the end of the array
	* @param   void 
	* @return  flag to indicate if iteration is done
	*/
	bool is_done (void);
	
	/**
	* @brief   move the iterator to the next element
	* @param   void
	* @return  void
	*/
	void advance (void); 
	
	/**
	* @brief   reset the iterator to the first element of the array
	* @param   void
	* @return  void
	*/
	void clear   (void); /*{this->curr_ = 0;}*/
	
	/**
	* @brief   Dereferencing the element pointed by iterator
	* @param   void
	* @return  Reference to the element 
	*/
	T & operator * (void); /*{return this->array_.data_[this->curr_]; }*/
	
	/**
	* @brief   Get the address of element pointed by iterator
	* @param   void
	* @return  Pointer to the element
	*/
	T * operator & (void); /* {return &this->array_.data_[this->curr_]; }*/

private:
	/// the array that the iterator is bound to
	Array<T> & array_;
	
	/// the index currently pointed by the iterator
	size_t curr_;
};

#include "Array_Iterator.cpp"

#endif