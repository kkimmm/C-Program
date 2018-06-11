//
//  sort_ByVector.cpp
//  SortAlgorithm
//   排序算法的vector实现
//  Created by kai on 2018/3/17.
//  Copyright © 2018年 kai. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

void printl(vector<int> vec)
{
    for(int i=0;i<vec.size();i++)
        cout<<vec[i];
    cout<<endl;
}

vector<int> sort_1(vector<int> &vec)
{
    for(int i=0;i<vec.size();i++)
    {
        for(int j=vec.size()-1;j>=i;j--)
        {
            if(vec[j]<vec[j-1])
            {
                int temp = vec[j];
                vec[j] = vec[j-1];
                vec[j-1] = temp;
            }
        }
    }
    return vec;
}

vector<int> sort_2(vector<int> &vec)
{
    int temp;
    for(int i=0;i<vec.size();i++)
    {
        int min = i;
        for(int j=i+1;j<vec.size();j++)
        {
            if(vec[j]<vec[min])
            {
                min = j;
            }
        }
        temp = vec[i];
        vec[i] = vec[min];
        vec[min] = temp;
    }
    
    return vec;
}

vector<int> sort_3(vector<int> &vec)
{
    for(int i=0;i<vec.size();i++)
    {
        int get = vec[i];
        int j = i-1;
        while(get<vec[j]&&j>=0)
        {
            vec[j+1]=vec[j];
            j--;
        }
        vec[j+1] = get;
    }
    return vec;
}





