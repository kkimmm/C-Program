//
//  CreatTree.cpp
//  Tree
//
//  Created by kai on 2018/3/18.
//  Copyright © 2018年 kai. All rights reserved.
//

#include <stdio.h>
#include "structure.h"

void Create(BitNode *&root)
{
    char ch;
    ch = getchar();
    if (ch== '#')//注意使用''而不是""
        root = NULL;
    else
    {
        root = new BitNode;
        root->data = ch;
        Create(root->lchild);
        Create(root->rchild);
    }
}
