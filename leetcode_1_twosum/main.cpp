//
//  main.cpp
//  leetcode_1_twosum
//
//  Created by kai on 2018/3/10.
//  Copyright © 2018年 kai. All rights reserved.
//

#include <iostream>
#include<map>
#include<vector>
using namespace std;
void Findnumber_1(int array[],int test,int size);
int twoSum(int numbers[], int target,int size);
int main() {
    int array[] = {2,7,11,5,4};
    int target = 9;
    int size =sizeof(array)/sizeof(int)-1;//计算数组长度
    Findnumber_1(array,target,size);
    
    
 /*   map<int, int> mp;
    for (int i = 0; i < 10; i ++){
        mp[i] = i;
    }

    map<int, int>::iterator it;
    for (it = mp.begin(); it != mp.end(); it++){
        printf("%d-->%d\n", it->first, it->second);
    }*/
    
    
    twoSum(array, target,size);
    return 0;
}

void Findnumber_1(int array[],int test,int size) //时间复杂度o(n^2)
{
    for(int i=0;i<=size;i++)
    {
        for(int j = i;j<=size;j++)
        {
            if (array[i]+array[j]==test)
                cout<<i+1<<" and "<<j+1<<" in the array make up the number of 9"<<endl;
        }
    }
}

int twoSum(int numbers[], int target,int size){
   //将数组填入hashMap
    map<int, int> hashMap;
    for (int i = 0; i <= size; i++){
            hashMap[numbers[i]] = i;
    }
    map<int, int>::iterator it;
    for (it = hashMap.begin(); it != hashMap.end(); it++){
        printf("%d-->%d\n", it->first, it->second);}
    //查找两数
    
    
    vector<int> result;
    for (int i = 0; i <= size; i++)
    {
        int otherNum = target - numbers[i];
        map<int, int>::iterator iter = hashMap.find(otherNum);
        
        if (iter != hashMap.end() && iter->second != i + 1)//存在另一个数，且不为自身
        {
            result.push_back(i + 1);
            result.push_back(iter->second);
            break;
        }
    }
    cout<<result[0]<<endl<<result[1]<<endl<<result[2]<<endl;
    
    
    
return 0;
}



