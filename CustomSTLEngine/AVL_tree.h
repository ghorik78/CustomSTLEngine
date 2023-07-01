#pragma once

#include <algorithm>
#include <iostream>

template<typename T>
class AVLNode {
public:
	T value;

	int height = 0;

	AVLNode<T>* left = nullptr;
	AVLNode<T>* right = nullptr;

	AVLNode(T value);
	~AVLNode();

	int get_height(const AVLNode* node);
	int get_balance(const AVLNode* node);

	AVLNode* delete_node(AVLNode* node, T value);

	void update_height(AVLNode* node);

	void insert(AVLNode* node, T value);
	
	void right_rotate(AVLNode* node);
	void left_rotate(AVLNode* node);
	void right_left_rotate(AVLNode* node);
	void left_right_rotate(AVLNode* node);

	void symmetric_print(const AVLNode* node);
	void backward_print(const AVLNode* node);
	void forward_print(const AVLNode* node);

	void delete_tree(AVLNode* node);

	const AVLNode* search(const AVLNode* node, T value);
	const AVLNode* get_min(const AVLNode* node);
	const AVLNode* get_max(const AVLNode* node);
};

template<typename T>
AVLNode<T>::AVLNode(T value) : value(value) {}

template<typename T>
AVLNode<T>::~AVLNode() {}

template<typename T>
int AVLNode<T>::get_height(const AVLNode* node) {
	return (node == nullptr) ? -1 : height;
}

template<typename T>
int AVLNode<T>::get_balance(const AVLNode* node) {
	return (node == nullptr) ? 0 : get_height(node->right) - get_height(node->left);
}

template<typename T>
void AVLNode<T>::update_height(AVLNode* node) {
	node->height = std::max(get_height(node->right), get_height(node->right)) + 1;
}

template<typename T>
void AVLNode<T>::right_rotate(AVLNode* node) {
	AVLNode* buffer = node->left;
	node->left = buffer->right;
	buffer->right = node;
	update_height(node);
	update_height(buffer);
}

template<typename T>
void AVLNode<T>::left_rotate(AVLNode* node) {
	AVLNode* buffer = node->right;
	node->right = buffer->left;
	buffer->left = node;
	update_height(node);
	update_height(node->right);
}

template<typename T>
void AVLNode<T>::right_left_rotate(AVLNode* node) {

}

template<typename T>
void AVLNode<T>::insert(AVLNode* node, T value) {
	if (node == nullptr) return;
	
	if (value < node->value) {
		if (node->left == nullptr) node->left = new AVLNode(value);
		else insert(node->left, value);
	}

	if (value >= node->value) {
		if (node->right == nullptr) node->right = new AVLNode(value);
		else insert(node->right, value);
	}

}

template<typename T>
void AVLNode<T>::forward_print(const AVLNode* node) {
	if (node == nullptr) return;
	std::cout << node->value << std::endl;
	forward_print(node->left);
	forward_print(node->right);
}