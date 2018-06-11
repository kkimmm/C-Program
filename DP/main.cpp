//
//  main.cpp
//  DP
//  一些典型的动态规划算法
//  Created by kai on 2018/3/21.
//  Copyright © 2018年 kai. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#define Max 100

using namespace std;
int msearchmin(int a[4][4],int n,int m);
void Cnk();
int n ;//fib
int temp[]={};
int Fib(int n);
int Fib_2(int n);
int data[100][100]={};//Ttower
int a1[Max][Max];
int Ttower(int i,int j);
int Ttower_2(int i,int j);
int  LCS(string a,string b);
int LIS(int a[],int asize);
int main()
{
    int press;
    cout<<"请输入下列问题对应的数字查看相应问题求解："<<endl<<"1.求矩阵权值路径最小和问题\n2.组合数C(n,k)\n3.斐波那契数列问题\n4.三角塔问题\n5.最长公共子序列问题\n6.最长递增子序列\n";
    while(cin>>press)
    {
        switch (press) {
            case 1:
            {
                int a[4][4] = {{1,3,5,9},{8,1,3,4},{5,0,6,1},{8,8,4,0}};
                cout<<"矩阵权值路径最小和为："<<msearchmin(a,4,4)<<endl;
                break;
            }
                
            case 2:
            {
                cout<<"组合数C(n,k)[亦即杨辉三角、帕斯卡三角形]的矩阵(以4阶为例)为："<<endl;
                Cnk();
                break;
            }
            case 3:
            {
                cout<<"请输入要计算的斐波那契数列：";
                cin>>n;
                cout<<"斐波那契数列对应的数字为：\n 递归："<<Fib_2(n)<<"\n动态规划："<<Fib(n)<<endl;
                cout<<"利用动态规划解决该问题的数组所存储的数值为：";
                for(int i=0;i<=n;i++)
                    cout<<temp[i]<<"~";
                cout<<endl;
                break;
            }
            case 4:
            {
                cout<<"请输入三角塔问题的层数：";
                cin>>n;
                cout<<"请输入三角塔各个节点的数值(e.g. 13 11 8 12 7 26 6 14 15 8(4层))：";
                for(int i=1;i<=n;i++)
                    for(int j=1;j<=i;j++)
                        cin>>a1[i][j];

                cout<<"路径最大和为：\n递归："<<Ttower_2(1,1)<<"\n动态规划："<<Ttower(1,1)<<endl;
                cout<<"利用动态规划解决该问题的矩阵所存储的数值为"<<endl;
                for(int k1=1;k1<=n;k1++)
                {
                    for(int k2=1;k2<=n;k2++)
                    {cout<<data[k1][k2]<<"  ";}
                     cout<<endl;
                }
                break;
            }
            case 5:
            {
                string a,b;
                cin>>a>>b;
                cout<<a<<"和"<<b<<"的最长公共子序列数为："<<LCS(a,b)<<"个"<<endl;
                break;
            }
            case 6:
            {
                int a[]={5,1,6,7,8};
                int asize = sizeof(a)/sizeof(int);
                cout<<"最长递增子序列有："<<LIS(a,asize)<<"个";
                break;
            }
                
            default:
                cout<<"error";
                break;
        }
        
        cout<<endl<<endl;
        cout<<"您还可以继续输入对应数字查看!请输入下列问题对应的数字查看相应问题求解："<<endl<<"1.求矩阵权值路径最小和问题\n2.组合数C(n,k)\n3.斐波那契数列问题\n4.三角塔问题\n5.最长公共子序列问题\n6.最长递增子序列\n";
    }
    
    return 0;
}

int Fib(int n)//动态规划，注意与递归相比较
{
    if(n<=1)
        return n;
    else
    {
        if(temp[n]!=0)
            return temp[n];
        return temp[n] = Fib(n-1)+Fib(n-2);
    }
}
int Fib_2(int n)//递归
{
    if(n<=1)
        return n;
    else
        return Fib(n-1)+Fib(n-2);
}


int Ttower(int i,int j)//动态规划，注意与递归相比较
{
    if(i==n)
        return data[i][j] = a1[i][j];
    else
        return data[i][j] = max( Ttower(i+1,j),Ttower(i+1,j+1) )+a1[i][j];
}

int Ttower_2(int i,int j)//递归
{
    if(i==n)
        return a1[i][j];
    else
        return  max( Ttower(i+1,j),Ttower(i+1,j+1) )+a1[i][j];
}



