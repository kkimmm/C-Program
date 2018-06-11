//
//  OtherOperation.cpp
//  SingleLinkList
//  这部分是常用的非基本操作函数
//  Created by kai on 2018/3/16.
//  Copyright © 2018年 kai. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "structure.h"
using namespace std;

bool Intersect(Node *head1,Node *head2)//判断两个链表是否相交
{
    bool flag = false;
    Node *p1 = head1->next;
    Node *p2 = head2->next;
    int i=1,j=1;
    while(p1->next!=NULL)
    {
        p1 = p1->next;
        i++;
    }
    while(p2->next!=NULL)
    {
        p2 = p2->next;
        j++;
    }
    if(i>=j)
    {
        for(int k=0;k<i-j;k++)
            p1 = p1->next;
        while(p1->next!=NULL)
        {
            p1 = p1->next;
            p2 = p2->next;
            if(p1==p2)
            {
                flag = true;
                break;
            }
        }
        
    }
    else
    {
        for(int k=0;k<j-i;k++)
            p2 = p2->next;
        while(p2->next!=NULL)
        {
            p2 = p2->next;
            p1 = p1->next;
            if(p2==p1)
            {
                flag = true;
                break;
            }
        }
    }
    return flag;
}



