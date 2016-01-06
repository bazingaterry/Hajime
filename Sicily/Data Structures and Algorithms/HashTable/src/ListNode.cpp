//
//  ListNode.cpp
//  HashTable
//
//  Created by terrychan on 15/12/4.
//  Copyright © 2015年 terrychan. All rights reserved.
//

#include "ListNode.hpp"
#include <string>
#include <cstdlib>

template <class keyType, class valueType>
ListNode<keyType, valueType>::ListNode()
{
	head = new Node<keyType, valueType>;
	size = 0;
}

template <class keyType, class valueType>
ListNode<keyType, valueType>::~ListNode()
{
	while(head != NULL)
	{
		Node<keyType, valueType>* next = head->next;
		delete head;
		head = next;
	}
}

template <class keyType, class valueType>
int ListNode<keyType, valueType>::getSize() const
{
	return size;
}

template <class keyType, class valueType>
bool ListNode<keyType, valueType>::insert(const keyType& key, const valueType& value)
{
	if(exist(key))	//	if the key is already exist
		return false;
	else
	{
		Node<keyType, valueType>* next = head->next;
		head->next = new Node<keyType, valueType>;
		head->next->key = key;
		head->next->value = value;
		head->next->next = next;
		size++;
		return true;
	}
}

template <class keyType, class valueType>
bool ListNode<keyType, valueType>::find(const keyType& key, valueType& value)
{
	Node<keyType, valueType>* current = head->next;
	while(current != NULL)
	{
		if (current->key == key)
		{
			value = current->value;
			return true;
		}
		current = current->next;
	}
	return false;
}

template <class keyType, class valueType>
bool ListNode<keyType, valueType>::exist(const keyType& key) const
{
	Node<keyType, valueType>* current = head->next;
	while(current != NULL)
	{
		if (current->key == key)
			return true;
		current = current->next;
	}
	return false;
}

template <class keyType, class valueType>
bool ListNode<keyType, valueType>::remove(const keyType& key)
{
	Node<keyType, valueType>* pre = head;
	Node<keyType, valueType>* current = head->next;
	while(current != NULL)
	{
		if (current->key == key)
		{
			Node<keyType, valueType>* next = current->next;
			delete current;
			pre->next = next;
			size--;
			return true;
		}
		current = current->next;
		pre = pre->next;
	}
	return false;
}