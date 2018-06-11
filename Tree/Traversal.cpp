//
//  Traversal.cpp
//  Tree
//  常用遍历方式
//  Created by kai on 2018/3/18.
//  Copyright © 2018年 kai. All rights reserved.
//

#include <stdio.h>
#include "structure.h"
using namespace std;

void PreOrderTraversal(BitNode *root)//递归的前序遍历
{
    if (root)
    {
        cout << root->data;
        PreOrderTraversal(root->lchild);
        PreOrderTraversal(root->rchild);
    }
}

void MidOrderTraverse(BitNode *T)//递归的中序遍历
{
    if(T)
    {
        MidOrderTraverse(T->lchild);
        cout<<T->data;
        MidOrderTraverse(T->rchild);
    }
}


void LastOrderTraverse(BitNode *T)//递归的后续遍历
{
    if(T)
    {
        LastOrderTraverse(T->lchild);
        LastOrderTraverse(T->rchild);
        cout<<T->data;
    }
}

void BreadthFirstSearch(BitNode *root)//广度优先遍历（搜索），亦即层序遍历
{
    queue<BitNode *> vec;
    vec.push(root);
    while(!vec.empty())
    {
        BitNode *node = vec.front();
        cout<<node->data;
        if(node->lchild!=NULL)
            vec.push(node->lchild);
        if(node->rchild!=NULL)
            vec.push(node->rchild);
        vec.pop();
        
    }
    
}

void DeepthFirstSrearch(BitNode *root)//深度优先遍历
{
    stack<BitNode *> sta;
    sta.push(root);
    while(!sta.empty())
    {
        BitNode *p=sta.top();
        cout<<p->data;
        sta.pop();
        if(p->rchild!=NULL)
            sta.push(p->rchild);
        if(p->rchild!=NULL)
            sta.push(p->lchild);
    }
    
}
