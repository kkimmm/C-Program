//
//  main.cpp
//  SortAlgorithm
//  常用排序算法
//  Created by kai on 2018/3/11.
//  Copyright © 2018年 kai. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void printl(int a[],int n);
void sort_1(int a[],int n);
void sort_2(int a[],int n);
void sort_3(int a[],int n);
void swap(int a[],int i,int j);
void merge(int a[],int left,int mid,int right);
void sort_5(int a[],int left,int right);
int partation(int a[],int left,int rigth);
void sort_4(int a[],int left,int rigth);

void Merge(int A[], int left, int mid, int right);
void MergeSortRecursion(int A[], int left, int right);

void printl(vector<int> vec);
vector<int> sort_1(vector<int> &vec);
vector<int> sort_2(vector<int> &vec);
vector<int> sort_3(vector<int> &vec);

int main()
{
    int a[]={5,2,9,4,7,6,1,3,8};
    int a_size =sizeof(a)/sizeof(int);
    
    /*sort_1(a,a_size);
    cout<<"冒泡排序结果：";
    printl(a,a_size);
    */sort_2(a,a_size);
    cout<<"选择排序结果：";
    printl(a,a_size);
    sort_3(a,a_size);
    /*cout<<"插入排序结果：";
    printl(a,a_size);
    
    sort_4(a,0,a_size-1);
    cout<<"快速排序结果：";
    printl(a,a_size);

    MergeSortRecursion(a,0,a_size-1);
    cout<<"归并排序结果：";
    printl(a,a_size);*/
    
    /*
    //以下是使用向量vector的排序用以熟悉vector的使用
    vector<int> vec1 = {1,8,2,3,0,4};
    //sort_1(vec1);
    sort_2(vec1);
    printl(vec1);
    */
    return 0;
}

void printl(int a[],int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i];
    cout<<endl;
}

void sort_1(int a[],int n)//冒泡排序
{
    int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>=i;j--)
        {
            if(a[j]<a[j-1])
            {
                temp = a[j-1];
                a[j-1]=a[j];
                a[j] = temp;
            }
        }
    }
}

void sort_2(int a[],int n)//选择排序
{
    int temp;
    for(int i=0;i<n;i++)
    {
        int min = i;
        for(int j=i+1;j<n;j++)
        {
            /*if(a[j]<a[min])//这种方式会增加时间
            {
                temp = a[min];
                a[min] = a[j];
                a[j]=temp;
            }*/
            if(a[j]<a[min])
            {min = j;}
        }
        if(min!=i)
        {
            temp = a[min];
            a[min] = a[i];
            a[i]=temp;
        }
    }
}

void sort_3(int a[],int n)//插入排序
{
    for(int i=1;i<n;i++)
    {
        int get = a[i];//抓牌顺序（右边）
        /*int j=i-1;
        while(j>=0&&a[j]>get)//抓到的牌比左边（已经排好序）小
        {
            a[j+1]=a[j];//将左边（已经排好序）的牌顺序向右移动直到出现比抓到的牌更小的
            j--;
        }
        a[j+1]=get;//由于上面循环的时候多减去了1，故这里要j+1*/
        
        int j=i-1;//这种写法更简洁
        for(;j>=0&&a[j]>get;j--)
        {
            a[j+1]=a[j];
        }
        a[j+1]=get;
        
    }
}

void sort_4(int a[],int left,int rigth)//快速排序
{
    if(left>=rigth)
        return;
    int p_index = partation(a,left,rigth);
    sort_4(a,left,p_index-1);
    sort_4(a,p_index+1,rigth);
}

int partation(int a[],int left,int rigth)
{
    int posindex =rigth;
    int tail = left-1;
    for(int i=left;i<rigth;i++)
    {
        if(a[i]<=posindex)
            swap(a,++tail,i);
    }
    swap(a,tail+1,posindex);
    return posindex;
}

void swap(int a[],int i,int j)
{
    int temp = a[j];
    a[j] = a[i];
    a[i] = temp;
}

/*void sort_5(int a[],int left,int right)//归并排序
{
    if(left==right)
        return;
    int mid = (left+right)/2;
    sort_5(a,left,mid);
    sort_5(a,mid+1,right);
    merge(a,left,mid,right);
}

void merge(int a[],int left,int mid,int right)
{
    int len = right-left+1;
    int *temp = new int[len];
    int k=0;
    int i=left,j=mid+1;
    while(i<=mid&&j<=right)
    {
        temp[k++] =a[i]<=a[j]? a[i++]: a[j++];
    }
    while(i<=mid)
        temp[k++] = a[i++];
    while(j<=right)
        temp[k++] = a[j++];
    for(int l=0;l<len;l++)
        a[left++] = temp[k];
}
*/
void MergeSortRecursion(int A[], int left, int right)    // 递归实现的归并排序(自顶向下)
{
    if (left == right)    // 当待排序的序列长度为1时，递归开始回溯，进行merge操作
        return;
    int mid = (left + right) / 2;
    MergeSortRecursion(A, left, mid);
    MergeSortRecursion(A, mid + 1, right);
    Merge(A, left, mid, right);
}

void Merge(int A[], int left, int mid, int right)// 合并两个已排好序的数组A[left...mid]和A[mid+1...right]
{
    int len = right - left + 1;
    int *temp = new int[len];       // 辅助空间O(n)
    int index = 0;
    int i = left;                   // 前一数组的起始元素
    int j = mid + 1;                // 后一数组的起始元素
    while (i <= mid && j <= right)
    {
        temp[index++] = A[i] <= A[j] ? A[i++] : A[j++];  // 带等号保证归并排序的稳定性
    }
    while (i <= mid)
    {
        temp[index++] = A[i++];
    }
    while (j <= right)
    {
        temp[index++] = A[j++];
    }
    for (int k = 0; k < len; k++)
    {
        A[left++] = temp[k];
    }
}

