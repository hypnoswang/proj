#include <iostream>

using namespace std;

#define ARRAY_SIZE	15
int input[ARRAY_SIZE] = { 12, 7, 3, 6, 2, 9, 10, 5, 8, 4, 11, 1, 13, 15, 14 };


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
