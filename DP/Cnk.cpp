//
//  Cnk.cpp
//  DP
//
//  Created by kai on 2018/3/21.
//  Copyright © 2018年 kai. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace  std;
void printl(int a[4][4]);

void Cnk()
{
    int n=4;
    int a[4][4];
    for(int k1=0;k1<n;k1++)
        for(int k2=0;k2<n;k2++)
            a[k1][k2]=0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(i==0||i==j||j==0)
                a[i][j] =1;
            else
            {
                a[i][j] = a[i-1][j]+a[i-1][j-1];
            }
        }
    }
    printl(a);
}

void printl(int a[4][4])
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}


