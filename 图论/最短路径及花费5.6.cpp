#include<stdio.h>
#include<vector>
using namespace std;
struct E
{
	int next;
	int c;  //·������
	int cost; //���� 
};
vector<E> edge[1001];
int Dis[1001];
int cost[1001];
bool mark[1001];
int main()
{
	int n,m;
	int S,T;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0 && m==0) 
			break;
		int i,j;
		for(i=1;i<=n;i++)
			edge[i].clear();
		//��ʼ��
		while(m--!=0)
		{
			int a,b,c,cost;
			//a ,b Ϊ���� 
			scanf("%d%d%d%d",&a,&b,&c,&cost);
			E tmp;
			tmp.c = c;
			tmp.cost = cost;
			tmp.next = b;
			edge[a].push_back(tmp);
			tmp.next = a;
			edge[b].push_back(tmp);
			//��Ϊ������ͼ
		}
		scanf("%d%d",&S,&T);
		for(i=1;i<=n;i++)
		{
			Dis[i] = -1;
			mark[i] = false;
			//��ʼ��
		}
		Dis[S] = 0;
		mark[S] = true;
		int newP = S;
		for(i=1;i<n;i++) //����ѭ��������ʣ���n-1��
			for(j=0;j<edge[newP].size();j++) 
			//jҪ��0��ʼ����Ϊedge[newP][]�Ǵ��±�0��ʼ��
			{  //Ҫ�ҵ�һЩ��ѡ�ĵ�
				int t = edge[newP][j].next; // tΪ��һ�����
				int c = edge[newP][j].c; //·��
				int co = edge[newP][j].cost;
				if(mark[t] == true)
					continue;
				if(Dis[t]==-1 || Dis[t]>Dis[newP]+c || (Dis[t]==Dis[newP]+c && cost[t]>cost[newP]+co))
				{ //����
					Dis[t] = Dis[newP]+c;
					cost[t] = cost[newP]+co;
				}
				int min = 123123123;
				//���ڿ�ʼ�ں�ѡ������С��Ȼ����뵽K������
				for(j=1;j<=n;j++)
				{
					if(mark[j] == true) 
						continue;
					if(Dis[j] == -1)
						continue;
					if(Dis[j] < min)
					{
						min = Dis[j];
						newP = j; //���ֻ����ʱ�ģ�Ҫ��forѭ������Ŷ�������С��
					}
				}
				mark[newP] = true; //���
			}//��for������ѭ��
		printf("%d %d\n",Dis[T],cost[T]);
	}
	return 0;
}