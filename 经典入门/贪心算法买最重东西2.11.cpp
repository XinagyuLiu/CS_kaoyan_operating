#include<stdio.h>
#include<algorithm>
using namespace std;
struct Goods
{
	double j; //һ����Ʒ�ж���
	double f; //һ��Ҫ����Ǯ
	double s;
	bool operator < (const Goods &gd )const 
	{
		return s > gd.s;
	}
}buf[1000];
int main()
{
	double m; //Ǯ
	int n; //�ж�����
	while(scanf("%lf %d",&m,&n)!=EOF)
	{ 
		if(m==-1&&n==-1)
			break; 
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&buf[i].j,&buf[i].f);
			buf[i].s = buf[i].j/buf[i].f;
		}
		sort(buf,buf+n);
		int idx = 0;
		double ans = 0;
		while(m>0&&idx<n)
		{
			if(m>=buf[idx].f)
			{
				ans += buf[idx].j;
				m -= buf[idx].f;
			}
			else 
			{
				ans += buf[idx].j * m/buf[idx].f;
				m = 0;
			}
			idx++;
		}
		printf("%.3lf\n",ans);
	}
	return 0;
}