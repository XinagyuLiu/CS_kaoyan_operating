#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	int buf[100];
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
			scanf("%d",&buf[i]);
		sort(buf,buf+n);
		for(i=0;i<n;i++)
			printf("%d ",buf[i]);
		printf("\n");
	}

	/*	int n;
	char buf[100]={0};
	while(gets(buf))
	{
		n = strlen(buf);
		sort(buf,buf+n);
		puts(buf);		
	}*/
	return 0;
}