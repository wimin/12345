#include<stdio.h>
#include<math.h>
void meun();
void first();
void second();
main()
{
	int temp;
	meun();
lab:	printf("请选择复利种类:");
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
	printf("*       1 一次支付复利        *\n");
	printf("*       2 等额多次支付复利    *\n");
	printf("*       3 退出                *\n");
	printf("*******************************\n");
}
void first()
{
	int n;
	double P,i,F;
	printf("请输入期初金额:");
	scanf("%lf",&P);
	printf("请输入利率:");
	scanf("%lf",&i);
	printf("请输入计息期数:");
	scanf("%d",&n);
	F=P*(pow((1+i),n));	
	printf("本利和为:%lf\n",F);
}
void second()
{
	int n;
	double A,i,F;
	printf("请输入年金:");
	scanf("%lf",&A);
	printf("请输入利率:");
	scanf("%lf",&i);
	printf("请输入计息期数:");
	scanf("%d",&n);
	F=(A*(pow((1+i),n)-1))/i;
	printf("本利和为:%lf\n",F);
}
