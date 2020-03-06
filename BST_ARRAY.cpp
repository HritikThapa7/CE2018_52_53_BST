#include <iostream>
#include "tree.h"
#include <stddef.h>
using namespace std;

ArrayBST::ArrayBST(){
	for(int i=0;i<MAX_SIZE; i++){
	this->element[i]=0;	
	}
	
}
// inserting data into the tree
void ArrayBST::add(int data){
	int currentIndex=0;
	cout<<"Adding "<<data<<endl;
	
	while(true){
		if(element[currentIndex]==NULL){
			element[currentIndex]=data;
			cout<<"Already Inserted "<<data<<" at Index "<<currentIndex<<endl;
			break;
		}
		
		else if(data>element[currentIndex]){
			if(data==element[currentIndex]){
				cout<<"Data already present!"<<endl;
				break;
			}
			else{
				cout<<"Inserting right: "<<endl;
				currentIndex=(2*currentIndex)+2;
			}
		}
		else if(data<element[currentIndex]){
			if(data==element[currentIndex]){
					cout<<"Data already present!"<<endl;
				break;
			}
			else{
				cout<<"Inserting left: "<<endl;
				currentIndex=(2*currentIndex)+1;
			}
			
		}
	}
}


//searching data
bool ArrayBST::search(int key){
	int currentIndex=0;
	cout<<"Searching "<<key<<endl;
	
	while(true){
		if(element[currentIndex]==NULL){
			cout<<"Key Not Found!"<<endl;
			break;
		}
		if(key==element[currentIndex]){
			cout<<"Key  Found at Index "<< currentIndex << endl;
			break;
		}
		
		else if(key>element[currentIndex]){
			currentIndex=(2*currentIndex)+2;
			
		}
		else if(key < element[currentIndex]){
			currentIndex=(2*currentIndex)+1;
			
		}
	}
}

//getting left child
	int ArrayBST:: getLeftChild(int currentIndex){
		if((element[currentIndex]!=NULL) && ((2*currentIndex+1) <= MAX_SIZE)){
			return 2*currentIndex+1;
		
		}
		else{
			return -1;
		}
	}

//getting right child
	
	int ArrayBST:: getRightChild(int currentIndex){
		if((element[currentIndex]!=NULL) && ((2*currentIndex+2) <= MAX_SIZE)){
			return (2*currentIndex+2);
		
		}
		else {
			return -1;
		}
	
	}
	
	
	//preOrder traversal

void ArrayBST::preOrderTraversal(){
	preOrderTraversal(1);
}
	
void ArrayBST::preOrderTraversal(int currentIndex) {
    if((currentIndex >= 0) && (element[currentIndex] != NULL)){
    	
       	cout << element[currentIndex]<<endl;
		preOrderTraversal(getLeftChild(currentIndex));
        preOrderTraversal(getRightChild(currentIndex));
        
        
    }
}


int ArrayBST::min(){
	int currentIndex=0;
	while(element[getLeftChild(currentIndex)]!=NULL){
	//	currentIndex = getLeftChild(currentIndex);
		currentIndex = 2*currentIndex+1;
		

	}
		return (element[currentIndex]);	
}


int ArrayBST::max(){
	int currentIndex=0;
	while(element[getRightChild(currentIndex)]!=NULL){
		currentIndex = 2*currentIndex+2;
		

	}
		return (element[currentIndex]);	
}

int ArrayBST::returnIndex(int key){
	int currentIndex=0;

	while(true){
		if(element[currentIndex]==0){
			break;
		}
		if(key==element[currentIndex]){
			return currentIndex;
			break;
		}

		else if(key>element[currentIndex]){
			currentIndex=(2*currentIndex)+2;

		}
		else if(key < element[currentIndex]){
			currentIndex=(2*currentIndex)+1;

		}
	}
}

int ArrayBST::minNode(int index){
	while(element[ArrayBST::getLeftChild(index)]!=0){
        index= 2* index + 1;
    }

    return element[index];
}

void ArrayBST::deleteKey(){
	deleteKey(1);
}

void ArrayBST::deleteKey(int key){

		if(ArrayBST::search(key)==true){
		int currentIndex = ArrayBST::returnIndex(key);
		int leftChild = element[ArrayBST::getLeftChild(currentIndex)];
		int rightChild = element[ArrayBST::getRightChild(currentIndex)];
		
		if(leftChild==NULL && rightChild== NULL){
			element[currentIndex]=NULL;
			cout<<"Delete Sucessfull!!"<<endl;
		}
		else if(leftChild==NULL && rightChild!=NULL){
			element[currentIndex] = NULL;
			element[currentIndex]=rightChild;
			element[ArrayBST::returnIndex(rightChild)]= NULL;
			cout<<"Delete Sucessfull!!"<<endl;
		}
		else if(leftChild!=NULL && rightChild==NULL){
			element[currentIndex] = NULL;
			element[currentIndex]= leftChild;
			element[ArrayBST::returnIndex(leftChild)]= NULL;
			cout<<"Delete Sucessfull!!"<<endl;
		}
		else if(leftChild!=NULL && rightChild!=NULL){
			int index = ArrayBST::returnIndex(rightChild);
			int minNodeIndex = ArrayBST::returnIndex(ArrayBST::minNode(index));
			element[currentIndex] = NULL;
			element[currentIndex] = ArrayBST::minNode(index);
			element[minNodeIndex] = NULL;
			cout<<"Deleted "<<key<<endl;
					
		}
		else 
			return;
	}
		else if(ArrayBST::search(key)==false)
		cout<<"Sorry the BST doesn't contain "<< key <<" . "<<endl;
}



ArrayBST::~ArrayBST(){}
int main(){
	ArrayBST a;
	a.add(6);
	a.add(2);
	a.add(8);
	a.add(10);
	a.add(5);
	a.search(10);
	cout<<"Pre-order Traversal:"<<endl;
	a.preOrderTraversal(0);
	
	cout<<"In order Traversal:"<<endl;
	a.inOrderTraversal(0);
	cout<<endl<<"Minm element is:" << a.min()<<endl;
	cout<<endl<<"Maxm element is:" << a.max()<<endl;
	cout<<"Deletion: "<<endl;
	a.deleteKey(10);
	return 0;
}
