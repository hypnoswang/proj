#include <iostream>

using namespace std;

class bTreeNode
{
 public:
	bTreeNode():
		value(0), left_p(NULL), right_p(NULL){}
	bTreeNode(int value, 
			  bTreeNode* left_p=NULL,
			  bTreeNode* right_p=NULL);
	~bTreeNode();

 private:
	int value;
	bTreeNode* left_p;
	bTReeNode* right_p;
};

class binaryTree
{
 public:
	binaryTree(): root(NULL){}
	~binaryTree();
 
	void insertNode(bTreeNode* node_p);
	void goThroughTree(bTreeNode* root_p);

 private:
	bTreeNode *root;

};
