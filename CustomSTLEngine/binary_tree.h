#pragma once

#include "abstract_tree.h"
#include <iostream>

template<typename T>
class BinaryNode : public TreeNode {
public:
	T value;
	BinaryNode* left = nullptr;
	BinaryNode* right = nullptr;

	BinaryNode(T value);
	~BinaryNode();

	BinaryNode* delete_node(BinaryNode* node, T value);
	
	void insert(BinaryNode* node, T value);
	void symmetric_print(const BinaryNode* node);
	void backward_print(const BinaryNode* node);
	void forward_print(const BinaryNode* node);
	void delete_tree(BinaryNode* node);

	const BinaryNode* search(const BinaryNode* node, T value);
	const BinaryNode* get_min(const BinaryNode* node);
	const BinaryNode* get_max(const BinaryNode* node);
};

template<typename T>
BinaryNode<T>::BinaryNode(T value) :value(value) {}

template<typename T>
BinaryNode<T>::~BinaryNode() {}


template<typename T>
void BinaryNode<T>::insert(BinaryNode* node, T value) {
	if (node == nullptr) return;
	if (value < node->value) {
		if (node->left == nullptr) node->left = new BinaryNode(value);
		else insert(node->left, value);
	}
	if (value >= node->value) {
		if (node->right == nullptr) node->right = new BinaryNode(value);
		else insert(node->right, value);
	}
}

template<typename T>
BinaryNode<T>* BinaryNode<T>::delete_node(BinaryNode* node, T value) {
	if (node == nullptr) return nullptr;

	if (value < node->value) node->left = delete_node(node->left, value);
	else if (value > node->value) node->right = delete_node(node->right, value);
	else {
		if (node->left == nullptr || node->right == nullptr) {
			node = (node->left == nullptr) ? node->right : node->left;
		}
		else {
			const BinaryNode* max_in_left = get_max(node->left);
			node->value = max_in_left->value;
			node->left = delete_node(node->left, max_in_left->value);
			node->right = delete_node(node->right, max_in_left->value);
		}
		
	}
	return node;
}

template<typename T>
void BinaryNode<T>::symmetric_print(const BinaryNode* node) {
	if (node == nullptr) return;
	symmetric_print(node->left);
	std::cout << node->value << std::endl;
	symmetric_print(node->right);
}

template<typename T>
void BinaryNode<T>::backward_print(const BinaryNode* node) {
	if (node == nullptr) return;
	backward_print(node->left);
	backward_print(node->right);
	std::cout << node->value << std::endl;
}

template<typename T>
void BinaryNode<T>::forward_print(const BinaryNode* node) {
	if (node == nullptr) return;
	std::cout << node->value << std::endl;
	forward_print(node->left);
	forward_print(node->right);
}

template<typename T>
void BinaryNode<T>::delete_tree(BinaryNode* node) {
	if (node == nullptr) return;
	delete_tree(node->left);
	delete_tree(node->right);
	delete node;
}

template<typename T>
const BinaryNode<T>* BinaryNode<T>::search(const BinaryNode* node, T value) {
	if (node == nullptr) return nullptr;
	if (node->value == value) return node;
	return (value > node->value) ? search(node->right, value) : search(node->left, value);
}

template<typename T>
const BinaryNode<T>* BinaryNode<T>::get_min(const BinaryNode* node) {
	if (node == nullptr) return nullptr;
	if (node->left == nullptr) return node;
	return get_min(node->left);
}

template<typename T>
const BinaryNode<T>* BinaryNode<T>::get_max(const BinaryNode* node) {
	if (node == nullptr) return nullptr;
	if (node->right == nullptr) return node;
	return get_max(node->right);
}
