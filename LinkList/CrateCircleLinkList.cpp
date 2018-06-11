//
//  CrateCircleLinkList.cpp
//  SingleLinkList
//
//  Created by kai on 2018/3/16.
//  Copyright © 2018年 kai. All rights reserved.
//

#include <stdio.h>
#include "structure.h"

NodeD *Creat_2()
{
    NodeD *head = new NodeD;
    head->piror = NULL;
    //head->next = NULL;
    NodeD *p = head;
    int x,c=1;
    while(c)
    {
        cout<<"input a number to create a circle linklist, inout 0 to end";
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
