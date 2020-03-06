#include <iostream>
#include "BST.h"

class Node{

	public:
		int info;
		Node* left;
		Node* right;

};

class node{
	public:
		Node* info;
		node* next;
};

class LLBST : public BST{	
	public:	
	Node* root;
	LLBST();
	Node* getroot();
	void add(int data);
	void preOrderTraversal();
	bool search(int data);
	bool isEmpty();
	void inOrderTraversal();
	int min();
	int max();
	Node* min(Node *root);
	Node* max(Node *root);
	void deleteKey();
	Node* deleteKey(Node *root, int key);
};

class Stack{
	public:
		Stack();
		~Stack();

		void push(Node* a);
		Node* pop();
		bool isEmpty();
		bool isFull();
		int peak();

	private:
		node* stack;
		node* top;

};
