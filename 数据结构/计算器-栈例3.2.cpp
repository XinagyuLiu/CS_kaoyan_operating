#include<stdio.h>
#include<stack>
using namespace std;
char str[220];
int mat[][5]=
{   //+,-,*,/
	1,0,0,0,0, //Ҫ��5�У���Ȼ'/'�ò���
	1,0,0,0,0,
	1,0,0,0,0,
    1,1,1,0,0,
	1,1,1,0,0
};
//mat[A][B] ��A�����ȼ���B�ıȽϣ�1��ʾ�ϸ�
stack<int> op; //�����ջ
stack<double> in; //����ջ
void getOp(bool &reto,int &retn,int &i)
{ //retoΪfalse�����ʾ���֣�����retn��
  //retoΪtrue�����ʾ�����������retn�С�
  //i��ʾ���������ַ����±�
	if(i==0&&op.empty()==true)
	{ //��һ���ַ����������ջΪ�գ���0���
		reto = true;
		retn = 0;
		return; //�˴�Ϊ����������
	}
	if(str[i]=='\0')
	{ //�������һ������0���
		reto = true;
		retn = 0;
		return;
	}
	if(str[i]>='0'&&str[i]<='9')
	{ //�������֣���ת��Ϊint��
		reto = false;
		retn = 0;
		for(;str[i]!=' '&&str[i]!='\0';i++)
		{
			retn*=10;
			retn+=(str[i]-'0');
		}
		if(str[i]==' ')
			i = i+1;
		return;
	}
	else
	{ //���������
		reto = true;
		if(str[i]=='+')
			retn = 1;
		else if(str[i]=='-')
			retn = 2;
		else if(str[i]=='*')
			retn = 3;
		else if(str[i]=='/')
			retn = 4;
		i+=2;
		return;
	}
}
int main()
{
	while(gets(str))
	{
		if(str[0]=='0'&&str[1]=='\0')
			break;
		bool retop; 
		int retnum;
		int idx = 0;
		while(!op.empty())
			op.pop();
		while(!in.empty())
			in.pop();
	while(true)
	{  //һֱ�ڴ�ѭ��
		getOp(retop,retnum,idx);
		if(retop==false)
			in.push((double)retnum);
		else
		{ //Ϊ�����
			if(op.empty()||mat[retnum][op.top()]==1)
				op.push(retnum); //ջ�ջ����ȼ�����
				//�� 1 + 2 * 3
			else
			{ //����ʼ����
				double tmp;
				while(mat[retnum][op.top()]==0)
				{
					int ret = op.top();
					op.pop(); //��Ϊpop()������void�͵ģ�����ֻ������
					double b = in.top();
					in.pop();
					double a = in.top(); //ջ�������˳���෴������Ҫ������
					in.pop();
					if(ret == 1)
						tmp = a + b;
					else if(ret == 2)
						tmp = a - b;
					else if(ret == 3)
						tmp = a * b;
					else if(ret == 4)
						tmp = a / b;
					in.push(tmp);					
				}
				op.push(retnum); 
				//��������һ������һ���������Ҫ����ѹ��ջ��
				//�� 2 * 3 + 1 ���ڵõ�'+'��Ҫ��ǰ���2*3���������Ȼ���'+'��ջ
			}
		}
		if(op.size()==2&&op.top()== 0 )  //���0һ������д��'0'
			break; //��������ջֻʣ��������ˣ��ͱ�ʾ�����
	}//while(true)
	printf("%.2f\n",in.top());
	}//while(gets(str))
	return 0;
}