#pragma once
#ifndef POSTFIX_EVALUATOR_STRATEGY_CPP_
#define POSTFIX_EVALUATOR_STRATEGY_CPP_

#include "Postfix_Evaluator_Strategy.h"

//
// Postfix_Evaluator_Strategy(void)
//
template<typename T>
Postfix_Evaluator_Strategy<T>::Postfix_Evaluator_Strategy(void)
	:p_postfix_array_(0),
	p_factory_(0),
	p_operator_stack_(0),
	flyweight(false)
{
	p_postfix_array_ = new Array<Expr_Command<T> *>();
	p_factory_ = new Stack_Expr_Command_Factory<T>();
	p_operator_stack_ = new Stack<std::string *>();
}

//
// Postfix_Evaluator_Strategy(bool)
//
template<typename T>
Postfix_Evaluator_Strategy<T>::Postfix_Evaluator_Strategy(bool use_flyweight)
	:p_postfix_array_(0),
	p_factory_(0),
	p_operator_stack_(0),
	flyweight(use_flyweight)
{
	p_postfix_array_ = new Array<Expr_Command<T> *>();

	if(use_flyweight)
		p_factory_ = new Flyweight_Expr_Command_Factory<T>();
	else
		p_factory_ = new Stack_Expr_Command_Factory<T>();

	p_operator_stack_ = new Stack<std::string *>();
}

//
// ~Postfix_Evaluator_Strategy(void)
//
template<typename T>
Postfix_Evaluator_Strategy<T>::~Postfix_Evaluator_Strategy(void)
{
	if(p_postfix_array_ != 0 )
	{		
		for(unsigned int i = 0; i < p_postfix_array_->size(); i++)
		{
			Expr_Command<T> * cmd = p_postfix_array_->get(i);
			if (cmd != 0)
			{
				//if using flyweight, only delete num_command, leave operator objects for
				// p_factory to delete. 
				if(flyweight) 
				{
					Num_Command<T> * num_cmd = dynamic_cast<Num_Command<T> *>(cmd);
					if(num_cmd)
					{
						delete num_cmd;
						num_cmd = 0;
					}
				}
				else
				{
					delete cmd;
					cmd = 0;
				}
			}
		}
		delete p_postfix_array_;
	}
	
	if (p_factory_ != 0)
	{
		delete p_factory_;
		p_factory_ = 0;
	}
	
	if(p_operator_stack_ != 0)
	{
		while(!p_operator_stack_->is_empty())
		{
			std::string * str = p_operator_stack_->top();
			if(str !=0 )
				delete str;
			p_operator_stack_->pop();
		}
		delete p_operator_stack_;
	}
}

//
//parse_expression
//
template<typename T>
bool Postfix_Evaluator_Strategy<T>::parse_expression(const std::string & expr)
{
	std::istringstream input (expr);
	std::string token;

	enum symbol {open_paren = 1, num, op = 4, close_paren = 8};
	unsigned char acceptable_token;
	acceptable_token = open_paren | num; // Either an open parenthesis or a number can begin an infix expression.

	try
	{
		while (!input.eof())
		{
			input >> token;

			if (token == "(")
			{
				if(acceptable_token & open_paren)
				{
					p_operator_stack_->push(new std::string(token));
				}
				else
				{
					throw std::exception("Bad Infix Format");
				}
			}
			else if(token == "+" || token == "-" || token == "*" || token == "/" || token == "%")
			{
				if(acceptable_token & op)
				{
					if(token == "+")
					{
						while (!p_operator_stack_->is_empty() && !(*p_operator_stack_->top()=="(") && this->priority(*p_operator_stack_->top()) <= this->priority(token))
						{
							this->create_command(*p_operator_stack_->top());
							delete p_operator_stack_->top();
							p_operator_stack_->pop();
						}
						p_operator_stack_->push(new std::string(token));
					}
					else if(token == "-")
					{
						while (!p_operator_stack_->is_empty() && !(*p_operator_stack_->top()=="(") && this->priority(*p_operator_stack_->top()) <= this->priority(token))
						{
							this->create_command(*p_operator_stack_->top());
							delete p_operator_stack_->top();
							p_operator_stack_->pop();
						}
						p_operator_stack_->push(new std::string(token));
					}
					else if(token == "*")
					{
						while (!p_operator_stack_->is_empty() && !(*p_operator_stack_->top()=="(") && this->priority(*p_operator_stack_->top()) <= this->priority(token))
						{
							this->create_command(*p_operator_stack_->top());
							delete p_operator_stack_->top();
							p_operator_stack_->pop();
						}
						p_operator_stack_->push(new std::string(token));
					}
					else if(token == "/")
					{
						while (!p_operator_stack_->is_empty() && !(*p_operator_stack_->top()=="(") && this->priority(*p_operator_stack_->top()) <= this->priority(token))
						{
							this->create_command(*p_operator_stack_->top());
							delete p_operator_stack_->top();
							p_operator_stack_->pop();
						}
						p_operator_stack_->push(new std::string(token));
					}
					else if(token == "%")
					{
						while (!p_operator_stack_->is_empty() && !(*p_operator_stack_->top()=="(") && this->priority(*p_operator_stack_->top()) <= this->priority(token))
						{
							this->create_command(*p_operator_stack_->top());
							delete p_operator_stack_->top();
							p_operator_stack_->pop();
						}
						p_operator_stack_->push(new std::string(token));
					}
					acceptable_token = open_paren | num; //only an open parenthesis or a number can follow an operator.
				}
				else
				{
					throw std::exception("Bad Infix Format");
				}
			}
			else if(token == ")")
			{
				if(acceptable_token & close_paren)
				{
					while (*p_operator_stack_->top() != "(")
					{
						this->create_command(*p_operator_stack_->top());
						delete p_operator_stack_->top();
						p_operator_stack_->pop();
					}
					delete p_operator_stack_->top();
					p_operator_stack_->pop();
					acceptable_token = op | close_paren; //Only operator and close parenthesis can follow a close parenthesis.
				}
				else
				{
					throw std::exception("Bad Infix Format");
				}
			}
			else //it's a number or contains wrong character
			{
				if(acceptable_token & num)
				{
					this->create_command(token);
					acceptable_token = op | close_paren;//Only operator and close parenthesis can follow a number.
				}
				else
				{
					throw std::exception("Bad Infix Format");
				}
			}

		}

		while (!p_operator_stack_->is_empty())
		{
			this->create_command(*p_operator_stack_->top());
			delete p_operator_stack_->top();
			p_operator_stack_->pop();
		}
	}
	catch (std::exception & e)
	{
		std::cout<<e.what()<<std::endl;
		return false;
	}

	return true;
}

/// output_to_array
template<typename T>
bool Postfix_Evaluator_Strategy<T>::create_command(const std::string & token)
{
	Expr_Command<T> * cmd = 0;

	// creating appropriate command object based on token
	if (token == "+")
		cmd = p_factory_->create_add_command();
	else if (token == "-")
		cmd = p_factory_->create_subtract_command();
	else if (token == "*")
		cmd = p_factory_->create_multiply_command();
	else if (token == "/")
		cmd = p_factory_->create_divide_command();
	else if (token == "%")
		cmd = p_factory_->create_module_command();
	else
	{
		//Using isstringstream for converting string to numeric values
		std::istringstream stream (token);
		T t;
		stream >> t;
		cmd = p_factory_->create_num_command(t);
	}

	p_postfix_array_->add(cmd);

	return true;
}


//
// priority
//
template<typename T>
int Postfix_Evaluator_Strategy<T>::priority(const std::string& op) const
{
	int temp;
	if (op == "*" || op == "/" || op == "%")
		temp = 1;
	else  if (op == "+" || op == "-")
		temp = 2;
	return temp;
}


//
//evaluate_expression
//
template<typename T>
bool Postfix_Evaluator_Strategy<T>::evaluate_expression(T & result)
{
	Stack<T> s;
	if(p_postfix_array_ == 0 )
		return false;

	Array_Iterator<Expr_Command<T> *> iter(*p_postfix_array_);

	for (; !iter.is_done(); iter.advance())
	{
		if (!(*iter)->execute(s))
			return false;
	}
	result = s.top();
	s.pop();

	return true;
}

#endif // POSTFIX_EVALUATOR_STRATEGY_CPP_
