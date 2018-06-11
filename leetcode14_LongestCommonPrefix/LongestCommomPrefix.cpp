//
//  main.cpp
//  leetcode14_LongestCommonPrefix
//编写一个函数来查找字符串数组中最长的公共前缀字符串。
//  Created by kai on 2018/3/13.
//  Copyright © 2018年 kai. All rights reserved.
//

#include <iostream>
#include<string>
using namespace std;
string FindP(string s[],int n);

int main() {
    string str[] = {"sdses","sdsd","sdssss","sde"};
    int length=4;

    cout<<"字符串数组的公共字符前缀为："<<FindP(str,length)<<endl;
    return 0;
}


string FindP(string s[],int n)
{
    int min=0;
    //首先寻找最短字符串（这里寻找的是最短字符串对应的位置是为了方便后面程序书写）
    for(int i =1;i<n;i++)
    {
        if(s[i].length()<s[min].length())
            min = i;
    }
    int minlength=s[min].length();//字符串数组中最短的字符串对应的字符长度
    string  smax="";//smax用来记录公共字符，初始值为空字符
    //将最短字符串从第一个字符开始，依次与字符串数组的所有字符串（从第一个开始）进行比较，相等则说明所有字符串都含有该字符（即为公共前缀）
    for(int j=0;j<minlength;j++)
    {
        int k;
        for(k=0;k<n;k++)
        {
            if(s[k][j]!=s[min][j])
                break;
        }
        if(k==n)//每个字符串的第k个字符都与最短字符s[min]的第k个字符相等时，意味着该字符是公共前缀
            smax +=s[min][j];//将第k个字符添加到smax当中
    }
    return smax;
}
