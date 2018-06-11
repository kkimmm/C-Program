//
//  main.cpp
//  StringMachingAlgorithm
//  常用字符串匹配算法
//  Created by kai on 2018/3/13.
//  Copyright © 2018年 kai. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace  std;
void SMatch_bf(string ostr,string tstr);

int main() {
    string ostr="ABCADE";
    string tstr="AD";
    SMatch_bf( ostr,tstr);

    return 0;
}

void SMatch_bf(string ostr,string tstr)//bf算法
{
    int n = ostr.length();//原字符串长度
    int m = tstr.length();//子字符串长度
    for(int i=0;i<n-m;i++)
    {
        int j;
        for(j=0;j<m;j++)
        {
            if(ostr[i+j]!=tstr[j])
                break;
        }
        if(j==m)
            printf("子字符串从第%d个字符开始匹配原字符串\n",i+1);
       /* else
            printf("error");*/
    }
}
