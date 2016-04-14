#include<stdio.h>
#include<string.h>
struct Node
{
	Node *lchild;
	Node *rchild;
	int c;
}Tree[110];
char str1[25],str2[25];
int loc;
int *size; char *str;
int size1,size2;
Node *create()
{
	Tree[loc].lchild = Tree[loc].rchild = NULL;
	return &Tree[loc++];
}
void postOrder(Node *T)
{ //�������
	if(T->lchild!=NULL)
		postOrder(T->lchild);
	if(T->rchild!=NULL)
		postOrder(T->rchild);
	str[(*size)++] = T->c + '0'; 
	//�����ֱ�Ϊ�ַ�������
}
void inOrder(Node *T)
{ //�������
	if(T->lchild!=NULL)
		inOrder(T->lchild);
	
	str[(*size)++] = T->c + '0'; 

	if(T->rchild!=NULL)
		inOrder(T->rchild);	
}
Node *Insert(Node *T,int x)
{
	if(T == NULL)
	{ //Ҫ����create()����
		T = create();
		T->c = x;
		return T;
	}
	else if(x < T->c)
		T->lchild = Insert(T->lchild,x);
	else if(x > T->c)
		T->rchild = Insert(T->rchild,x);
	return T;
	//��Ϊ���������Node�͵ģ��������Ҫ����T
}
int main()
{
	char tmp[12];
	int n;
	int i;
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%s",tmp);
		loc = 0;//��ʼ����̬�ռ�
		Node *T = NULL;
		for(i=0;tmp[i]!='\0';i++)
			T = Insert(T,tmp[i]-'0');
		size1 = 0;
		//��ʼ��,����൱�ڰѺ�������������ķ���һ���ַ�����
		size = &size1;
		str = str1;
		postOrder(T);
		inOrder(T);
		str1[size1] = '\0';
		while(n--!=0)
		{
			scanf("%s",tmp);
			Node *T2 = NULL;
			for(i=0;tmp[i]!='\0';i++)
				T2 = Insert(T2,tmp[i]-'0');
			size2 = 0; //��ʼ��
			size = &size2;
			str = str2;
			postOrder(T2);
			inOrder(T2);
			str2[size2] = '\0';
			puts(strcmp(str1,str2)==0?"YES":"NO");
		}
	}
	return 0;
}