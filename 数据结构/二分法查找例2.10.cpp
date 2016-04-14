#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct Student
{
	char no[100];
	char name[100];	
	char sex[5];
	int age;
	bool operator < (const Student &st)const 
	{
		return strcmp(no,st.no)<0;
	}
}buf[1000];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int i,j,k;
		for(i=0;i<n;i++)
		{
			scanf("%s %s %s %d",buf[i].no,buf[i].name,buf[i].sex,&buf[i].age);
		}
		sort(buf,buf+n);
		//����Ϊ���������
		
		int t;//Ҫ��ѯ�ĸ���
		scanf("%d",&t);
		while(t--!=0)
		{
			//���ַ��ҵ�Ҫ�ҵ�����
			int ans = -1; //��ʼ��
			char x[100];
			scanf("%s",x);
			int base = 0,top = n-1,mid;
			while(base<=top)
		{
			mid = (base+top)/2;
			int tmp=strcmp(buf[mid].no,x);
			if(tmp==0)
			{
				ans = mid;
				//�������Ҫ����break֮ǰ
				break;
			}
			else if(tmp<0)
				base = mid+1;
			else
				top = mid-1;
		}
			if(ans==-1)
				printf("No Answer!\n");
			else
				printf("%s %s %s %d\n",buf[ans].no,buf[ans].name,buf[ans].sex,buf[ans].age);	
		}		
	}
	return 0;
}