#include<queue>
#include<stdio.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> > Q;
//С���ѣ�ע�⣺���> >���м�Ҫ�ӿո�
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int i;
		while(Q.empty()==false) Q.pop();
		for(i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			Q.push(x);
		}
		int ans = 0; //���Ľ��
		while(Q.size()>1)
		{
			int a = Q.top();
			Q.pop();
			int b = Q.top();
			Q.pop();
			ans += a+b; // += ���ֿܷ�
			Q.push(a+b);
			//����Q.push(ans)
		}
		printf("%d\n",ans);
	}
	return 0;
}