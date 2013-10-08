/**
* @file    	Expr_Builder.cpp
* @brief    
* @details 
* @author   yikliu@umail.iu.edu
* @date     2012/04/07
*/
#pragma once
#ifndef EXPR_BUILDER_CPP_
#define EXPR_BUILDER_CPP_

#include "Expr_Builder.h"

template<typename T>
Expr_Builder<T>::Expr_Builder(void){}

template<typename T>
Expr_Builder<T>::~Expr_Builder(void){}

template<typename T>
void Expr_Builder<T>::build_number(T n){}

template<typename T>
void Expr_Builder<T>::build_add_operator(void){}

template<typename T>
void Expr_Builder<T>::build_subtract_operator(void){}

template<typename T>
void Expr_Builder<T>::build_multiply_operator(void){}

template<typename T>
void Expr_Builder<T>::build_divide_operator(void){}

template<typename T>
void Expr_Builder<T>::build_module_operator(void){}

template<typename T>
void Expr_Builder<T>::build_open_parenthesis(void){}

template<typename T>
void Expr_Builder<T>::build_close_parenthesis(void){}

template<typename T>
void Expr_Builder<T>::build_end(void){}

template<typename T>
Expr_Node<T> * Expr_Builder<T>::get_expression(void)
{
	return NULL;
}

#endif // EXPR_BUILDER_CPP_
