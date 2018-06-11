//
//  matrix.cpp
//  DP
//  给定一个矩阵Matrix, 从左上角开始每次只能向右或者向下走,最后到达右下角的位置,路径上所有的树子累加起来就是路径和,返回所有的路径中最小的路径和
//  Created by kai on 2018/3/21.
//  Copyright © 2018年 kai. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace  std;
int msearchmin(int a[4][4],int n,int m)
{
    int Min[4][4];
    int i,j;
    Min[0][0] = a[0][0];
    for(int k=1;k<m;k++)
        Min[0][k] = a[0][k]+Min[0][k-1];
    for(int k2 =1;k2<n;k2++)
        Min[k2][0] = a[k2][0]+Min[k2-1][0];
    for(i=1;i<n;i++)
    {
        for(j=1;j<m;j++)
        {
            Min[i][j] = min(Min[i-1][j],Min[i][j-1])+a[i][j];
        }
    }
    return Min[i-1][j-1];
}
