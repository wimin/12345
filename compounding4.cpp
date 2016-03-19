#include<stdio.h>   
  #include<math.h>   
  void meun();   
  void captical_profit(int temp);  
  void captica();  
   void rate(); 
  void time();
  void repayment();
   main()   
   {   
   	int temp;  
  	char temp0,temp1;  
   	meun();   
  lab:	printf("请选择种类:");   
   	scanf("%d",&temp);  
  	if(temp>0&&temp<10)   //判断输入是否正确  
  	{   
      	while(1)  //循环选择  
  		{  
      	if(temp>0&&temp<5)   
      		captical_profit(temp); //求本利和  
      	else if(temp==5)  
      		captica();        //求本金  
  		else if(temp==6)  
  			time();  
 		else if(temp==7)  
  			rate();
		else if(temp==8)  
  			repayment();
      	else if(temp==9)   
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
   	printf("**********************************\n");   
   	printf("*       1 一次支付复利           *\n");   
   	printf("*       2 定额定投收益计算(年)   *\n"); 
	printf("*       3 定额定投收益计算(月)   *\n");
   	printf("*       4 单利计算               *\n");  
  	printf("*       5 投入的本金计算         *\n");  
  	printf("*       6 计息期数               *\n");  
 	printf("*       7 利率                   *\n");
  	printf("*       8 月等额本息还款         *\n"); 
	printf("*       9 退出                   *\n");
   	printf("**********************************\n");   
   }   
   void captical_profit(int temp)   
   {   
   	int n;   
   	double P,i,F=0;   
   	printf("请输入期初金额:");   
   	scanf("%lf",&P);   
   	printf("请输入年利率:");   
   	scanf("%lf",&i);   
   	printf("请输入期限:");   
   	scanf("%d",&n);   
  	switch(temp)  
  	{  
  	case 1:  
  		F=P*(pow((1+i),n)); //一次支付复利计算  
  		break;  
 	case 2:  
	 	{
			F=P;
			for(int j=1;j<=n;j++)
				F=F+P*(pow((1+i),j));
		}
		break;
    /* 	F=(P*(pow((1+i),n)-1))/i; //多次等额复利计算  
  		break; */ 
	case 3:  
       	F=12*P*(1+i)*(-1+pow((1+i),n))/i;
		break;
  	case 4:  
  		F=P*(1+i*n);    //单利计算  
  		break;  
  	}  
   	printf("本利和为:%lf\n\n",F);   
   }   
   //求本金  
   void captica()   
   {   
   	int n;   
   	double P,i,F;   
   	printf("请输入本利和:");   
   	scanf("%lf",&F);   
   	printf("请输入年回报率:");   
   	scanf("%lf",&i);   
   	printf("请输入期限:");   
   	scanf("%d",&n);   
   	P=F/(pow((1+i),n));   
   	printf("本金为:%lf\n\n",P);   
   }  
   //利率 
    void rate()   
   {   
   	double P,i,F,n;   
   	printf("请输入本利和:");   
   	scanf("%lf",&F);   
   	printf("请输入本金:");   
   	scanf("%lf",&P);   
   	printf("请输入期限:");   
   	scanf("%lf",&n);   
   	i=pow((F/P),(1/n))-1;   
   	printf("利率为:%lf\n\n",i);   
   }  
  //求计息期数  
  /* void time()  
   {  
  	 int n,flat=0;   
   	double P,i,F;   
   	printf("请输入本利和:");   
   	scanf("%lf",&F);   
   	printf("请输入年回报率:");   
   	scanf("%lf",&i);   
   	printf("请输入本金:");   
   	scanf("%lf",&P);   
   	for(n=1;n<100;n++)    //穷举法求100年满足的期限  
  	{  
  		if((P*(pow((1+i),n)))>=F)  
  		{  
  			printf("期限数:%d\n\n",n);  
  			flat=1;  
  			break;  
  		}  
  	}  
  	if(flat==0)  
      	printf("在100年内没有符合期限!\n\n");  
    
   } */ 
  void time()   
   {   
 	int n; 
   	double P,i,F;   
   	printf("请输入本利和:");   
   	scanf("%lf",&F);   
   	printf("请输入本金:");   
   	scanf("%lf",&P);   
   	printf("请输入利率:");   
   	scanf("%lf",&i);   
    n=(log(F/P))/(log(1+i)); 
 	if((log(F/P))/(log(1+i))>n) 
 		n++; 
     printf("期限:%d\n\n",n);  
   }  
  //月等额本息还款
 void repayment()
 {
	 int n;   
   	double P,i,F,j;   
   	printf("请输入贷款金额:");   
   	scanf("%lf",&P);   
   	printf("请输入年利率:");   
   	scanf("%lf",&i);   
   	printf("请输入期限:");   
   	scanf("%d",&n);
	j=i/12;
	F=(P*j*pow((1+j),(n*12)))/(pow((1+j),(n*12))-1);
	printf("每月等额本息还款:%lf\n\n",F); 
 }
