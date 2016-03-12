#include<stdio.h> 
 #include<math.h> 
 void meun(); 
void captical_profit(int temp);
void captica(int temp);
 main() 
 { 
 	int temp;
	char temp0;
 	meun(); 
lab:	printf("请选择种类:"); 
 	scanf("%d",&temp); 
	while(temp>0&&temp<6)
	{
 	if(temp>0&&temp<4) 
 		captical_profit(temp); 
	else if(temp==4)
		captica(temp);
 	else if(temp==5) 
 		return 0; 	
	meun(); 
	printf("是否需要继续选择(y/n):"); 
	getchar();
 	scanf("%c",&temp0);
	if(temp0=='y')
		goto lab;
	else
		break;
	}
 } 
 void meun() 
 { 
 	printf("*******************************\n"); 
 	printf("*       1 一次支付复利        *\n"); 
 	printf("*       2 等额多次支付复利    *\n"); 
 	printf("*       3 单利计算            *\n");
	printf("*       4 投入的本金计算      *\n");
	printf("*       5 退出                *\n");
 	printf("*******************************\n"); 
 } 
 void captical_profit(int temp) 
 { 
 	int n; 
 	double P,i,F; 
 	printf("请输入期初金额:"); 
 	scanf("%lf",&P); 
 	printf("请输入利率:"); 
 	scanf("%lf",&i); 
 	printf("请输入计息期数:"); 
 	scanf("%d",&n); 
	switch(temp)
	{
	case 1:
		F=P*(pow((1+i),n));	 
		break;
	case 2:
     	F=(P*(pow((1+i),n)-1))/i; 
		break;
	case 3:
		F=P*(1+i*n);
		break;
	}
 	printf("本利和为:%lf\n",F); 
 } 
 void captica(int temp) 
 { 
 	int n; 
 	double P,i,F; 
 	printf("请输入本利和:"); 
 	scanf("%lf",&F); 
 	printf("请输入年回报率:"); 
 	scanf("%lf",&i); 
 	printf("请输入计息期数:"); 
 	scanf("%d",&n); 
 	P=F/(pow((1+i),n)); 
 	printf("本金为:%lf\n",P); 
 }