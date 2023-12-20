#include"linkedListIter.h"
#include"listType.h"
#include<assert.h>
#include"unorderedListType.h"
#include"orderedList.h"

template<class type> 
linkedListiter<type>::linkedListiter()
{
	current = 0; 
}

template<class type> 
linkedListiter<type>::linkedListiter(nodeType<type>* ptr)
{
	current = ptr; 
}
template<class type> 
type linkedListiter<type>::operator*()
{
	return this->current->data; 
}

template<class type> 
linkedListiter<type> linkedListiter<type>::operator++()
{
	current = current->next
		return *this;
}

template<class type> 
bool linkedListiter<type>::operator==(const linkedListiter<type>& right)const
{
	return current == right.current; 
}
template<class type> 
bool linkedListiter<type>::operator!=(const linkedListiter<type>& right)const
{
	return current != right.current; 
}

template<class type> 
bool listType<type>::isEmpty() // o(1) 
{
	return first == 0; 
}

template<class type> 
listType<type>::listType() // o(1) 
{
	first = last = 0; 
	count = 0; 
}

template<class type> 
void listType <type>::destroyList()
{
	nodeType<type>* temp; 
	while (first != 0)// o(n) 
	{
		temp = first; 
		first = first->next; 
		delete temp; 
	}// first = 0 
	last = 0; 
	count = 0; 

}


template<class type> 
void listType<type>::initalizeList()
{
	destroyList(); 
}

template<class type> 
void listType<type>::print() // o (n) 
{
	if (!isEmpty())
	{
		nodeType<type>* current; 
		current = first; 
		while (current != 0)
		{
			cout << current->data << " ";
			current = current->next;
		}cout << endl; 
	}
}


template<class type> 
int listType<type>::length()
{
	return count; // o(1) 
}


template<class type> 
type listType<type>::front()
{
	assert(first != 0); 
	return first->data; // o(1) 
}

template<class type> 
type listType<type>::back()
{
	assert(last != 0);
	return last->data; 
}


template<class type> 
nodeType<type>* listType<type>::begin()
{
	nodeType<type>* temp(first); 
	return temp; 
}


template<class type> 
nodeType<type>* listType<type>::end()
{
	nodeType<type>* temp(last->next); 
	return temp; 
}

template<class type> 
void listType<type>::copyList(const listType<type>& rightList)
{
	nodeType<type>* current, *newNode; 
	if (first != 0)// if the list is not empty i must destroy the list or reinitalize it 
		destroyList(); 
	if (rightList.isEmpty())// if the right list is empty , i can set the list to it's empty statue 
	{
		first = last = 0; 
		count = 0; 
	}
	else
	{
		current = rightList.first; 
		count = rightList.count;
		first = new nodeType<type>; 
		first->data = current->data; 
		first->next = 0; 
		last = first; 
		current = current->next; 
		while (current != 0)
		{
			newNode = new nodeType<type>; 
			newNode->data = current->data; 
			newNode->next = 0; 
			last->next = newNode; 
			last = newNode; 
			current = current->next; 
		}

	}
}


template<class type> 
listType<type>::~listType()
{
	cout << " this list will be destroy" << endl; 
	destroyList(); 
}

template<class type> 
listType<type>::listType(const listType<type>& right)
{
	first = 0; 
	copyList(right); 
}

template<class type> 
const listType<type>& listType<type>::operator=(const listType& right)
{
	if (this != &right) // this return the address of the list object and the &right return the address of the right list 
	{
		copyList(right); 
	}
	return *this; 
}

template<class type> 
bool unorderdList<type>::search(const type& searchItem)const
{
	nodeType<type> current; 
	current = first; 
	bool found = false; 
	while (current != 0 && !found)
	{
		if (current->info == searchItem)
		{
			found = true;
		}
		else
			current = cuurent->next;
	}return  found; 
}
/* 
template<class type> 
void unorderdList<type>::insertFirst(const type& item)
{
	nodeType<type>* newNode; 
	newNode->data = item; 
	newNode->next = 0; 
	if (first == 0)
	{
		first = last = newNode; 
		
	}
	else
	{
		newNode->next = first;
		first = newNode; 
	}
	count++; 
	
}*/
/* 
template<class type>
void unorderdList<type>::insertLast(const type& item)
{
	nodeType<type> newNode; 
	newNode = new nodeType<type>; 
	newNode->data = item; 
	newNode->next = 0; 
	if (first == 0)
	{
		first = last = newNode; 
	}
	else
	{
		last->next = newNode; 
		last = newNode; 
	}
	count++; 
}
*/
/* 
template<class type> 
void listType<type>::deleteFirst()
{
	if (!isEmpty())
	{
		nodeType<type> temp; 
		temp = first; 
		first = first->next; 
		delete temp; 
		cout << "item  : " << front() << " is deleted " << endl; 
	}else cout << "can not delete from an empty list" << endl; 
}*/ 
/*

template<class type> 
void listType<type>::deleteLast()
{
	if (!isEmpty())
	{
		nodeType<type> temp; 
		temp = last; 
		last->next = 0; 
		delete temp; 
		cout << "item " << back() << " have been deleted " << endl; 
	}
	
	else cout << "list is empty" << endl; 
}*/
template<class type> 
void unorderdList<type>::deleteItem(const type& item)
{
	if (isEmpty())
		cout << "can not delete from an empty list" << endl; 
	if (search(item))
	{
		if (item == front())
			deleteFirst();
		if (item == back())
			deleteLast();
		else {

		}
	}
	else cout << item << " dose not exist in the list " << endl; 
	

}



template<class type> 
void unorderdList<type>::insertFirst(const type& item)
{
	nodeType<type>* newNode; 
	newNode = new nodeType<type>; 
	newNode->data = item; 
	newNode->next = first; 
	first = newNode; 
	count++; 
	if (last == 0)
		last = newNode; 
}

template<class type> 
void unorderdList<type>::insertLast(const type& item)
{
	nodeType<type> *newNode; 
	newNode->data = item; 
	newNode->next = 0; 
	if (first == 0)
	{
		first = newNode; 
		last = newNode; 
	
	}
	else
	{
		last->next = newNode; 
		last = newNode; 
	}
	count++; 
}
template<class type> 
void unorderdList<type>::deleteItem(const type& item)
{
	nodeType<type>* trailCurrent; 
	nodeType<type>* current; 
	if (first == 0)
		cout << "list is empty" << endl;
	else if (first->data == item)
	{
		current = first;
		first = first->next;
		if (first == 0) // after delete the first node , the list is empty , we make sure that last pointer is not deleted too with the item 
			last = 0;
		delete current;
	}
	else {
		//the data is somewhere in the list ( last or somewhere in between)
		trailCurrent = first; 
		current = first->next; 
		bool found = false; 
		while (current != 0 && !found)
		{
			if (current->data != item)
			{
				trailCurrent = current; 
				current = current->next; 
			}
			else
			{
				found = true; 
			}
		}//end while 
		if (found)
		{
			trailCurrent->next = current->next;
			count--;
			if (last == current)
				last = trailCurrent;
			delete current;
		}
		else cout << "not founded" << endl; 
	}
}

template<class type> 
void unorderdList<type>::deleteItem(const type& item)
{
	nodeType<type>* current; 
	nodeType<type>* trailCurrent; 
	bool found;
	if (first == 0)
		cout << "empty list " << endl; 
	else if (this->front() == item)
	{
		current = this->first;
		this->first = this->first->next; 
		count--; 
		if (this->first == 0)
			last = 0; 
		delete current; 
	}
	else {
		found = false; 
		trailCurrent = this->first; // point to the first node 
		current = this->first->next; // point to the second node 
		while (current != 0 && !found)
		{
			if (current->data != item)// traverse the list by adding changing both location to the next cuurent node 
			{
				trailCurrent = current; 
				current = current->next; 
			}
			else
			{
				found = true; 
			}
		}// end while 
		if (found)
		{
			trailCurrent->next = current->next; 
			count--; 
			if (last == current)
			{
				last = trailCurrent;

			}delete current; 
		}
		else
		{
			cout << "the item to be deleted is not in the list " << endl; 
		}//end else 
	} // end else 
}//end fucntion 


template<class type> 
bool orderedList<type>::search(const type& item)
{
	bool found = false; 
	nodeType<type>* current = first; 
	while (current != 0 && !found)
	{
		if (current->data >= item)//once the data become grater or equal the item , break the while 
			found = true;
		else
			current = current->next; 
	}found = (current->data == item); // ensure the equality 
	return found; 
}


template<class type> 
void orderedList<type>::insert(const type& item)
{
	if (search(item))
		cout << "the item exist in the list " << endl; 
	else
	{
		nodeType<type>* newNode;
		nodeType < type>* current;
		nodeType<type>* trailCurrent;
		bool found;

		newNode = new nodeTyppe<type>;
		newNode->data = item;
		newNode->next = 0;

		if (first == 0)//empty list
		{
			first = last = newNode;
			count++;
		}
		else {
			found = false;
			current = first;
			while (current != 0 && !found)
			{
				if (current->data >= found)
				{
					found = true
				}
				else
				{
					trailCuurent = current;
					current = current->next;
				}
			}// end while 
			if (current == first)
			{
				newNode->next = first;
				first = newNode;
				count++;
			}
			else
			{
				trailCurrent->next = newNode;
				newNode->next = current;
				if (current == 0)
					last = newNode;
				count++;
			}
		}
	}
}


template<class type> 
void orderedList<type>::insertFirst(const type& item)
{
	this->insert(item); 
}//end insertfirst 

template<class type> 
void orderedList<type>::insertLast(const type& item)
{
	this->insert(item); 
}// end insertLast 

