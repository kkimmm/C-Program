//
//  main.cpp
//  RecursionAlgorithm
//  常见的递归算法应用实例
//  Created by kai on 2018/3/12.
//  Copyright © 2018年 kai. All rights reserved.
//

#include <iostream>
using namespace std;
int Factorial(int n);
int Fib(int n);
int Hanoi(int n);
void Hanoi_2(char a,char b,char c,int n);
void move(char input,char output);
int Combine(int n,int k);

int main() {
    int number = 4;
    cout<<number<<"的阶乘为："<<Factorial(number)<<endl;
    cout<<number<<"对应的斐波那契数为："<<Fib(number)<<endl;
    cout<<number<<"的汉诺塔移动步数为："<<Hanoi(number)<<endl;
    cout<<number<<"的汉诺塔移动方式为："<<endl;
    Hanoi_2('A','B','C',number);
    int number_2=1;
    cout<<"从"<<number<<"个人中选择"<<number_2<<"个人的方式有："<<Combine(number, number_2)<<"种"<<endl;
    return 0;
}

int Factorial(int n)//阶乘
{
    if(n==1)
        return 1;
    else
        return Factorial(n-1)*n;
}

int Fib(int n)//斐波那契数列1，1，2，3，5，8...
{
    if(n==1)
        return 1;
    else if(n==2)
        return 1;
    else
    {
        return Fib(n-1)+Fib(n-2);
    }
}

int Hanoi(int n)//（三柱）汉诺塔移动次数
{
    if(n==1)
        return 1;
    else
        return 2*Hanoi(n-1)+1;
}

void Hanoi_2(char a,char b,char c,int n)//三柱汉诺塔每步的移动方式
{
    if(n==1)
        move(a,c);
    else
    {
        Hanoi_2(a,c,b,n-1);
        move(a,c);
        Hanoi_2(b, a, c,n-1);
    }
}
void move(char input,char output)
{
    cout<<input<<"->"<<output<<endl;
}


int Combine(int n,int k)//组合Cnk，从n个人中选择k个人组成一个组
{
    if(k>n)
        return -1;
    else if(k==n||k==0)
            return 1;
    else
        {
            return Combine(n-1, k)+Combine(n-1, k-1);
        }
    
}






