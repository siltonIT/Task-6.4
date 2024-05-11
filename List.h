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

	void clear();

	List create_copy() const;

private:
	Node* _head;
	Node* _tail;
};
