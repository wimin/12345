
# include <stdio.h>
# include <stdlib.h>
# include <conio.h>              // getch() ����ͷ�ļ�
# include <string.h> 
#include <math.h> 

char list[20][100] = {
	{"|----------------------------------------------------|"},
	{"|                    Ŀ¼                            |"},
	{"|----------------------------------------------------|"},
	{"|                >> һ. ����                         |"},
	{"|                   ��. ����                         |"},
	{"|                   ��. Ͷ���ʽ�                     |"},
	{"|                   ��. Ͷ��ʱ��                     |"},
	{"|                   ��. �������                     |"},
	{"|                   ��. ����                         |"},
	{"|                   ��. ÿ�µȶϢ����             |"},
	{"|                   ��. Ͷ�ʼ���                     |"},
	{"|                   ��. �˳�                         |"},
	{"|----------------------------------------------------|"}
};

char list2[3][100] = {
	{"|                      > 1. һ��֧��                 |"},
	{"|                        2. ��εȶ�֧��             |"},
	{"|                        3. ����                     |"}
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
 void display(int x)                           // ����б� ����  
{
	int i, j;							
	for(i = 0; i < 13; i++)			// ѭ����ӡ�б�
	{
		if(x == 2 && i == 5)			// x = 2ʱ�� ��Ŀ¼���Ӳ˵�
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

int move(int x, int row, int levl)					// xΪ�����ƶ��ı����� rowȷ��������ַ������λ�ã� levl��ʾ��ǰ�ı��Ϊ�ڼ�����
{
	if(levl == 1 && row+x >= 3 && row+x <= 13)            // ��row ��1��3֮��ʱ��ָ����������ƶ�
	{
		system("cls");								// ����
		list[row][17] = list[row][18] = ' ';			// ����ǰָ�����ڵ�λ�ñ�Ϊ�ո�
		row = row + x;								// row ָ���µ�λ��
		list[row][17] = list[row][18] = '>';			// ��ָ��������µ�λ����
		display(0);									// �ٴδ�ӡ�б�
	}	
   else if(3 == levl && row+x >= 0 && row+x <= 2)
	{
		system("cls");
		list2[row][23] = ' ';
		row = row + x;
		list2[row][23] = '>';
		display(2);
	}
	return row;												// ���ص�ǰrow ���ڵ�λ��
}

 main() 
 { 
	char x;										 //  ��ȡ�û�������
	int row = 3;								 //   ��¼��ǰ��ѡ��Ĺ���
	int row2 = 0;						

	LAB1:
	system("cls");
	display(0);              //   �ȴ�ӡһ���б�
	while(1)            //   ���޽����û�������
	{
		printf("\t\twΪ�ϣ�sΪ�£� �س�ѡ��\n");
		x = getch();	// ��ȡ�û�������
		switch(x)
		{
		case 'w':
			row = move(-1, row, 1);break;         // ����Ϊw �� ָ�������ƶ�  
		case 's':
			row = move(1, row, 1);break;			// ����Ϊs�� ָ�������ƶ�
		case '\r':
			if(row == 3)								
			{
				C();                       //Ͷ���ʽ�
			}
				else if(row == 4)					
			{										
				system("cls");		// ����
				display(2);				// �������һ�µ�2����
				while(1)			
				{
					printf("\t\twΪ�ϣ�sΪ�£� �س�ѡ��\n");
					x = getch();	                         // ��ȡ�û�������
					switch(x)
					{
					case 'w':
						row2 = move(-1, row2, 3);break;
					case 's':
						row2 = move(1, row2, 3);break;
					case '\r':
						if(row2 == 2)                
						{	
							goto LAB1;					// goto �� LAB1
						}
						else if(row2 == 0)
						{
						    A();	//      ��������
						}
						else if(row2 == 1)
						{
						     B();	//     ��������
						}
					}
				}
			}
			else if(row == 5)					
			{						
				D();	                   // Ͷ��ʱ��
			}
			else if(row == 6)
			{
				E();	                  // �������
			}
			else if(row == 7)
			{
				F();		// ����
			}
			else if(row == 8)
			{
				G();		// ÿ�µȶϢ���� 
			}
			else if(row == 9)
			{
				H();		// Ͷ�ʼ���
			}
			else if(row == 10)						// �˳�ѡ��
			{	
				printf("\n\n\t   ллʹ��.\n");
				return 0;
			}
			break;	// ����س���ѡ����
		}
	}
 } 
   
 void A()//һ��Ͷ�븴������ 
 { 
     int n;//ʱ��n 
	 char c;
     double p,i,sum1;//�ܽ��p,����i,������sum1 

LABA:    printf("\n\t*����������:");
     while(scanf("%lf",&p)!=1||p<=0)
     {
        printf("\t�������!!!\n\n\t*��������������:"); 
             getchar();   
     } 
     printf("\t*����������:"); 
     while(scanf("%lf",&i)!=1||i<=0)
     {
        printf("\t�������!!!\n\n\t*��������������:"); 
        getchar();    
     }  
     printf("\t*������洢ʱ��(��):"); 
     while(scanf("%d",&n)!=1||n<=0||n>100)
     {
        printf("\t�������!!!\n\n\t*����������洢ʱ��(��):"); 
             getchar();    
     } ; 
     sum1=p*pow((1+i),n);//�����ļ��㹫ʽ 
     printf("\t**������Ϊ:%.2lf\n\n",sum1);//�����������Ľ�� 
	 printf("�Ƿ�Ҫ��������(y/n): ");
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

void B()//��εȶ�֧����������
 { 
     int n;
     double p,i,sum2=0;
     char choose,c;
LABB:     printf("\n\t��εȶ�Ͷ�뷽ʽ:\n\t1.�ȶ�����Ͷ\n\t2.�ȶ�����Ͷ\n\t*��ѡ��:");
     while(scanf("%d",&choose)!=1||choose<1||choose>2)
     {
        printf("\t�������!!!\n\n\t������ѡ��:"); 
        while(getchar() != '\n');        
     }
     while(getchar() != '\n');
     if(choose==1)
     {
        printf("\n\t*��������Ͷ���:"); 
        while(scanf("%lf",&p)!=1||p<=0)
        {
            printf("\t�������!!!\n\n\t*������������Ͷ���:"); 
            getchar();   
        } 
        printf("\t*������������:"); 
        while(scanf("%lf",&i)!=1||i<=0)
        {
            printf("\t�������!!!\n\n\t*��������������:"); 
            getchar();    
        }  
        printf("\t*������洢ʱ��(��):"); 
        while(scanf("%d",&n)!=1||n<=0||n>100)
        {
            printf("\t�������!!!\n\n\t*����������洢ʱ��(��):"); 
            getchar();    
        } 
        sum2=p*12*(pow(1+i,n)-1)/i;
        printf("\t**������Ϊ:%.2lf\n\n",sum2);
     }
     else
     {
        printf("\n\t*��������Ͷ���:"); 
        while(scanf("%lf",&p)!=1||p<=0)
        {
            printf("\t�������!!!\n\n\t*������������Ͷ���:"); 
            getchar();   
        }  
        printf("\t*������������:"); 
        while(scanf("%lf",&i)!=1||i<=0)
        {
            printf("\t�������!!!\n\n\t*��������������:"); 
            getchar();    
        }  
        printf("\t*������洢ʱ��(��):"); 
        while(scanf("%d",&n)!=1||n<=0||n>100)
        {
            printf("\t�������!!!\n\n\t*����������洢ʱ��(��):"); 
            getchar();  
        }
        sum2=(p*pow((1+i),n)-1)/i;
        printf("\t**������Ϊ:%.2lf\n\n",sum2);
     }
	  printf("�Ƿ�Ҫ��������(y/n): ");
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

 void C()//�������� 
 { 
     int n; 
	 char c;
     double p,i,sum3; 
LABC:    printf("\n\t*����������:"); 
     while(scanf("%lf",&p)!=1||p<=0)
     {
        printf("\t�������!!!\n\n\t*��������������:"); 
        getchar();   
     }  
     printf("\t*������������:"); 
     while(scanf("%lf",&i)!=1||i<=0)
     {
        printf("\t�������!!!\n\n\t*��������������:"); 
        getchar();    
     }   
     printf("\t*������洢ʱ��(��):"); 
     while(scanf("%d",&n)!=1||n<=0||n>100)
     {
        printf("\t�������!!!\n\n\t*����������洢ʱ��(��):"); 
        getchar();  
     } 
     sum3=p*(1+i*n); 
     printf("\t**������Ϊ:%.2lf\n\n",sum3); 
	 printf("�Ƿ�Ҫ��������(y/n): ");
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

 void D() //Ͷ���ʽ�
 { 
     int n; 
	 char c;
     double sum4,i,p;//pΪͶ�뱾�� 
LABD:    printf("\n\t*�����뱾����:");
     while(scanf("%lf",&sum4)!=1||sum4<=0)
     {
        printf("\t�������!!!\n\n\t*���������뱾����:"); 
        getchar();   
     }   
     printf("\t*������������:"); 
     while(scanf("%lf",&i)!=1||i<=0)
     {
        printf("\t�������!!!\n\n\t*��������������:"); 
        getchar();    
     }  
     printf("\t*��������ʱ��(��):"); 
     while(scanf("%d",&n)!=1||n<=0||n>100)
     {
        printf("\t�������!!!\n\n\t*������������ʱ��(��):"); 
        getchar();  
     }  
     p=sum4/(1+i*n); 
     printf("\t**Ͷ��ı���Ϊ:%.2lf\n\n",p); 
	 	 printf("�Ƿ�Ҫ��������(y/n): ");
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

 void E()   //Ͷ��ʱ��
 {
     double n;
	 char c;
     double sum5,i,p;
LABE:    printf("\n\t*������洢���:");
     while(scanf("%lf",&p)!=1||p<=0)
     {
        printf("\t�������!!!\n\n\t*����������洢���:"); 
        getchar();   
     }   
     printf("\t*������������:");
     while(scanf("%lf",&i)!=1||i<=0)
     {
        printf("\t�������!!!\n\n\t*��������������:"); 
        getchar();    
     }   
     printf("\t*�����뱾����:");
     while(scanf("%lf",&sum5)!=1||sum5<=0)
     {
        printf("\t�������!!!\n\n\t*���������뱾����:"); 
        getchar();   
     }   
     n=(log(sum5/p))/(log(1+i));
     printf("\t**Ͷ���ʱ��Ϊ:%.0lf\n\n",n);
	 	 printf("�Ƿ�Ҫ��������(y/n): ");
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

void F()  //����
{
	char c;
    double sum6,i,p,n;
LABF:   printf("\n\t*������洢���:");
    while(scanf("%lf",&p)!=1||p<=0)
    {
        printf("\t�������!!!\n\n\t*����������洢���:"); 
        getchar();   
    }   
    printf("\t*������洢ʱ��(��):");
    while(scanf("%d",&n)!=1||n<=0||n>100)
    {
        printf("\t�������!!!\n\n\t*����������洢ʱ��(��):"); 
        getchar();  
    } 
    printf("\t*�����뱾����:");
    while(scanf("%lf",&sum6)!=1||sum6<=0)
    {
        printf("\t�������!!!\n\n\t*���������뱾����:"); 
        getchar();   
    }   
    i=pow((sum6/p),(1/n))-1;
    printf("\t**����Ϊ:%.2lf\n\n",i);
		 printf("�Ƿ�Ҫ��������(y/n): ");
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
LABG:    printf("\n\t*�����������:");
    while(scanf("%lf",&sum7)!=1||sum7<=0)
    {
        printf("\t�������!!!\n\n\t*���������뱾����:"); 
        getchar();   
    }   
    printf("\t*���������ʱ��(��):");
    while(scanf("%d",&n)!=1||n<=0||n>100)
    {
        printf("\t�������!!!\n\n\t*�������������ʱ��(��):"); 
        getchar();  
    } 
    printf("\t*������������:");
    while(scanf("%lf",&i)!=1||i<=0)
    {
        printf("\t�������!!!\n\n\t*��������������:"); 
        getchar();    
    }   
    p=sum7*i/(12*(1+i)*(pow(1+i,n)-1));
    printf("\t**ÿ�µȶϢ����Ϊ:%.2lf\n\n",p);
		 	 printf("�Ƿ�Ҫ��������(y/n): ");
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

 void H()//��������Ͷ�ʷ�ʽ���������
 {
    int n,op=0;
	char c;
	double i,p;
	double temp;
	double record[4];
LABH:	printf("\t*������洢���:");
	while(scanf("%lf",&p)!=1||p<=0)
    {
        printf("\t�������!!!\n\n\t*����������洢���:"); 
        getchar();   
    }   
	printf("\t*������������:");
	  while(scanf("%lf",&i)!=1||i<=0)
    {
        printf("\t�������!!!\n\n\t*��������������:"); 
        getchar();    
    }   
    printf("\t*������tͶ��ʱ��(��):");
	while(scanf("%d",&n)!=1||n<=0||n>100)
    {
       printf("\t�������!!!\n\n\t*����������Ͷ��ʱ��(��):"); 
       getchar();  
    }
	record[0]=p*pow((1+i),n);//����
	I(0,record);
	record[1]=p*12*(pow(1+i,n)-1)/i;//�ȶ���Ͷ
    I(1,record);
	record[2]=(p*pow((1+i),n)-1)/i;//�ȶ���Ͷ
	I(2,record);
	record[3]=p*(1+i*n);//����
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
	printf("\t�Ƽ�:\n");
	I(op,record);
		 	 	 printf("�Ƿ�Ҫ��������(y/n): ");
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

 void I(int op,double record[4])//�ж�����Ͷ�ʷ�ʽ���������
 {
	 switch (op)
	 {
	 case 0:printf("\tѡ����Ͷ��,������Ϊ%.2lf\n",record[0]);break;
	 case 1:printf("\tѡ��ȶ���Ͷ��,������Ϊ%.2lf\n",record[1]);break;
	 case 2:printf("\tѡ��ȶ���Ͷ��,������Ϊ%.2lf\n",record[2]);break;
	 case 3:printf("\tѡ��ȵ���Ͷ��,������Ϊ%.2lf\n",record[3]);break;
	 }
 }
