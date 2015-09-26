#include <iostream>
#include <vector>

class bTreeNode
{
 public:
	bTreeNode():
		value_(0), left_(NULL), right_(NULL){}

	bTreeNode(int value, 
			  bTreeNode* left=NULL,
			  bTreeNode* right=NULL):
        value_(value), left_(left), right_(right) {
    }

    inline bool hasLeft() { return (left_ != NULL); }
    inline bool hasRight() { return (right_ != NULL); }
    inline bTreeNode* left() { return left_; }
    inline bTreeNode* right() { return right_; }
    inline int value() { return value_; }

    inline void setLeft(bTreeNode* node) { left_ = node; }
    inline void setRight(bTreeNode* node) { right_ = node; }

	~bTreeNode() {}

 private:
	int value_;
	bTreeNode* left_;
	bTreeNode* right_;
};

class binaryTree
{
 public:
	binaryTree(): root_(NULL){}
	~binaryTree();
 
	void goThroughTree();
	void goThroughTree(bTreeNode* root);
    void init(const std::vector<int>& input);
    void construct(bTreeNode* root, bTreeNode* node);
    void destroy(bTreeNode* root);

 private:
	bTreeNode *root_;

};
