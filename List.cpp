#include "List.h"

std::ostream& operator<<(std::ostream& os, const List& seq) {
	for(auto i = seq._head; i != nullptr; i = i->_next) {
		i->_data->print();
		os << std::endl;
	}

	return os;
}

List::List(): _head(nullptr), _tail(nullptr) {}

List::List(const List& other): List() {
	for(auto i = other._head; i != nullptr; i = i->_next) {
		Node* node = new Node();	
		node->_data = i->_data->clone();

		if(!_head)
			_head = node;
		
		if(_tail)
			_tail->_next = node;
		
		_tail = node;
	}
}

List& List::operator=(List other) {
	swap(other);
	return *this;
}

List::List(List&& other) noexcept: _head(other._head), _tail(other._tail) {
	other._head = other._tail = nullptr;
}

List& List::operator=(List&& other) noexcept {
	List res(std::move(other));
	swap(res);
	return *this;
}

void List::swap(List& other) noexcept {
	std::swap(_head, other._head);
	std::swap(_tail, other._tail);
}

List::~List() {
	clear();
}

void List::pop_back() {
	if(_tail == nullptr)
		return;

	if(_head == _tail) {
		delete _tail;
		_head = _tail = nullptr;
		return;
	}

	Node* node = _head;
	while(node->_next != _tail) 
		node = node->_next;

	node->_next = nullptr;
	delete _tail;
	_tail = node;
}

void List::pop_front() {
	if(_head == nullptr)
		return;

	if(_head == _tail) {
		delete _tail;
		_head = _tail = nullptr;
		return;
	}

	Node* node = _head;
	_head = node->_next;
	delete node;
}

void List::erase(const size_t& ind) {
	if(ind < 0)
		return;
	if(ind == 1) {
		pop_front();
		return;
	}

	Node* left = _head;
	for(size_t i = 0; i != ind; ++i) {
		if(left == nullptr)
			return;

		left = left->_next;
	}

	Node* node = left->_next;
	if(node == nullptr)
		return;

	Node* right = node->_next;

	left->_next = right;
	if(node == _tail)
		_tail = left;

	delete node;
}

void List::clear() {
	Node* prev = _head;
	Node* curr = _head;
	while(curr != nullptr) {
		prev = curr;
		curr = prev->_next;
		delete prev;

	}

	_head = _tail = nullptr;
}

List List::create_copy() const {
	return *this;
}















