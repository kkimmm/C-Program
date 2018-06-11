//
//  cratelinklist.cpp
//  SingleLinkList
//  链表定义部分
//  Created by kai on 2018/3/16.
//  Copyright © 2018年 kai. All rights reserved.
//

#include"structure.h"
#include <iostream>
using namespace std;
Node *Creat()//创建单链表
{
    Node *head = new Node;
    Node *p = head;
    int x,flag=1;
    while(flag)
    {
        cout<<"input a number,input 0 to stop:";
        cin>>x;
        if(x==0)
        {
            flag = 0;
        }
        else
        {
            Node *s = new Node;
            s->data = x;
            p->next=s;
            p=s;
        }
    }
    p->next = NULL;
    return head;
}

Node *Creat_1()//创建循环链表
{
    Node *head = new Node;
    Node *p = head;
    int x,flag=1;
    while(flag)
    {
        cout<<"input a number,input 0 to stop:";
        cin>>x;
        if(x==0)
        {
            flag = 0;
        }
        else
        {
            Node *s = new Node;
            s->data = x;
            p->next=s;
            p=s;
        }
    }
    p->next = head;
    return head;
}

NodeD *Creat_2()//创建双向链表
{
    NodeD *head = new NodeD;
    head->piror = NULL;
    //head->next = NULL;
    NodeD *p = head;
    int x,c=1;
    while(c)
    {
        cout<<"input a number to create a circle linklist, inout 0 to stop:";
        cin>>x;
        if(x!=0)
        {
            NodeD *s = new NodeD;
            s->data = x;
            s->piror = p;
            p->next = s;
            p=s;
        }
        else
        {
            c=0;
        }
    }
    p->next =NULL;
    
    return head;
}



