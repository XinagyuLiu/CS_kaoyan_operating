#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct Student
{
	char name[101];
	int age;
	int score;
	bool operator < (const Student &st) const 
	{
		int tmp = strcmp(name,st.name);
		if(score != st.score)
			return (score < st.score);
		//����ֱ�Ӽ򵥵�дif(score < st.score)
		//Ȼ��дelse����Ϊ�����С�ڵĻ�����>=����������� 
		else if(tmp != 0)
			return (tmp<0);
		else if(age != st.age)
			return (age < st.age);
	}
}buf[1000];
int main()
{
	int n;	
	while(scanf("%d",&n)!=EOF)
	{
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%s %d %d",buf[i].name,&buf[i].age,&buf[i].score);
		}
		sort(buf,buf+n);
		for(i=0;i<n;i++)
		{
			printf("%s %d %d\n",buf[i].name,buf[i].age,buf[i].score);
		}
	}
	return 0;
}