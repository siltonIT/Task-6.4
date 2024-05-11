#pragma once

#include "Move.h"
#include <cwctype>

struct Node {
	Node* _next;
	Move* _data;

	template<typename T>
	Node(const T& data): _next(nullptr), _data(new T(data)) {}

	//вынес специально так как жалуется что не види Node::Node() и Node::~Node()
	Node(): _next(nullptr), _data(nullptr) {}

	~Node() {
		delete _data;
	}
};

