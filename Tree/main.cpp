//
//  main.cpp
//  Tree
//
//  Created by kai on 2018/3/17.
//  Copyright © 2018年 kai. All rights reserved.
//

#include "structure.h"
using namespace std;

int main() {
    cout<<"input number to create a binary tree, input # means null or leaf node(example input: 124##5##3##):"<<endl;
    BitNode *root = NULL;
    Create(root);
    cout<<"using PreOrderTravers is:";
    PreOrderTraversal(root);
    cout<<endl;
    cout<<"using MidOrderTraverse is:";
    MidOrderTraverse(root);
    cout<<endl;
    cout<<"using LastOrderTraverse is:";
    LastOrderTraverse(root);
    cout<<endl;
    cout<<"using BreadthFirstSearch is:";
    BreadthFirstSearch(root);
    cout<<endl;
    /*cout<<"using DeepthFirstSearch is:";
    DeepthFirstSrearch(root);
    cout<<endl;*/
    cout<<"node's number of the tree is:";
    cout<<Nodes(root)<<endl;
    cout<<"the deepth of the tree is:";
    cout<<Deepth(root)<<endl;
    cout<<"input a number(notice:smaller than the deepth):";
    int k;cin>>k;
    cout<<"the "<<k<<"th layer's leaf nodes is:";
    cout<<LeafNodes(root,k)<<endl;
    bool flag = IsCompleteBinaryTree(root);
    if (flag==true)
        cout<<"the tree is a complete binary tree!"<<endl;
    if(flag == false)
        cout<<"the tree is not a complete binary tree"<<endl;

    return 0;
}
