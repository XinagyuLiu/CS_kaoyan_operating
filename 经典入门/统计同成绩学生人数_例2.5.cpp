#include<stdio.h>
int main()
{ //��hash�������������
	int n;
	int x;
	while(scanf("%d",&n)!=EOF && n!=0)
	{
		int Hash[101]={0};
		//���һ��Ҫ����whileѭ����,ÿ�ζ����³�ʼ��
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			Hash[x]++;
		}	
		int find;
		scanf("%d",&find);
		printf("%d\n",Hash[find]);
	}
	return 0;
}