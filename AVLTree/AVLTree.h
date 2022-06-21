#ifndef AVLTREE_CPP
#define AVLTREE_CPP

struct Node {
	int data;
	Node* left;
	Node* right;
	Node() {
		left = nullptr;
		right = nullptr;
	}
};

class queue {
private:
	Node* front, * rear;
	int size, capacity;
public:
	queue() {
		front = nullptr;
		rear = nullptr;
		size = 0;
		capacity = 10;
	}
	void enqueue(const Node* node) {
		Node* newNode;
		newNode = new Node;
		newNode->data = node->data;
		if (isEmpty()) {
			front = newNode;
			rear = newNode;
		}
		else {
			rear->right = newNode;
			rear = newNode;
		}
		size++;
	}
	int dequeue() {
		int value = front->data;
		Node* temp = new Node;
		temp = front->right;
		delete front;
		front = temp;
		size--;
		return value;
	}
	bool isEmpty() const {
		if (size > 0)
			return false;
		else
			return true;
	}
	bool isFull() const {
		if (size == capacity)
			return true;
		else
			return false;
	}
};

class AVLTree {
private:
	Node* root;
	Node* rightRotate(Node* node) {
		Node* x = node->left;
		Node* y = x->right;
		x->right = node;
		node->left = y;
		return x;
	}
	Node* leftRotate(Node* node) {
		Node* x = node->right;
		Node* y = x->left;
		x->left = node;
		node->right = y;
		return x;
	}
	queue list;
public:
	AVLTree();
	int height(Node*);
	int getBalance(Node*);
	Node* newNode(int);
	void insert(int);
	Node* insertR(Node*, int);
	void deleteNode(int);
	Node* deleteNodeR(Node*, int);
	Node* minValueNode(Node*);
	void inorder() const;
	void inorderR(const Node*) const;
	void first10();
	void first10R(const Node* node);
	void print10();
};

#endif