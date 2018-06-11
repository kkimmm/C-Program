//
//  structure.h
//  SingleLinkList
//  链表的节点定义文件
//  Created by kai on 2018/3/16.
//  Copyright © 2018年 kai. All rights reserved.
//

#ifndef structure_h
#define structure_h

struct Node//单向链表结构
{
    int data;
    Node *next;
};

struct NodeD//双向链表结构
{
    int data;
    NodeD *piror;
    NodeD *next;
};


//以下函数功能都封装在其他.cpp文件中
class Node *Creat();
class Node *Creat_1();
class NodeD *Creat_2();
void printl(Node *head);
void printcr(Node *head);
void printdl(NodeD *head);
int Len(Node *head);
void InsertElem(Node *head, int n,int m);
void DeleteElem(Node *head, int n);
Node *sort_1(Node *head,int length);
Node *sort_2(Node *head,int length);
void Reverse(Node *head);
void Rprintl(Node *head);
int printK(Node *head,int k,int length);
bool HaveRing(Node *head);
int Mid(Node *head);
Node *head(Node *head,int length);
bool Intersect(Node *head1,Node *head2);
void del(NodeD *head,int k);
void ins(NodeD *head,int k,int m);
Node *sort_3(Node *head);
//Node *merge(Node *head1,Node *head2);

Node *mergeSortList(Node *head);
Node *merge(Node *head1, Node *head2);

#endif /* structure_h */

