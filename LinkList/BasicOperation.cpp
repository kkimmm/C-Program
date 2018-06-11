//
//  BasicOperation.cpp
//  SingleLinkList
//  这部分是链表的常用基本操作
//  Created by kai on 2018/3/16.
//  Copyright © 2018年 kai. All rights reserved.
//

#include <stdio.h>
#include <stack>
#include"structure.h"
#include<iostream>
using namespace std;

void printl(Node *head)//单链表打印
{
    Node *p=head->next;
    while(p!=NULL)
    {
        cout<<p->data;
        p = p->next;
    }
}

void printcr(Node *head)//循环链表打印
{
    Node *p = head->next;
    while(p->next != head)
    {
        cout<<p->data;
        p = p->next;
    }
    cout<<p->data;
}

void printdl(NodeD *head)//双向链表打印
{
    NodeD *p = head->next;
    while(p!=NULL)
    {
        cout<<p->data;
        p = p->next;
    }
    cout<<endl;
}

int Len(Node *head)//计算链表长度
{
    Node *p=head->next;
    int i=0;
    while(p!=NULL)
    {
        i++;
        p = p->next;
    }
    return i;
}

void InsertElem(Node *head, int n,int m)//在第n个位置插入一个数m
{
    Node *p=head->next;
    for(int i=1;i<n-1;i++)
    {
        p = p->next;
    }
    Node *s = new Node;
    s->data = m;
    s->next=p->next;
    p->next=s;
    
}

void DeleteElem(Node *head, int n)//删除第n个位置的数
{
    Node *p=head->next;
    for(int i=1;i<n-1;i++)
        p=p->next;
    p->next=p->next->next;
}

void del(NodeD *head,int k)//双向链表删除第k个节点
{
    NodeD *p = head->next;
    for(int i=0;i<k-1;i++)
    {
        p = p->next;
    }
    p->piror->next = p->next;
    p->next->piror = p->piror;
}

void ins(NodeD *head,int k,int m)//双向链表在第k个位置添加数m
{
    NodeD *p = head->next;
    for(int i=1;i<k-1;i++)
    {
        p = p->next;
    }
    NodeD *s = new NodeD;
    s->data = m;
    s->next = p->next;
    p->next->piror = s;
    s->piror = p;
    p->next = s;
}

void Reverse(Node *head)//单链表反转
{
    Node *p1,*p2,*p3;
    p1 = head->next;
    p2 = head->next->next;
    p1->next =NULL;
    while(p2!=NULL)
    {
        p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }
    head->next=p1;
}

void Rprintl(Node *head)//使用栈从尾部到头部的打印链表
{
    Node *p = head->next;
    stack <int> sta;
    while(p!=NULL)
    {
        sta.push(p->data);
        p=p->next;
    }
    while(!sta.empty())
    {
        cout<<sta.top();
        sta.pop();
    }
}

int printK(Node *head,int k,int length)//双指针法打印倒数第k个数
{
    Node *p1 = head->next;
    Node *p2 = head->next;
    if(p1==NULL||k==0||k>length)
        return -1;
    else
    {
        for(int i=0;i<k-1;i++)
        {
            p1 = p1->next;
        }
        while(p1->next!=NULL)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2->data;
    }
}

bool HaveRing(Node *head)//快慢指针法判断链表是否有环
{
    Node *pfast = head->next;
    Node *pslow = head->next;
    bool flag = false;
    if(pfast==NULL)
        return flag;
    while(pfast->next!=NULL&&pfast->next->next!=NULL)
    {
        pfast = pfast->next->next;
        pslow = pslow->next;
        if(pfast==pslow)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

int Mid(Node *head)//快慢指针法寻找链表终点
{
    Node *pfast = head->next;
    Node *pslow = head->next;
    if(pfast==NULL)
        return pfast->data;
    while(pfast->next!=NULL&&pfast->next->next!=NULL)
    {
        pfast = pfast->next->next;
        pslow = pslow->next;
    }
    return pslow->data;
}
