#ifndef POSTFIX_EVALUATOR_CPP
#define POSTFIX_EVALUATOR_CPP

#include "Postfix_Evaluator.h"

/// constructor
template<typename T>
Postfix_Evaluator<T>::Postfix_Evaluator(void)
{
}

/// Destructor
template<typename T>
Postfix_Evaluator<T>::~Postfix_Evaluator(void)
{
}

/// postfix_evaluate
template<typename T>
bool Postfix_Evaluator<T>::postfix_evalute(Array_Iterator<Expr_Command<T> *> & iter, T & result)
{
	Stack<T> s;
	for (; !iter.is_done(); iter.advance())
	{
		if (!(*iter)->execute(s))
			return false;
	}
	result = s.top();
	s.pop();

	return true;
}


#endif