#include<stdio.h>
#include<math.h>
void meun();
void first();
void second();
main()
{
	int temp;
	meun();
lab:	printf("��ѡ��������:");
	scanf("%d",&temp);
	if(temp==1)
		first();
	else if(temp==2)
		second();
	else if(temp==3)
		return 0;
	else
		goto lab;
}
void meun()
{
	printf("*******************************\n");
	printf("*       1 һ��֧������        *\n");
	printf("*       2 �ȶ���֧������    *\n");
	printf("*       3 �˳�                *\n");
	printf("*******************************\n");
}
void first()
{
	int n;
	double P,i,F;
	printf("�������ڳ����:");
	scanf("%lf",&P);
	printf("����������:");
	scanf("%lf",&i);
	printf("�������Ϣ����:");
	scanf("%d",&n);
	F=P*(pow((1+i),n));	
	printf("������Ϊ:%lf\n",F);
}
void second()
{
	int n;
	double A,i,F;
	printf("���������:");
	scanf("%lf",&A);
	printf("����������:");
	scanf("%lf",&i);
	printf("�������Ϣ����:");
	scanf("%d",&n);
	F=(A*(pow((1+i),n)-1))/i;
	printf("������Ϊ:%lf\n",F);
}
