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
lab:	printf("��ѡ������:"); 
 	scanf("%d",&temp);
	if(temp>0&&temp<6)   //�ж������Ƿ���ȷ
	{ 
    	while(1)  //ѭ��ѡ��
		{
    	if(temp>0&&temp<4) 
    		captical_profit(temp); //������
    	else if(temp==4)
    		captica(temp);        //�󱾽�
		else if(temp==5)
			time(temp);
    	else if(temp==6) 
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
	else  //�������
	{
		printf("�������!\n\n�Ƿ�Ҫ��������(y/n):");
		getchar();
    	scanf("%c",&temp1);
		if(temp1=='y')
    		goto lab;
    	else
			return 0;
	}
 } 
 //�˵�
 void meun() 
 { 
 	printf("*******************************\n"); 
 	printf("*       1 һ��֧������        *\n"); 
 	printf("*       2 �ȶ���֧������    *\n"); 
 	printf("*       3 ��������            *\n");
	printf("*       4 Ͷ��ı������      *\n");
	printf("*       5 ��Ϣ����            *\n");
	printf("*       6 �˳�                *\n");
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
		F=P*(pow((1+i),n));	 //һ��֧����������
		break;
	case 2:
     	F=(P*(pow((1+i),n)-1))/i; //��εȶ������
		break;
	case 3:
		F=P*(1+i*n);    //��������
		break;
	}
 	printf("������Ϊ:%lf\n\n",F); 
 } 
 //�󱾽�
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
 	printf("����Ϊ:%lf\n\n",P); 
 }

//���Ϣ����
 void time(int temp)
 {
	 int n,flat=0; 
 	double P,i,F; 
 	printf("�����뱾����:"); 
 	scanf("%lf",&F); 
 	printf("��������ر���:"); 
 	scanf("%lf",&i); 
 	printf("�����뱾��:"); 
 	scanf("%lf",&P); 
 	for(n=1;n<100;n++)    //��ٷ���100������ļ�Ϣ����
	{
		if((P*(pow((1+i),n)))>=F)
		{
			printf("��Ϣ����:%d\n\n",n);
			flat=1;
			break;
		}
	}
	if(flat==0)
    	printf("��100����û�з��ϼ�Ϣ����!\n\n");

 }