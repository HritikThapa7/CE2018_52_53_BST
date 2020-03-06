#include "BST.h"
#define MAX_SIZE 20

class ArrayBST : public BST {
	private:
		int element[MAX_SIZE];
	public:
		ArrayBST();
		~ArrayBST();
		
		
	void add(int data);
	void preOrderTraversal();
	void preOrderTraversal(int currentIndex);
	void inOrderTraversal();
	void inOrderTraversal(int currentIndex);
	bool search(int key);
	int getLeftChild(int currentIndex);
	int getRightChild(int currentIndex);
	int min();
	int max();
	void deleteKey();
	void deleteKey(int key);

	int returnIndex(int key);
	int minNode(int index);
};
