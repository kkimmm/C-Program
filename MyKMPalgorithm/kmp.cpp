#include<iostream>
using namespace std;

void GetNext(char *target,int *&next)//int*&p是一个指针的引用，因为我们这里的next是会变化的，因此使用这种方法；
                                     //若我们使用*next，那么就不能改变next的值
{
	int t_len = strlen(target);
	next = new int[t_len + 1];//new int[] 是创建一个int型数组，数组大小是在[]中指定
	next[0] = -1;
	int k = -1;
	for (int i = 0; i < t_len;)
	{
		if (k == -1|| target[i] == target[k])
		{
			i++;
			k++;
			next[i] = k;
		}
		else
		{
			k = next[k];
		}

			
	}
}

int Find_KMP(char* source, char* target, int* next){

	int j = 0;
	int t_len = strlen(target);
	int s_len = strlen(source);


	for (int i = 0; i<s_len;){


		if (source[i] == target[j]){
			i++;//同时右移，进行下一次比较 
			j++;//记录相同的长度,若长度与target相同，则表示已完全匹配 
		}
		else{//回溯 
			j = next[j];
		}

		if (j == -1){//表示source[i]与target[0]不相同，右移i，进行下次比较 
			i++;
			j = 0;
		}

		
		if (j == t_len){
			return i -j + 1;
		}
	}

	return 0;
}
int main()
{
	char *S = "abcabdabeabf";
	char *T = "abe";
	int *next;
	GetNext(T,next);
	cout <<"find! the position is:"<< Find_KMP(S, T, next) << endl;

	return 0;
}