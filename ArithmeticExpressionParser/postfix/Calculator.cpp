#ifndef CALCULATOR_CPP_
#define CALCULATOR_CPP_

#include "Calculator.h"

/// Default constructor
template<typename T>
Calculator<T>::Calculator(void)
	:p_postfix_array_(0),
	p_iter_(0),
	p_parser_(0),
	p_evaluator_(0),
	p_factory_(0)
{
	p_postfix_array_ = new Array<Expr_Command<T> *>();
	p_iter_ = new Array_Iterator<Expr_Command<T> *>(*p_postfix_array_);
	p_parser_ = new Infix_Postfix_Parser<T>();
	p_evaluator_ = new Postfix_Evaluator<T>();
	p_factory_ = new Stack_Expr_Command_Factory<T>();
}

/// Destructor
template<typename T>
Calculator<T>::~Calculator(void)
{
	if(p_postfix_array_ != 0) 
		delete p_postfix_array_;
	if(p_iter_ != 0)
		delete p_iter_;
	if(p_parser_ != 0)
		delete p_parser_;
	if(p_evaluator_ != 0)
		delete p_evaluator_;
	if(p_factory_ != 0)
		delete p_factory_;
}

/// do_calculation
template<typename T>
bool Calculator<T>::do_calculation(std::istream & source, T & result)
{	
	std::string infix;					
	getline(source, infix);			
	
	// infix-to-postfix conversion
	if(!p_parser_->inflix_to_postfix(infix, *p_factory_, *p_postfix_array_))
	{
		return false;
	}
	
	// evaluate the postfix to get the result
	if(!p_evaluator_->postfix_evalute(*p_iter_, result))
	{
		return false;
	}	
	return true;
}

/// get_postfix
template<typename T>
std::string & Calculator<T>::get_postfix() const
{
	return p_parser_->get_postfix();
}

/// reset
template<typename T>
void Calculator<T>::reset()
{
	p_postfix_array_->clear();
	p_iter_->clear();
	p_parser_->clear_postfix_string();
}

#endif // calculator_h__
