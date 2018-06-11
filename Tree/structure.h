//
//  structure.h
//  Tree
//
//  Created by kai on 2018/3/18.
//  Copyright © 2018年 kai. All rights reserved.
//

#ifndef structure_h
#define structure_h
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct BitNode
{
    char data;
    BitNode *lchild, *rchild;
    // BitNode(char x) :data(x), left(0), right(0){}
};
void Create(BitNode *&root);
void PreOrderTraversal(BitNode *root);
void MidOrderTraverse(BitNode *T);
void LastOrderTraverse(BitNode *T);
void BreadthFirstSearch(BitNode *root);
void DeepthFirstSrearch(BitNode *root);
int Nodes(BitNode *root);
int Deepth(BitNode *root);
int LeafNodes(BitNode *root,int k);
bool IsCompleteBinaryTree(BitNode *root);

#endif /* structure_h */
