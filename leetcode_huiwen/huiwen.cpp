//
//  main.cpp
//  leetcode_huiwen
//
//  Created by kai on 2018/3/10.
//  Copyright © 2018年 kai. All rights reserved.
//

#include <iostream>
using namespace std;
int reverse(int num);
int main() {
    int input = 10000001;
    int s;
    s = reverse(input);
    if (s==0)//两种可能发生错误的情况，详细reverse函数的注释
        cout<<"error"<<endl;
    else if(input == s)
        cout<<"是回文序列"<<endl;
    else
        cout<<"不是回文序列！"<<endl;
    return 0;
}

int reverse(int num)
{
    int temp =0;
    if(num<0)
        return 0;//小于0的数字没有回文序列并报错
    else
    {
        while(num)
        {
            if(temp>(INT_MAX-num%10)/10)
                return 0;//数字反转以后如果发生溢出则报错
            else
            {temp = temp*10+num%10;
                num /=10;}
        }
        return temp;

    }
    
}
