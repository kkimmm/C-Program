//
//  LCS.cpp
//  DP
//
//  Created by kai on 2018/3/23.
//  Copyright © 2018年 kai. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int  LCS(string a,string b)
{
    int  c[100][100];
    int i,j;
    string temp;
    for(i=0;i<=a.size();i++)
    {
        for(j=0;j<=b.size();j++)
        {
            if(i==0||j==0)
            {
                c[i][j] = 0;
            }
            else
            {
                if(a[i-1]==b[j-1])
                {
                    c[i][j]=c[i-1][j-1]+1;
                    //temp+=b[j-1];
                }
                else
                {
                    c[i][j]=max(c[i-1][j],c[i][j-1]);
                }
            }
        }
    }
    /*for(int k1=0;k1<i;k1++)
    {
        for(int k2=0;k2<j;k2++)
        {cout<<c[k1][k2];}
        cout<<endl;
    }*/
    //cout<<temp<<endl;
    return c[i-1][j-1];
}
