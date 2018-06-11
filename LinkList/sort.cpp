//
//  doublelinklist.cpp
//  SingleLinkList
//  本部分是链表排序功能区
//  Created by kai on 2018/3/16.
//  Copyright © 2018年 kai. All rights reserved.
//

#include"structure.h"
#include<iostream>
using namespace std;

Node *sort_1(Node *head,int length)//排序,仅交换数字域的冒泡排序
{
    Node *p1 =head->next;
    Node *p2 = head->next;
    for(int i=0;i<length&&p1->next!=NULL;i++)
    {
        for(int j=0;j<length&&p2->next!=NULL;j++)
        {
            if(p2->data>p2->next->data)
            {
                int temp = p2->next->data;
                p2->next->data = p2->data;
                p2->data=temp;
            }
            p2 =p2->next;
        }
        p1 = p1->next;
    }
    return head;
}

Node *sort_2(Node *head,int length)//排序，交换节点的冒泡排序
{
    Node *p1 = head->next;
    Node *p2 = head->next;
    Node *p3,*p4;
    for(int i=0;i<length&&p1->next!=NULL;i++)
    {
        for(int j=0;j<length&&p2->next!=NULL;j++)
        {
            p3 = p2->next;
            if(p2->data>p3->data)
            {
                p2->next = p3->next;
                p3->next = p2;
                p4->next = p3;
                Node *temp = p2;
                p2 = p3;
                p3 = temp;
            }
            p4 = p2;
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    return head;
}

Node *mergeSortList(Node *head)//归并排序(归并排序在链表中时间复杂度是o(nlogn)，空间复杂度降到了o(1),相对来说是最好的排序算法)
{
    if(head == NULL || head->next == NULL)return head;
    else
    {
        //快慢指针找到中间节点
        Node *fast = head,*slow = head;
        while(fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow;
        slow = slow->next;
        fast->next = NULL;//注意要断开
        fast = mergeSortList(head);//前半段排序
        slow = mergeSortList(slow);//后半段排序
        return merge(fast,slow);
    }
    
}
//两个链表归并排序
Node *merge(Node *head1, Node *head2)
{
    if(head1 == NULL)return head2;
    if(head2 == NULL)return head1;
    Node *res , *p ;
    if(head1->data < head2->data)
    {res = head1; head1 = head1->next;}
    else{res = head2; head2 = head2->next;}
    p = res;
    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data < head2->data)
        {
            p->next = head1;
            head1 = head1->next;
        }
        else
        {
            p->next = head2;
            head2 = head2->next;
        }
        p = p->next;
    }
    if(head1 != NULL)p->next = head1;
    else if(head2 != NULL)p->next = head2;
    return res;
}

/*Node *sort_3(Node *head)//归并排序(归并排序在链表中时间复杂度是o(nlogn)，空间复杂度降到了o(1),相对来说是最好的排序算法)
 {
 //先排序找到中间节点
 Node *pfast = head->next;
 Node *pslow = head->next;
 if(pfast==NULL||head ==NULL)
 return head;
 while(pfast->next!=NULL&&pfast->next->next!=NULL)
 {
 pfast = pfast->next->next;
 pslow = pslow->next;
 }
 sort_3(pslow->next);
 pslow->next = NULL;//注意要断开
 sort_3(head->next);
 return merge(pslow->next,head->next);
 }
 
 Node *merge(Node *head1,Node *head2)
 {
 if(head1==NULL)
 return  head2;
 if(head2==NULL)
 return head1;
 Node *res=NULL,*p=NULL;
 if(head1->data<head2->data)
 {
 res = head1;
 head1 = head1->next;
 }
 else if(head1->data>head2->data)
 {
 res = head2;
 head2 = head2->next;
 }
 p = res;
 while (head1!=NULL&&head2!=NULL)
 {
 if(head1->data<head2->data)
 {
 p->next=head1;
 head1 = head1->next;
 }
 if(head1->data>head2->data)
 {
 p->next = head2;
 head2 = head2->next;
 }
 }
 p = p->next;
 if(head1!=NULL)
 p->next = head1;
 else if(head2!=NULL)
 p->next = head2;
 return res;
 }
 
 */
