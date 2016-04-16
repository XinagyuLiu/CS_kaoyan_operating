#include<stdio.h>
#define N 1000
int Tree[N];
int findRoot(int x)
{
	if(Tree[x]==-1)
		return x;
	else
	{
		int tmp = findRoot(Tree[x]);
		Tree[x] = tmp;
		return tmp;
	}
}
int main()
{
	int n,m; //nΪ��������mΪ��·��
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		scanf("%d",&m);
		int i;
		for(i=1;i<=n;i++) //ע���Ǵ�1--n
			Tree[i] = -1;
		//��ʼ�����ǹ����ĵ�
		int a,b;
		while(m--!=0)
		{
			scanf("%d%d",&a,&b);
			a = findRoot(a);
			b = findRoot(b);
			if(a!=b)
				Tree[a] = b;		
		}
		int ans = 0;
		//Ҫ����while���棬ÿ����������
		for(i=1;i<=n;i++)		
			if(Tree[i]==-1)
				ans++;
		printf("%d\n",ans-1);
		//���ansҪ��һ
	}
	return 0;
}