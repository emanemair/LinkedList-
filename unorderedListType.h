#pragma once
#include"listType.h"


template <class type> 
class unorderdList : public listType<type>
{
public : 
	bool search(const type& searchItem)const;
	void insertFirst(const type& item); 
	void insertLast(const type& item); 
	void deleteItem(const type& item); 

};