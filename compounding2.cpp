#include<stdio.h> 
#include<math.h> 
void meun(); 
void captical_profit(int temp);
void captica(int temp);
void time(int temp);
 main() 
 { 
 	int temp;
	char temp0,temp1;
 	meun(); 
lab:	printf("请选择种类:"); 
 	scanf("%d",&temp);
	if(temp>0&&temp<6)   //判断输入是否正确
	{ 
    	while(1)  //循环选择
		{
    	if(temp>0&&temp<4) 
    		captical_profit(temp); //求本利和
    	else if(temp==4)
    		captica(temp);        //求本金
		else if(temp==5)
			time(temp);
    	else if(temp==6) 
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
	else  //输入错误
	{
		printf("输入错误!\n\n是否要重新输入(y/n):");
		getchar();
    	scanf("%c",&temp1);
		if(temp1=='y')
    		goto lab;
    	else
			return 0;
	}
 } 
 //菜单
 void meun() 
 { 
 	printf("*******************************\n"); 
 	printf("*       1 一次支付复利        *\n"); 
 	printf("*       2 等额多次支付复利    *\n"); 
 	printf("*       3 单利计算            *\n");
	printf("*       4 投入的本金计算      *\n");
	printf("*       5 计息期数            *\n");
	printf("*       6 退出                *\n");
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
		F=P*(pow((1+i),n));	 //一次支付复利计算
		break;
	case 2:
     	F=(P*(pow((1+i),n)-1))/i; //多次等额复利计算
		break;
	case 3:
		F=P*(1+i*n);    //单利计算
		break;
	}
 	printf("本利和为:%lf\n\n",F); 
 } 
 //求本金
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
 	printf("本金为:%lf\n\n",P); 
 }

//求计息期数
 void time(int temp)
 {
	 int n,flat=0; 
 	double P,i,F; 
 	printf("请输入本利和:"); 
 	scanf("%lf",&F); 
 	printf("请输入年回报率:"); 
 	scanf("%lf",&i); 
 	printf("请输入本金:"); 
 	scanf("%lf",&P); 
 	for(n=1;n<100;n++)    //穷举法求100年满足的计息期数
	{
		if((P*(pow((1+i),n)))>=F)
		{
			printf("计息期数:%d\n\n",n);
			flat=1;
			break;
		}
	}
	if(flat==0)
    	printf("在100年内没有符合计息期数!\n\n");

 }