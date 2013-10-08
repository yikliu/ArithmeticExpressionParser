//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
	return this->top_ + 1;
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
	if(this->is_empty())
	{
		throw new empty_exception("Stack is empty");
	}
	return array_->get(top_);
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
	return this->top_ == -1;
}
