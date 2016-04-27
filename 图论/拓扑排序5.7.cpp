#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<int> edge[501]; 
//�ڽӱ�ֻ�����ڽӵı�ţ��൱��edge[i].next
queue<int> Q;
int main()
{
	int inDegree[501]; //ÿ���������
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0 && m==0) 
			break;
		int i;
		for(i=0;i<n;i++) //������ý����Ϊ0--n-1
		{
			inDegree[i] = 0;
			edge[i].clear();
		}
		while(m--!=0)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			//����ͼ����aָ��b
			inDegree[b]++;
			edge[a].push_back(b); //��b��ӵ�a���ڽ�������
		}
		while(Q.empty()!=true)
			Q.pop(); //�����һ������
		for(i=0;i<n;i++)
			if(inDegree[i] == 0)
				Q.push(i); //�����Ϊ0�Ľ���ݴ����;��ջҲ����
		int cnt = 0; //����ȷ�����������еĸ���
		while(Q.empty()!=true)
		{ //Ҫ�����Ϊ0�Ľ�㶼ȡ����
			int nowP = Q.front();
			Q.pop();
			cnt++;
			for(i=0;i<edge[nowP].size();i++) //ȥ���ý�㣬�������
			{
				inDegree[edge[nowP][i]]--;
				if(inDegree[edge[nowP][i]] == 0)
					Q.push(edge[nowP][i]);
			}
		}
		if(cnt == n)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}