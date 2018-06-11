//
//  main.cpp
//  lintcode
//
//  Created by kai on 2018/3/10.
//  Copyright © 2018年 kai. All rights reserved.
//

#include <iostream>
using namespace std;
int reverse_1(int num);
string reverse_2(string a,int n);

int main() {
    int input = 10000003;
    cout<<reverse_1(input)<<endl;
    
    string str ="abcdef";
    int length = str.length();
    cout<<reverse_2(str,length)<<endl;
    
    return 0;
}

int reverse_1(int num)//反转数字
{
   /*
    for(int i=3;i>0;i--)
    {
        cout<<num%10;
         num = num/10;
    }
    */
    int temp =0;
    while(num!=0)//这种方法优于上面注释掉的那个算法，不用再计算数据长度
    {
        if (temp>(INT_MAX-num%10)/10)//判断是否溢出,关键点之一
        {
            return 0;
        }
        else
        {
            temp = temp*10+num%10;//对比上面注释的算法可以发现这种统一到一起再输出的方法更好
            num/=10;
        }
    }
    
    return temp;
}


string reverse_2(string a,int length)//反转字符串
{
    char temp;
    for(int i=0;i<length/2;i++)
    {
        temp = a[i];
        a[i]=a[length-1-i];
        a[length-1-i]=temp;
    }
    return a;
}



