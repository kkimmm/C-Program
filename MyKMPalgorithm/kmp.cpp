#include<iostream>
using namespace std;

void GetNext(char *target,int *&next)//int*&p��һ��ָ������ã���Ϊ���������next�ǻ�仯�ģ����ʹ�����ַ�����
                                     //������ʹ��*next����ô�Ͳ��ܸı�next��ֵ
{
	int t_len = strlen(target);
	next = new int[t_len + 1];//new int[] �Ǵ���һ��int�����飬�����С����[]��ָ��
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
			i++;//ͬʱ���ƣ�������һ�αȽ� 
			j++;//��¼��ͬ�ĳ���,��������target��ͬ�����ʾ����ȫƥ�� 
		}
		else{//���� 
			j = next[j];
		}

		if (j == -1){//��ʾsource[i]��target[0]����ͬ������i�������´αȽ� 
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