#ifndef BST_h
#define BST_h

class BST{
	public:
		virtual void add(int data)=0;
		virtual void preOrderTraversal()=0;
		virtual bool search(int data)=0;
		virtual int max_e() =0;
};

#endif
