#include <iostream>
using namespace std;

void FindBF(char *s,char *t)
{
	int i=0, j = 0;
	int s_len = strlen(s);
	int t_len = strlen(t);
	for (i = 0; i <= s_len; i++)
	{
		if (s[i] == t[j])
			j++;
		else if (j != 0)
		{
			i = i - j;
			j = 0;
		}
		if (j == t_len)
		{
			cout << "Find! in the position of  " << (i - j + 1) + 1 << "  those two string begin to the same";
		}	
		
	}
}

int main()
{
	char *S = "abcabdabe";
	char *T = "abd";
	FindBF(S, T);
	return 0;
}