#pragma once
#include"listType.h"




template<class type>
class orderedList : public listType<type>
{
public : 
	bool search(const type& item); 
	void insert(const type& item); 
	void insertFirst(const type& item); 
	void insertLast(const type& item); 
	void deleteItem(const type& item); 

	// friend void BinarySearch(const orderedList<type>& list, const nodeType<type>* first, const nodeType<type>*last );
};




