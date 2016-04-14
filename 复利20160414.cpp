
# include <stdio.h>
# include <stdlib.h>
# include <conio.h>              // getch() 函数头文件
# include <string.h> 
#include <math.h> 

char list[20][100] = {
	{"|----------------------------------------------------|"},
	{"|                    目录                            |"},
	{"|----------------------------------------------------|"},
	{"|                >> 一. 单利                         |"},
	{"|                   二. 复利                         |"},
	{"|                   三. 投入资金                     |"},
	{"|                   四. 投入时间                     |"},
	{"|                   五. 利润计算                     |"},
	{"|                   六. 利率                         |"},
	{"|                   七. 每月等额本息还款             |"},
	{"|                   八. 投资计算                     |"},
	{"|                   九. 退出                         |"},
	{"|----------------------------------------------------|"}
};

char list2[3][100] = {
	{"|                      > 1. 一次支付                 |"},
	{"|                        2. 多次等额支付             |"},
	{"|                        3. 后退                     |"}
}; 
 
 void A(); 
 void B(); 
 void C(); 
 void D(); 
 void E();
 void F();
 void G();
 void H();
 void I(int op,double record[4]);
 void display(int x)                           // 输出列表 函数  
{
	int i, j;							
	for(i = 0; i < 13; i++)			// 循环打印列表
	{
		if(x == 2 && i == 5)			// x = 2时， 打开目录的子菜单
		{
			for(j = 0; j < 3; j++)
			{
				printf("      \t%s", list2[j]);
				putchar('\n');
			}
		}
		printf("      \t%s", list[i]);
		putchar('\n');
	}
}

int move(int x, int row, int levl)					// x为上下移动的变量， row确定光标在字符串里的位置， levl表示当前的表格为第几个表
{
	if(levl == 1 && row+x >= 3 && row+x <= 13)            // 当row 在1到3之间时，指标可以上下移动
	{
		system("cls");								// 清屏
		list[row][17] = list[row][18] = ' ';			// 将当前指标所在的位置变为空格
		row = row + x;								// row 指向新的位置
		list[row][17] = list[row][18] = '>';			// 让指标出现在新的位置上
		display(0);									// 再次打印列表
	}	
   else if(3 == levl && row+x >= 0 && row+x <= 2)
	{
		system("cls");
		list2[row][23] = ' ';
		row = row + x;
		list2[row][23] = '>';
		display(2);
	}
	return row;												// 返回当前row 所在的位置
}

 main() 
 { 
	char x;										 //  获取用户的输入
	int row = 3;								 //   记录当前所选择的功能
	int row2 = 0;						

	LAB1:
	system("cls");
	display(0);              //   先打印一次列表
	while(1)            //   无限接收用户的输入
	{
		printf("\t\tw为上，s为下， 回车选择\n");
		x = getch();	// 获取用户的输入
		switch(x)
		{
		case 'w':
			row = move(-1, row, 1);break;         // 输入为w ， 指标向上移动  
		case 's':
			row = move(1, row, 1);break;			// 输入为s， 指标向下移动
		case '\r':
			if(row == 3)								
			{
				C();                       //投入资金
			}
				else if(row == 4)					
			{										
				system("cls");		// 清屏
				display(2);				// 输出功能一下的2级表
				while(1)			
				{
					printf("\t\tw为上，s为下， 回车选择\n");
					x = getch();	                         // 获取用户的输入
					switch(x)
					{
					case 'w':
						row2 = move(-1, row2, 3);break;
					case 's':
						row2 = move(1, row2, 3);break;
					case '\r':
						if(row2 == 2)                
						{	
							goto LAB1;					// goto 至 LAB1
						}
						else if(row2 == 0)
						{
						    A();	//      复利计算
						}
						else if(row2 == 1)
						{
						     B();	//     单利计算
						}
					}
				}
			}
			else if(row == 5)					
			{						
				D();	                   // 投入时间
			}
			else if(row == 6)
			{
				E();	                  // 利润计算
			}
			else if(row == 7)
			{
				F();		// 利率
			}
			else if(row == 8)
			{
				G();		// 每月等额本息还款 
			}
			else if(row == 9)
			{
				H();		// 投资计算
			}
			else if(row == 10)						// 退出选项
			{	
				printf("\n\n\t   谢谢使用.\n");
				return 0;
			}
			break;	// 输入回车键选择功能
		}
	}
 } 
   
 void A()//一次投入复利计算 
 { 
     int n;//时间n 
	 char c;
     double p,i,sum1;//总金额p,利率i,本利和sum1 

LABA:    printf("\n\t*请输入存款金额:");
     while(scanf("%lf",&p)!=1||p<=0)
     {
        printf("\t输入错误!!!\n\n\t*请重新输入存款金额:"); 
             getchar();   
     } 
     printf("\t*请输入利率:"); 
     while(scanf("%lf",&i)!=1||i<=0)
     {
        printf("\t输入错误!!!\n\n\t*请重新输入利率:"); 
        getchar();    
     }  
     printf("\t*请输入存储时间(年):"); 
     while(scanf("%d",&n)!=1||n<=0||n>100)
     {
        printf("\t输入错误!!!\n\n\t*请重新输入存储时间(年):"); 
             getchar();    
     } ; 
     sum1=p*pow((1+i),n);//复利的计算公式 
     printf("\t**本利和为:%.2lf\n\n",sum1);//输出复利计算的结果 
	 printf("是否要重新输入(y/n): ");
	 getchar();
		scanf("%c",&c);
		if(c=='y')
			goto LABA;
		else
		{
			system("cls");
			display(2);
		}
	}

void B()//多次等额支付复利计算
 { 
     int n;
     double p,i,sum2=0;
     char choose,c;
LABB:     printf("\n\t多次等额投入方式:\n\t1.等额多次月投\n\t2.等额多次年投\n\t*请选择:");
     while(scanf("%d",&choose)!=1||choose<1||choose>2)
     {
        printf("\t输入错误!!!\n\n\t请重新选择:"); 
        while(getchar() != '\n');        
     }
     while(getchar() != '\n');
     if(choose==1)
     {
        printf("\n\t*请输入月投金额:"); 
        while(scanf("%lf",&p)!=1||p<=0)
        {
            printf("\t输入错误!!!\n\n\t*请重新输入月投金额:"); 
            getchar();   
        } 
        printf("\t*请输入年利率:"); 
        while(scanf("%lf",&i)!=1||i<=0)
        {
            printf("\t输入错误!!!\n\n\t*请重新输入利率:"); 
            getchar();    
        }  
        printf("\t*请输入存储时间(年):"); 
        while(scanf("%d",&n)!=1||n<=0||n>100)
        {
            printf("\t输入错误!!!\n\n\t*请重新输入存储时间(年):"); 
            getchar();    
        } 
        sum2=p*12*(pow(1+i,n)-1)/i;
        printf("\t**本利和为:%.2lf\n\n",sum2);
     }
     else
     {
        printf("\n\t*请输入年投金额:"); 
        while(scanf("%lf",&p)!=1||p<=0)
        {
            printf("\t输入错误!!!\n\n\t*请重新输入年投金额:"); 
            getchar();   
        }  
        printf("\t*请输入年利率:"); 
        while(scanf("%lf",&i)!=1||i<=0)
        {
            printf("\t输入错误!!!\n\n\t*请重新输入利率:"); 
            getchar();    
        }  
        printf("\t*请输入存储时间(年):"); 
        while(scanf("%d",&n)!=1||n<=0||n>100)
        {
            printf("\t输入错误!!!\n\n\t*请重新输入存储时间(年):"); 
            getchar();  
        }
        sum2=(p*pow((1+i),n)-1)/i;
        printf("\t**本利和为:%.2lf\n\n",sum2);
     }
	  printf("是否要重新输入(y/n): ");
	 getchar();
		scanf("%c",&c);
		if(c=='y')
			goto LABB;
		else
		{
			system("cls");
			display(2);
		}
 } 

 void C()//单利计算 
 { 
     int n; 
	 char c;
     double p,i,sum3; 
LABC:    printf("\n\t*请输入存款金额:"); 
     while(scanf("%lf",&p)!=1||p<=0)
     {
        printf("\t输入错误!!!\n\n\t*请重新输入存款金额:"); 
        getchar();   
     }  
     printf("\t*请输入年利率:"); 
     while(scanf("%lf",&i)!=1||i<=0)
     {
        printf("\t输入错误!!!\n\n\t*请重新输入利率:"); 
        getchar();    
     }   
     printf("\t*请输入存储时间(年):"); 
     while(scanf("%d",&n)!=1||n<=0||n>100)
     {
        printf("\t输入错误!!!\n\n\t*请重新输入存储时间(年):"); 
        getchar();  
     } 
     sum3=p*(1+i*n); 
     printf("\t**本利和为:%.2lf\n\n",sum3); 
	 printf("是否要重新输入(y/n): ");
	 	 getchar();
		scanf("%c",&c);
		if(c=='y')
			goto LABC;
		else
		{
			system("cls");
			display(1);
		}
 } 

 void D() //投入资金
 { 
     int n; 
	 char c;
     double sum4,i,p;//p为投入本金 
LABD:    printf("\n\t*请输入本利和:");
     while(scanf("%lf",&sum4)!=1||sum4<=0)
     {
        printf("\t输入错误!!!\n\n\t*请重新输入本利和:"); 
        getchar();   
     }   
     printf("\t*请输入年利率:"); 
     while(scanf("%lf",&i)!=1||i<=0)
     {
        printf("\t输入错误!!!\n\n\t*请重新输入利率:"); 
        getchar();    
     }  
     printf("\t*请输入存款时间(年):"); 
     while(scanf("%d",&n)!=1||n<=0||n>100)
     {
        printf("\t输入错误!!!\n\n\t*请重新输入存款时间(年):"); 
        getchar();  
     }  
     p=sum4/(1+i*n); 
     printf("\t**投入的本金为:%.2lf\n\n",p); 
	 	 printf("是否要重新输入(y/n): ");
	 	 getchar();
		scanf("%c",&c);
		if(c=='y')
			goto LABD;
		else
		{
			system("cls");
			display(1);
		}
 }

 void E()   //投入时间
 {
     double n;
	 char c;
     double sum5,i,p;
LABE:    printf("\n\t*请输入存储金额:");
     while(scanf("%lf",&p)!=1||p<=0)
     {
        printf("\t输入错误!!!\n\n\t*请重新输入存储金额:"); 
        getchar();   
     }   
     printf("\t*请输入年利率:");
     while(scanf("%lf",&i)!=1||i<=0)
     {
        printf("\t输入错误!!!\n\n\t*请重新输入利率:"); 
        getchar();    
     }   
     printf("\t*请输入本利和:");
     while(scanf("%lf",&sum5)!=1||sum5<=0)
     {
        printf("\t输入错误!!!\n\n\t*请重新输入本利和:"); 
        getchar();   
     }   
     n=(log(sum5/p))/(log(1+i));
     printf("\t**投入的时间为:%.0lf\n\n",n);
	 	 printf("是否要重新输入(y/n): ");
	 	 getchar();
		scanf("%c",&c);
		if(c=='y')
			goto LABE;
		else
		{
			system("cls");
			display(1);
		}
 }

void F()  //利率
{
	char c;
    double sum6,i,p,n;
LABF:   printf("\n\t*请输入存储金额:");
    while(scanf("%lf",&p)!=1||p<=0)
    {
        printf("\t输入错误!!!\n\n\t*请重新输入存储金额:"); 
        getchar();   
    }   
    printf("\t*请输入存储时间(年):");
    while(scanf("%d",&n)!=1||n<=0||n>100)
    {
        printf("\t输入错误!!!\n\n\t*请重新输入存储时间(年):"); 
        getchar();  
    } 
    printf("\t*请输入本利和:");
    while(scanf("%lf",&sum6)!=1||sum6<=0)
    {
        printf("\t输入错误!!!\n\n\t*请重新输入本利和:"); 
        getchar();   
    }   
    i=pow((sum6/p),(1/n))-1;
    printf("\t**利率为:%.2lf\n\n",i);
		 printf("是否要重新输入(y/n): ");
	 	 getchar();
		scanf("%c",&c);
		if(c=='y')
			goto LABF;
		else
		{
			system("cls");
			display(1);
		}
}

void G()
{
	char c;
    double sum7,i,p,n;
LABG:    printf("\n\t*请输入贷款金额:");
    while(scanf("%lf",&sum7)!=1||sum7<=0)
    {
        printf("\t输入错误!!!\n\n\t*请重新输入本利和:"); 
        getchar();   
    }   
    printf("\t*请输入贷款时间(年):");
    while(scanf("%d",&n)!=1||n<=0||n>100)
    {
        printf("\t输入错误!!!\n\n\t*请重新输入贷款时间(年):"); 
        getchar();  
    } 
    printf("\t*请输入年利率:");
    while(scanf("%lf",&i)!=1||i<=0)
    {
        printf("\t输入错误!!!\n\n\t*请重新输入利率:"); 
        getchar();    
    }   
    p=sum7*i/(12*(1+i)*(pow(1+i,n)-1));
    printf("\t**每月等额本息还款为:%.2lf\n\n",p);
		 	 printf("是否要重新输入(y/n): ");
	 	 getchar();
		scanf("%c",&c);
		if(c=='y')
			goto LABG;
		else
		{
			system("cls");
			display(1);
		}
}

 void H()//计算哪种投资方式的利益最大
 {
    int n,op=0;
	char c;
	double i,p;
	double temp;
	double record[4];
LABH:	printf("\t*请输入存储金额:");
	while(scanf("%lf",&p)!=1||p<=0)
    {
        printf("\t输入错误!!!\n\n\t*请重新输入存储金额:"); 
        getchar();   
    }   
	printf("\t*请输入年利率:");
	  while(scanf("%lf",&i)!=1||i<=0)
    {
        printf("\t输入错误!!!\n\n\t*请重新输入利率:"); 
        getchar();    
    }   
    printf("\t*请输入t投资时间(年):");
	while(scanf("%d",&n)!=1||n<=0||n>100)
    {
       printf("\t输入错误!!!\n\n\t*请重新输入投资时间(年):"); 
       getchar();  
    }
	record[0]=p*pow((1+i),n);//复利
	I(0,record);
	record[1]=p*12*(pow(1+i,n)-1)/i;//等额月投
    I(1,record);
	record[2]=(p*pow((1+i),n)-1)/i;//等额年投
	I(2,record);
	record[3]=p*(1+i*n);//单利
	I(3,record);
	temp=record[0];
	for(int j=1;j<4;j++)
	{
		if(record[j]>temp)
		{
			temp=record[j];
			op=j;
		}
	}
	printf("\t推荐:\n");
	I(op,record);
		 	 	 printf("是否要重新输入(y/n): ");
	 	 getchar();
		scanf("%c",&c);
		if(c=='y')
			goto LABH;
		else
		{
			system("cls");
			display(1);
		}
 }

 void I(int op,double record[4])//判断哪种投资方式的利益最大
 {
	 switch (op)
	 {
	 case 0:printf("\t选择复利投资,本利和为%.2lf\n",record[0]);break;
	 case 1:printf("\t选择等额月投资,本利和为%.2lf\n",record[1]);break;
	 case 2:printf("\t选择等额年投资,本利和为%.2lf\n",record[2]);break;
	 case 3:printf("\t选择等单利投资,本利和为%.2lf\n",record[3]);break;
	 }
 }
