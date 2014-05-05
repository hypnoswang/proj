#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
					 12
				   /   \
				   7   13
				 /  \    \
				3    9    15
			  /  \  / \   /
			 2	 6 8  10 14
			/   /      \
		   1   5       11
			  /
			 4 
*/

#define ARRAY_SIZE	15
int input[ARRAY_SIZE] = { 12, 7, 3, 6, 2, 9, 10, 5, 8, 4, 11, 1, 13, 15, 14 };

typedef struct bTreeNode{
	int value;
	
	struct bTreeNode* left_p;
	struct bTreeNode* right_p;
} bTreeNode;

bTreeNode*	root_p = NULL;

int insertNode( bTreeNode* cur_p, int value )
{
	bTreeNode* tmp_p = NULL;
	
	tmp_p = (bTreeNode *)malloc( sizeof(bTreeNode) );
	if( tmp_p == NULL ){
		printf("malloc failed!!\n");
		return -1;
	}
	
	tmp_p->value = value;
	tmp_p->left_p = NULL;
	tmp_p->right_p = NULL;
	
	if( cur_p == NULL ){
		root_p = tmp_p;
		return 0;
	}
	
	if( value < cur_p->value ){
		if( cur_p->left_p == NULL ){
			cur_p->left_p = tmp_p;
			return 0;
		} else {
			insertNode( cur_p->left_p, value );
		}
	} else {
		if( cur_p->right_p == NULL ){
			cur_p->right_p = tmp_p;
			return 0;
		}else{
			insertNode( cur_p->right_p, value );
		}
	}
	
	return 0;
}

int constructTree()
{
	int i = 0;
	
	for( i=0; i<ARRAY_SIZE; i++ ){
		insertNode( root_p, input[i] );
	}
	
	return 0;	
}

int insertNode2( bTreeNode** cur_root_p, int value )
{
	bTreeNode* tmp_p = NULL;
	
	tmp_p = (bTreeNode *)malloc( sizeof(bTreeNode) );
	if( tmp_p == NULL ){
		printf("malloc failed!!\n");
		return -1;
	}
	
	tmp_p->value = value;
	tmp_p->left_p = NULL;
	tmp_p->right_p = NULL;
	
	if( *cur_root_p == NULL ){
		*cur_root_p = tmp_p;
		return 0;
	}
	
	if( value < (*cur_root_p)->value ){
		return insertNode2( &(*cur_root_p)->left_p, value );
	}else{
		return insertNode2( &(*cur_root_p)->right_p, value );
	}
	
	return 0;
}

int constructTree2()
{
	int i = 0;
	
	for( i=0; i<ARRAY_SIZE; i++ ){
		insertNode2( &root_p, input[i] );
	}
	
	return 0;	
}

int printTree( bTreeNode* cur_p )
{
	if( cur_p->left_p != NULL ){
		printTree( cur_p->left_p );
	}
	
	printf("\t%d", cur_p->value );
	
	if( cur_p->right_p != NULL ){
		printTree( cur_p->right_p );
	}
	
	return 0;
	
}



bTreeNode* g_head_p = NULL;
bTreeNode* g_tail_p = NULL;

void convertTreeToLink( bTreeNode* cur_root_p )
{
	bTreeNode* tmp_p = cur_root_p;
	bTreeNode* left_p = tmp_p->left_p;
	bTreeNode* right_p = tmp_p->right_p;
	
	
	if( left_p != NULL ){
		convertTreeToLink( left_p );
	}
	
	if( g_head_p == NULL ){
		g_head_p = tmp_p;
		g_head_p->left_p = NULL;
		g_head_p->right_p = NULL;
		g_tail_p = g_head_p;
	}else{
		g_tail_p->right_p = tmp_p;
		tmp_p->left_p = g_tail_p;
		tmp_p->right_p = NULL;
		g_tail_p = tmp_p;
	}
	
	if( right_p != NULL ){
		convertTreeToLink( right_p );
	}
	
	return;
}

void printLink( )
{
	bTreeNode *tmp_p = g_head_p;
	
	while( tmp_p != NULL ){
		printf("\t%d", tmp_p->value);
		tmp_p = tmp_p->right_p;
	}
	
	return;
}

void testConstructTree1()
{
	constructTree();
	printTree( root_p );
}

void testConstructTree12()
{
	constructTree2();
	printTree( root_p );
}

void testConvertTree()
{
	constructTree2();
	
	convertTreeToLink(root_p);
	printLink();
	
}

int main(int argc, char *argv[]) 
{
	//testConstructTree1();
	//testConstructTree2();
	testConvertTree();
	
	return 0;
}
