#include "AVLTree.h"
#include <iostream>

using namespace std;

AVLTree::AVLTree() {	}
int AVLTree::height(Node* node) {
	if (node == nullptr)
		return 0;
	else {
		int leftHeight = 1 + height(node->left);
		int rightHeight = 1 + height(node->right);
		if (leftHeight > rightHeight)
			return leftHeight;
		return rightHeight;
	}
}
int AVLTree::getBalance(Node* node) {
	if (node == nullptr)
		return 0;
	int leftHeight = 1 + height(node->left);
	int rightHeight = 1 + height(node->right);
	return rightHeight - leftHeight;
}

Node* AVLTree::newNode(int item) {
	Node* temp = new Node;
	temp->data = item;
	return temp;
}
void AVLTree::insert(int item) {
	root = insertR(root, item);
}
Node* AVLTree::insertR(Node* node, int item) {
	if (node == nullptr)
		return newNode(item);
	if (item < node->data)
		node->left = insertR(node->left, item);
	else if (item > node->data)
		node->right = insertR(node->right, item);

	int balance = getBalance(node);
	//left left case
	if (balance < -1 && item < node->left->data)
		return rightRotate(node);
	//right right case
	if (balance > 1 && item > node->right->data)
		return leftRotate(node);
	//left right case
	if (balance < -1 && item > node->left->data) {
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	//right left case
	if (balance > 1 && item < node->right->data) {
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
}

Node* AVLTree::minValueNode(Node* node) {
	Node* current = node;
	while (current->left != nullptr)
		current = current->left;
	return current;
}
void AVLTree::deleteNode(int item) {
	root = deleteNodeR(root, item);
}
Node* AVLTree::deleteNodeR(Node* node, int item) {
	if (node == nullptr)
		return node;
	if (item < node->data)
		node->left = deleteNodeR(node->left, item);
	else if (item > node->data)
		node->right = deleteNodeR(node->right, item);
	else {
		if (node->left == nullptr || node->right == nullptr) {
			Node* temp = node->left ? node->left : node->right;

			if (temp == nullptr) {
				temp = node;
				node = nullptr;
			}
			else
				*node = *temp;
			delete temp;
		}
		else {
			Node* temp = minValueNode(node->right);
			node->data = temp->data;
			node->right = deleteNodeR(node->right, temp->data);
		}
	}
	if (node == nullptr)
		return node;
	int balance = getBalance(node);
	//left left case
	if (balance < -1 && getBalance(node->left) < 0)
		return rightRotate(node);
	//left right case
	if (balance < -1 && getBalance(node->left) >= 0) {
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	//right right case
	if (balance > 1 && getBalance(node->right) > 0)
		return leftRotate(node);
	//right left case
	if (balance > 1 && getBalance(node->right) <= 0) {
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
}

void AVLTree::inorder() const {
	inorderR(root);
}
void AVLTree::inorderR(const Node* node) const {
	if (node != nullptr) {
		inorderR(node->left);
		cout << node->data << endl;
		inorderR(node->right);
	}
}

void AVLTree::first10() {
	first10R(root);
	print10();
}
void AVLTree::first10R(const Node* node) {
	if (node != nullptr && !list.isFull()) {
		first10R(node->left);
		list.enqueue(node);
		first10R(node->right);
	}
}void AVLTree::print10() {
	while (!list.isEmpty())
		cout << list.dequeue() << endl;
}