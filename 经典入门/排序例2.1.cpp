#include<stdio.h>
int main()
{
	int n;
	int buf[100];
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
			scanf("%d",&buf[i]);		
		//ð�ݷ�����
		for(int j=0;j<n;j++)
			for(int k=0;k<n-j-1;k++)
				if(buf[k]>buf[k+1])
				{//����ں�
					int tmp = buf[k];
					buf[k] = buf[k+1];
					buf[k+1] = tmp;
				}
		for(i=0;i<n;i++)
			printf("%d ",buf[i]);
		printf("\n");
	}

	/*��
	char a[4] ="abc";
	char *p;
	p = &a[0];
    printf("%c\n%s\n",*p,p);
	//*pΪpָ��ĵ�һ���ַ���
	//��pָ���ַ�������%sһ��ʹ��*/

	return 0;	
}