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
  lab:	printf("��ѡ������:");   
   	scanf("%d",&temp);  
  	if(temp>0&&temp<10)   //�ж������Ƿ���ȷ  
  	{   
      	while(1)  //ѭ��ѡ��  
  		{  
      	if(temp>0&&temp<5)   
      		captical_profit(temp); //������  
      	else if(temp==5)  
      		captica();        //�󱾽�  
  		else if(temp==6)  
  			time();  
 		else if(temp==7)  
  			rate();
		else if(temp==8)  
  			repayment();
      	else if(temp==9)   
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
   	printf("**********************************\n");   
   	printf("*       1 һ��֧������           *\n");   
   	printf("*       2 ���Ͷ�������(��)   *\n"); 
	printf("*       3 ���Ͷ�������(��)   *\n");
   	printf("*       4 ��������               *\n");  
  	printf("*       5 Ͷ��ı������         *\n");  
  	printf("*       6 ��Ϣ����               *\n");  
 	printf("*       7 ����                   *\n");
  	printf("*       8 �µȶϢ����         *\n"); 
	printf("*       9 �˳�                   *\n");
   	printf("**********************************\n");   
   }   
   void captical_profit(int temp)   
   {   
   	int n;   
   	double P,i,F=0;   
   	printf("�������ڳ����:");   
   	scanf("%lf",&P);   
   	printf("������������:");   
   	scanf("%lf",&i);   
   	printf("����������:");   
   	scanf("%d",&n);   
  	switch(temp)  
  	{  
  	case 1:  
  		F=P*(pow((1+i),n)); //һ��֧����������  
  		break;  
 	case 2:  
	 	{
			F=P;
			for(int j=1;j<=n;j++)
				F=F+P*(pow((1+i),j));
		}
		break;
    /* 	F=(P*(pow((1+i),n)-1))/i; //��εȶ������  
  		break; */ 
	case 3:  
       	F=12*P*(1+i)*(-1+pow((1+i),n))/i;
		break;
  	case 4:  
  		F=P*(1+i*n);    //��������  
  		break;  
  	}  
   	printf("������Ϊ:%lf\n\n",F);   
   }   
   //�󱾽�  
   void captica()   
   {   
   	int n;   
   	double P,i,F;   
   	printf("�����뱾����:");   
   	scanf("%lf",&F);   
   	printf("��������ر���:");   
   	scanf("%lf",&i);   
   	printf("����������:");   
   	scanf("%d",&n);   
   	P=F/(pow((1+i),n));   
   	printf("����Ϊ:%lf\n\n",P);   
   }  
   //���� 
    void rate()   
   {   
   	double P,i,F,n;   
   	printf("�����뱾����:");   
   	scanf("%lf",&F);   
   	printf("�����뱾��:");   
   	scanf("%lf",&P);   
   	printf("����������:");   
   	scanf("%lf",&n);   
   	i=pow((F/P),(1/n))-1;   
   	printf("����Ϊ:%lf\n\n",i);   
   }  
  //���Ϣ����  
  /* void time()  
   {  
  	 int n,flat=0;   
   	double P,i,F;   
   	printf("�����뱾����:");   
   	scanf("%lf",&F);   
   	printf("��������ر���:");   
   	scanf("%lf",&i);   
   	printf("�����뱾��:");   
   	scanf("%lf",&P);   
   	for(n=1;n<100;n++)    //��ٷ���100�����������  
  	{  
  		if((P*(pow((1+i),n)))>=F)  
  		{  
  			printf("������:%d\n\n",n);  
  			flat=1;  
  			break;  
  		}  
  	}  
  	if(flat==0)  
      	printf("��100����û�з�������!\n\n");  
    
   } */ 
  void time()   
   {   
 	int n; 
   	double P,i,F;   
   	printf("�����뱾����:");   
   	scanf("%lf",&F);   
   	printf("�����뱾��:");   
   	scanf("%lf",&P);   
   	printf("����������:");   
   	scanf("%lf",&i);   
    n=(log(F/P))/(log(1+i)); 
 	if((log(F/P))/(log(1+i))>n) 
 		n++; 
     printf("����:%d\n\n",n);  
   }  
  //�µȶϢ����
 void repayment()
 {
	 int n;   
   	double P,i,F,j;   
   	printf("�����������:");   
   	scanf("%lf",&P);   
   	printf("������������:");   
   	scanf("%lf",&i);   
   	printf("����������:");   
   	scanf("%d",&n);
	j=i/12;
	F=(P*j*pow((1+j),(n*12)))/(pow((1+j),(n*12))-1);
	printf("ÿ�µȶϢ����:%lf\n\n",F); 
 }
