//
//  BasicOperation.cpp
//  Tree
//
//  Created by kai on 2018/3/19.
//  Copyright © 2018年 kai. All rights reserved.
//

#include <stdio.h>
#include "structure.h"

int Nodes(BitNode *root)
{
    if(root==NULL)
        return 0;
    else
        return Nodes(root->lchild)+Nodes(root->rchild)+1;
}

int Deepth(BitNode *root)
{
    if(root==NULL)
        return 0;
    else
    {
        int leftdeepth = Deepth(root->lchild);
        int righdeepth = Deepth(root->rchild);
        return (leftdeepth>righdeepth)?(leftdeepth+1):(righdeepth+1);
    }
}

int LeafNodes(BitNode *root,int k)//第k层叶子节点个数
{
    if(root==NULL||k<1)
        return 0;
    if(k==1)
        return 1;
    else
    {
        int leftnodes, rightnodes;
        leftnodes =  LeafNodes(root->lchild,k--);
        rightnodes =  LeafNodes(root->rchild,k--);
        return leftnodes+rightnodes;
    }
}

bool IsCompleteBinaryTree(BitNode *root)
{
    if(root ==NULL)
        return true;
    queue<BitNode*> que;
    que.push(root);
    BitNode *p = root;
    while(1)
    {
        que.push(p->lchild);
        que.push(p->rchild);
        que.pop();
        if(que.front()!=NULL)
            p = que.front();
        else
            break;
    }
    while(!que.empty())
    {
        BitNode *p = que.front();
        if(p!=NULL)
            return false;
        que.pop();
    }
    return true;
}


