#include<stdio.h>
// �������ϸ�ڡ�
//�������Ű棬�����
int main()
{
	char outPutBuf[82][82];
	char a,b; //��������ַ�
	int n; //�����С������
	bool firstcase = true;
	while(scanf("%d %c %c",&n,&a,&b)!=EOF)
	{
		    if(firstcase)
				firstcase = false;
			else
				printf("\n");
		int i,j,k; //����ѭ��
		for(i=1,j=1;i<=n;i+=2,j++)
		{  //�����������ÿ��Ȧ
			int x = n/2+1;
			int y = x;
			x-=(j-1);
			y-=(j-1);  //�������Ͻǵ�����
			char c=j%2==1?a:b; //jΪ�棬����a
			for(k=1;k<=i;k++)
			{
				outPutBuf[x+k-1][y] = c; //���
				outPutBuf[x][y+k-1] = c; //�ϱ�
				outPutBuf[x+i-1][y+k-1] = c; //�±�
				outPutBuf[x+k-1][y+i-1] = c; //�ұ�
			}
		}
		//����ֻ��һ��Ԫ�ص����
		if(n!=1)
		{
			outPutBuf[1][1] = ' ';
			outPutBuf[1][n] = ' ';
			outPutBuf[n][1] = ' ';
			outPutBuf[n][n] = ' ';
		}
		for(i=1;i<=n;i++)
		{					
			for(j=1;j<=n;j++)
				printf("%c",outPutBuf[i][j]);
			printf("\n");
		}
	}
	return 0;
}