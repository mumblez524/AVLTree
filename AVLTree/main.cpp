#include <iostream>
#include <fstream>
#include "AVLTree.h"

using namespace std;

int main() {
	AVLTree tree;
	int option, num, value, byebyeNode;
	char choice;
	cout << "Choose your option:\n\t1- Create an AVL tree manually.\n\t2- Create an AVL tree by reading from a file.\nOption (number only): ";
	cin >> option;
	if (option == 1) {
		cout << "Enter the number of nodes to be inserted: ";
		cin >> num;
		cout << "Enter node values:\n\n";
		int i = 0;
		while (i < num) {
			cin >> value;
			tree.insert(value);
			i++;
		}
		cout << "\nInorder Tree Traversal:\n\n";
		tree.inorder();
		cout << "\nWanna delete a node (Y/N): ";
		cin >> choice;
		while (choice == 'Y' || choice == 'y') {
			cout << "\nEnter the value to be deleted:\n";
			cin >> byebyeNode;
			tree.deleteNode(byebyeNode);
			cout << "\nInorder Tree Traversal:\n";
			tree.inorder();
			cout << "\nWanna delete a node (Y/N): ";
			cin >> choice;
		}
	}
	else if (option == 2) {
		cout << "Reading from file...";
		ifstream input;
		int temp;
		input.open("values.txt");
		input >> temp;
		if (!input) {
			cout << "Error!" << endl;
			system("PAUSE");
			return 0;
		}
		while (!input.eof()) {
			input >> value;
			tree.insert(value);
		}
		input.close();
		cout << "\n\nTree is created\n\n";
		cout << "Printing the first 10 nodes...\n\n";
		tree.first10();
	}
	system("PAUSE");
	return 0;
}