#include<stdio.h>
#include<stack>
using namespace std;
stack<int> S;
char str[100]; //�����ַ���
char ans[110]; //����ַ���
int main()
{
	while(scanf("%s",str)!=EOF)
	{	
		int i;
		for(i=0;str[i]!='\0';i++)
		{
			if(str[i]== '(' )
			{
				ans[i] = ' ';
				S.push(i);
			}
			else if(str[i]== ')' )
			{
				if(S.empty())
					ans[i] = '?';
				else 
				{ //ƥ��
					S.pop();
					ans[i] = ' ';
				}
			}
			else 
				ans[i] = ' '; //�����޹صĶ���
		}
		while(!S.empty()) //Ӧ�õ�for������ж�
		{ //ջ�л���δƥ��� '('
			ans[S.top()] = '$';
			//���Ҫע��,S���涼��������װ���ŵ��±�
			S.pop();
		}
		ans[i] = '\0';
		puts(str);
		puts(ans);
	}
	return 0;
}