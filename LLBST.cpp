#include <iostream>
#include "BST.h"
#include "LLBST.h"

Stack::Stack(){
	stack = NULL;
	top = NULL;
}

Stack::~Stack(){}

LLBST::LLBST(){
	root = NULL;
}

Node* LLBST::getroot(){
	return root;
}

bool Stack::isEmpty(){
	if(stack == NULL){
		return true;
	}
	else{
		return false;
	}
}

void Stack::push(Node *a){
	node* newNode = new node();
	newNode->info = a;
	if(isEmpty()){
		newNode->next = newNode;
		stack = newNode;
	}
	else{
		newNode->next=stack->next;
		stack->next=newNode;
	}
}
Node* Stack::pop(){
	if(isEmpty()){
		std::cout<<"Stack Underflow"<<std::endl;
	}
	else{
		top=stack->next;
		Node* data=top->info;
		stack->next=top->next;
		if(top==stack){
			stack=NULL;
		}
		return data;
	}
}





void LLBST::add(int data){
	if (isEmpty()) {
	    Node *newNode= new Node();
		root = newNode;
		root->info = data;
	}
	else {
		Node* newnode = root;
		Node* pre = NULL;
		bool l = false;
		bool r = false;
		while (newnode != NULL) {
			pre = newnode;
			l = false;
			if (data < newnode->info) {
				newnode = newnode->left;
				l = true;
			}
			else if (data > newnode->info) {
				newnode = newnode->right;
			}
		}
		if (l) {
			Node* n = new Node();
			n->info = data;
			pre->left = n;
		}
		else {
			Node* n = new Node();
			n->info = data;
			pre->right = n;
		}
	}

}


void LLBST::preOrderTraversal(){
    Stack st;
	st.push(root);
	Node* a;
	while (!st.isEmpty()) {
		a=st.pop();
		std::cout << a->info << " ";
		if (a->right != NULL)	st.push(a->right);
		if (a->left != NULL)	st.push(a->left);
	}

}

void LLBST::inOrderTraversal(){
	Stack st;
	Node* a = root;
	while(!st.isEmpty() || a != NULL){
		while(a != NULL){
			st.push(a);
			a = a->left ;
		}

		a = st.pop();
		std::cout << a->info <<" ";
		a = a->right;
	}

}


bool LLBST::search(int data){
    Node* prev;
    prev=root;
    while(prev!=NULL){
        if(prev->info==data){
            return true;
        }
        else if(data<prev->info){
            prev=prev->left;
        }
        else if(data>prev->info){
            prev=prev->right;
        }
    }
    return false;
}
int LLBST:: min(){
	Node* res = min(root);
	return res->info;
}
Node* LLBST:: min(Node *root){
	Node* a = root;
	while(a->left != NULL){
		a = a->left;
	}
	return a;
}

int LLBST::max(){
	Node* res = max(root);
	return res->info;
}

Node* LLBST::max(Node* root){
	Node *p=root;
	while(p->right!=NULL){
		p=p->right;
	}
	return p;
}

bool LLBST::isEmpty() {
	if(root==NULL){
	    return true;
	}
	else{
	    return false;
	}
}

void LLBST::deleteKey(){
	deleteKey(root,6);
}

Node* LLBST::deleteKey(Node* root, int key){
	if(root==NULL){
		return root;
	}
	if(key<root->info){
		return deleteKey(root->left,key);
	}
	else if(key>root->info){
		return deleteKey(root->right,key);
	}
	else{
		if(root->left==NULL){
			Node* temp=root->right;
			delete(root);
			return temp;
		}
		else if(root->right==NULL){
			Node *temp=root->left;
			delete(root);
			return temp;
		}
		else{
			Node* current = root->right; 
    		while (current && current->left != NULL) {
    			current = current->left;
			}
			Node* temp=current;
			root->info=temp->info;
			root->right=deleteKey(root->right,temp->info);
		}
	}
	return root;
}


int main(){
	LLBST h;
	h.add(5);
	h.add(8);
	h.add(2);
	h.add(7);
	h.add(13);
	Node* p = h.deleteKey(h.getroot(), 2);
	
	h.preOrderTraversal();
	h.inOrderTraversal();

	
	std::cout<<"\nThe smallest element is "<< h.min() <<std::endl;
	
    if(h.search(12)){
    	std::cout<<"Found"<<std::endl;
    }
    else{
        std::cout<<"Not Found"<<std::endl;
    }
}