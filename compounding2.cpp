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
lab:	printf("��ѡ������:"); 
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
	printf("�Ƿ���Ҫ����ѡ��(y/n):"); 
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
 	printf("*       1 һ��֧������        *\n"); 
 	printf("*       2 �ȶ���֧������    *\n"); 
 	printf("*       3 ��������            *\n");
	printf("*       4 Ͷ��ı������      *\n");
	printf("*       5 �˳�                *\n");
 	printf("*******************************\n"); 
 } 
 void captical_profit(int temp) 
 { 
 	int n; 
 	double P,i,F; 
 	printf("�������ڳ����:"); 
 	scanf("%lf",&P); 
 	printf("����������:"); 
 	scanf("%lf",&i); 
 	printf("�������Ϣ����:"); 
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
 	printf("������Ϊ:%lf\n",F); 
 } 
 void captica(int temp) 
 { 
 	int n; 
 	double P,i,F; 
 	printf("�����뱾����:"); 
 	scanf("%lf",&F); 
 	printf("��������ر���:"); 
 	scanf("%lf",&i); 
 	printf("�������Ϣ����:"); 
 	scanf("%d",&n); 
 	P=F/(pow((1+i),n)); 
 	printf("����Ϊ:%lf\n",P); 
 }