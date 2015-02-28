//
//  LList.h
//  Lab9
//
//  Created by Nathan Sturtevant on 2/10/15.
//  Copyright (c) 2015 Nathan Sturtevant. All rights reserved.
//

#ifndef Lab9_LList_h
#define Lab9_LList_h

#include <iostream>

template <typename T>
class LList {
public:
	LList();
	~LList();
	bool IsEmpty();
	void AddFront(T item);
	T PeekFront();
	void RemoveFront();
	void Print();
private:
	struct ListItem
	{
		T item;
		ListItem* next;
	};
	ListItem *GetFromCache();
	void Free(ListItem *l);
	ListItem *head, *cache;
};

template <typename T>
LList<T>::LList()
{
	head = 0;
	cache = 0;
}

template <typename T>
LList<T>::~LList()
{
	while (head != 0)
	{
		ListItem *tmp = head->next;
		delete head;
		head = tmp;
	}
	while (cache != 0)
	{
		ListItem *tmp = cache->next;
		delete cache;
		cache = tmp;
	}
}


template <typename T>
bool LList<T>::IsEmpty()
{
	return head == 0;
}


template <typename T>
void LList<T>::AddFront(T item)
{
	ListItem *t = GetFromCache();
	t->item = item;
	t->next = head;
	head = t;
}


template <typename T>
T LList<T>::PeekFront()
{
	return head->item;
}

template <typename T>
void LList<T>::RemoveFront()
{
	if (head == 0)
		return;
	ListItem *t = head;
	head = head->next;
	Free(t);
}

template <typename T>
typename LList<T>::ListItem *LList<T>::GetFromCache()
{
	if (cache == 0)
		return new ListItem;
	ListItem *tmp = cache;
	cache = cache->next;
	tmp->next = 0;
	return tmp;
}

template <typename T>
void LList<T>::Free(ListItem *l)
{
	if (l)
	{
		l->next = cache;
		cache = l;
	}
}

template <typename T>
void LList<T>::Print()
{
	for (ListItem *t = head; t; t = t->next)
	{
		std::cout << t->item << " ";
	}
	std::cout << "\n";
}


#endif
