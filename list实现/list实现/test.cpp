#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
using namespace std;
template <class T>
struct ListNode
{
	ListNode <const T& val>*_next;
	ListNode<T>*_prev;
	T _data;
};


template <class T>
struct ListIterator
{
	typedef ListNode<T>* pNode;
	typedef ListIterator<T> self;
	pNode _node;

	ListIterator(pNode node)
		:_node(node)
	{}
	//++iterator
	self& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	//iterator++
	self operator++(int)
	{
		self tmp(*this);
		_node = _node->_next;
		return tmp;
	}

	self &operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	self &operator--(int)
	{
		self tmp(this*);
		_node = _node->_prev;
		return tmp;
	}

	//*iterator
	T& operator*()
	{
		return _node->_data;
	}

	operator->()
	{
		return _node->_data;
	}

	//iterator !=l.end()
	//比较两个迭代器封装的节点是否一样
	bool operator !=(const self& it)
	{
		return _node != it._node;
	}
};


template <class T>
class List
{public:
	typedef ListNode<T> Node;
	typedef Node* pNode;
	typedef ListIterator<T> iterator;

	List(const T& val = T())
		:_head(new Node(val))
	{
		_head->_next = _head;
		_head->_prev = _head;
	}

	void PushBack(const T& val)
	{
		pNode curNode = new Node(val);
		pNode prev = _head->_prev;
		prev->_next = curNode;
		curNode->_next = _head;
		_head->_prev = curNode;
	}

	iterator begin()
	{
		return iterator(_head->_next);
	}

	iterator end()
	{
		return iterator(_head);//最后一个元素的下一个位置是头节点
	}

private:
	pNode _head;
};


int mian()
{
	List<int> lst;
	lst.PushBack(1);
	lst.PushBack(2);
	lst.PushBack(3);
	lst.PushBack(4);
	auto lit = lst.begin();
	while (lit != lst.end())
	{
		cout << *lit << " ";
		++lit;
	}
	system("pause");
	return 0;
}




