#include<stdio.h>
#define ISYEAP(x) ((x%4==0&&x%100!=0)||(x%400==0))?1:0

//���˳��Ӧ���ȱ�дday�����ԣ�
//Ȼ���дmonth��year�ȵȣ�Ҫһ������

int dayOfMonth[13][2] = 
{//����������
	0,0,
	31,31,
	28,29,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31
}; //���";"һ��Ҫ����
struct Date
{
	int year;
	int month;
	int day;
	void nextDay()
	{
		day++;
		if(day>dayOfMonth[month][ISYEAP(year)])
		{
			day = 1;
			month++;
			if(month>12)
			{				
				month = 1;
				year++;
			}
		}
	}
};
int buf[5001][13][32];
int Abs(int x)
{
	return x<0?-x:x;
}
int main()
{
	Date tmp;
	int cnt = 0; //ֻ�����������ģ�Ȼ�����buf��
	tmp.year = 0;  //��0��1��1����Ϊ��׼
	tmp.month = 1;	
	tmp.day = 1;
	while(tmp.year!=5001)
	{
		buf[tmp.year][tmp.month][tmp.day] = cnt;
		tmp.nextDay();
		cnt++;

	}
	int y1,m1,d1;
	int y2,m2,d2;
	while(scanf("%4d%2d%2d",&y1,&m1,&d1)!=EOF)
	{
		scanf("%4d%2d%2d",&y2,&m2,&d2);
		printf("%d\n",Abs(buf[y2][m2][d2]-buf[y1][m1][d1])+1);
	}
	return 0;
}