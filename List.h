#pragma once

#include <utility>
#include "Node.h"

class List{
	friend std::ostream& operator<<(std::ostream&, const List&);
public:
	List();

	template<typename T>
	List(const T& data): _head(new Node(data)), _tail(_head) {}

	List(const List&);

	List& operator=(List);

	List(List&&) noexcept;

	List& operator=(List&&) noexcept;

	void swap(List&) noexcept;

	~List();

	template<typename T>
	void create_list(const T& data) {
		if(_head)
			return;

		_head = new Node(data);
		_tail = _head;
	}

	template<typename T>
	void push_back(const T& data) {
		Node* node = new Node(data);

		if(!_head)
			_head = node;
		
		if(_tail)
			_tail->_next = node;

		_tail = node;
	}

	void pop_back();

	template<typename T>
	void push_front(const T& data) {
		Node* node = new Node(data);
		node->_next = _head;
		_head = node;

		if(_tail == nullptr)
			_tail = node;
	} 

	template<typename T>
	void insert(const T& data, const size_t ind) {
		if(ind < 0)
			return;
		Node* left = _head;
		for(size_t i = 0; i != ind; ++i) {
			if(left == nullptr)
				return;

			left = left->_next;
		}

		Node* right = left->_next;
		Node* node = new Node(data);
	
		left->_next = node;
		node->_next = right;

		if(right == nullptr)
			_tail = node;
	}

	void erase(const size_t&);

	void pop_front();

	void clear();

	List create_copy() const;

private:
	Node* _head;
	Node* _tail;
};
