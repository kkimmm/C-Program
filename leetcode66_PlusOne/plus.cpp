//
//  main.cpp
//  leetcode66_PlusOne
//给定一非负整数，将其当做一个包含数字的数组来看待，求对其"加1"后所得到的数组。例如数字999对应于数组[9,9,9]，那么“加1”后得到的数组为[1,0,0,0]。
//  Created by kai on 2018/3/13.
//  Copyright © 2018年 kai. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;
vector<int> PlusOne(vector<int> &a);

int main()
{
    vector <int> vec={9,9,9,8};
    PlusOne(vec);
    
    vector <int>::iterator it;
    for(it=vec.begin();it!=vec.end();it++)
        cout<<*it;
    cout<<endl;
    
    return 0;
}

vector<int> PlusOne(vector<int> &a)
{
    int c = 1;// c既是标志位，又是要相加的数字
    for(int i=a.size()-1;i>=0;i--)
    {
        int k =a[i]+c;
        a[i] = k%10;
        c = k/10;
    }
    if(c==1)
        a.insert(a.begin(),1);
    return a;
}


