//
//  LIS.cpp
//  DP
//
//  Created by kai on 2018/3/23.
//  Copyright © 2018年 kai. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int LIS(int a[],int asize)
{
    int temp[100]={};
    int tsize = sizeof(temp)/sizeof(int);
    for(int k=0;k<tsize;k++)
        temp[k]=1;
    
    int i,j;
    for(j=1;j<asize;j++)
    {
        for(i=0;i<j;i++)
        {
            if(a[j]>a[i]&&temp[j]<temp[i]+1)
                temp[j] = temp[i]+1;
        }
    }
    
    return temp[j-1];

}
