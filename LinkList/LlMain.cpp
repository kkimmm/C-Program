//
//  main.cpp
//  SingleLinkList
//  链表及其常用操作(已经封装到其他.cpp文件中)
//  Created by kai on 2018/3/15.
//  Copyright © 2018年 kai. All rights reserved.
//

#include <iostream>
#include <stack>
#include"structure.h"
using namespace std;
int main()
{
    //单链表相关操作
    Node *head = Creat();
    cout<<"the linklist is:";
    printl(head);
    cout<<endl;
    
    cout<<"the length of the linklist is："<<Len(head)<<endl;
    int x1,y1;
    cout<<"please input the position to insert:";
    cin>>x1;
    cout<<"please input the number you want to insert:";
    cin>>y1;
    InsertElem(head,x1,y1);
    cout<<"after insert the linklist is:";
    printl(head);
    cout<<endl;
    int x2;
    cout<<"please input the position to delete:";
    cin>>x2;
    DeleteElem(head,x2);
    cout<<"after delete the linklist is:";
    printl(head);
    cout<<endl;
    cout<<"after sort the linklist is:";
    //sort_1(head,Len(head));
    mergeSortList(head);
    printl(head);
    cout<<endl;
    cout<<"after reverse the linklist is:";
    Reverse(head);
    printl(head);
    cout<<endl;
    int x3,length =Len(head);
    cout<<"input a number you want to find from the end(to begin):";
    cin>>x3;
    cout<<x3<<"th from the end is:"<<printK(head,x3,length)<<endl;
    cout<<"now output the linklist from the end:";
    Rprintl(head);
    cout<<endl;
    bool flag = HaveRing(head);
    if(flag==true)
        cout<<"have ring"<<endl;
    else
        cout<<"no ring"<<endl;
    cout<<"the middle number of the linklist is:"<<Mid(head)<<endl;
    
    /*//循环链表操作
    Node *head_1 = Creat_1();
    cout<<"the circlelinklist is:";
    printcr(head_1);
    cout<<endl;
    bool flag_1 =HaveRing(head_1);
    if(flag_1==true)
        cout<<"have ring"<<endl;
    else
        cout<<"no ring"<<endl;*/
    
    /*//双向链表操作
    NodeD *head_2 = Creat_2();
    cout<<"the circle linklist is:";
    printdl(head_2);
    int x1;
    cout<<"input the position you want to delete:";
    cin>>x1;
    del(head_2,x1);
    cout<<"after delete the list is:";
    printdl(head_2);
    int x2,y2;
    cout<<"input the position you want to insert:";
    cin>>x2;
    cout<<"input the number you want to insert:";
    cin>>y2;
    cout<<"after insert the list is:";
    ins(head_2,x2,y2);
    printdl(head_2);
    */
    return 0;
}
