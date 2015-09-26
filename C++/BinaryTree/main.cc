#include <iostream>

#include "binaryTree.h"

#define ARRAY_SIZE	15
int input[ARRAY_SIZE] = { 12, 7, 3, 6, 2, 9, 10, 5, 8, 4, 11, 1, 13, 15, 14 };


int main() {
    std::vector<int> ivec;

    for(int i = 0; i < ARRAY_SIZE; ++i) {
       ivec.push_back(input[i]); 
    }

    binaryTree bt;

    bt.init(ivec);

    bt.goThroughTree();

    return 0;
}
