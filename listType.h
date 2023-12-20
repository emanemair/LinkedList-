#pragma once
#include"linkedListIter.h"

template<class type>
struct nodeType
{
	type data; 
	nodeType* next; 
	nodeType()
	{
		node = 0; 
	}
	nodeType(type d, nodeType<type>* next = 0)
	{
		this->data = d; 
		this->next = next; 
	}
};
template<class type> 
class listType
{
protected : 
	nodeType<type>* first, * last; 
	int count; 
public : 
	listType();
	~listType(); 
	void deleteFirst(); 
	void deleteLast(); 
	listType(const listType<type>& right); 
	const listType<type>& operator= (const listType<type>& right); 
	void initalizeList();//to it's empty satute  
	bool isEmpty(); 
	void print(); 
	void destroyList(); 
	int length(); 
	void destroyList(); 
	type front(); 
	type back(); 
	nodeType<type>*  begin(); 
	nodeType<type>* end(); 
	virtual bool search(const type& searchItem)const = 0; 
	virtual void insertFirst(const type& item)const = 0; 
	virtual void insertLast(const type& item)const = 0; 
	virtual void deleteNode(const type& item)const = 0; 
private: 
	void copyList(const listType<type>& right);
	
	
};