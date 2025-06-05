#include <stdio.h>
int main(void)
{
	/*

	do
	{
    	(statement);
	} while(condition);

	 statement -> condition -> T -> Loop
   			                -> F -> Execute

   	do while -> co output o phan do, while kiem tra dieu kien output dam bao moi chay

	while(condition)
	{
    	(statement);
	}
	  condition -> T -> statement -> Loop until F
   	  condition -> F -> Execute

    while -> co input dam bao dieu kien moi chay
    */

    int n,i,a,b,U;
    double s,e;
    float x;
    // nhap n sao cho n>0 && n<100 -> ktra gia tri n sau khi nhap -> do while
    do
	{
    	printf("n="); scanf("%d",&n);
	}
	while (n<=0 || n>=100);

		printf("n=%d",n);

	// S= 1 +1/2+...+1/n
	x=0;
	s=0;
	for(i=1;i<=n;i++)
	{
		x+=(float)1/i;
		s+=(double)1/i;
	}
	printf("\n s=%lf, x=%f",s,x);
    // S =1 +1/2+... +1/n sao cho 1/n < e (e>0 && e<1) -> e cang be n cang to
   n=1;
   s=0;
   do
   {
   		printf("\ne="); scanf("%lf",&e);

   }while (e<=0 || e>= 1);

   while(1.0/n>e)
   {
   		s+=1/n;
   		n++;
   }
   printf("\n s=%lf \t n=%d",s,n);


   /*
   USCLN(a,b): if (a==b) --> USCLN = a
   Loop: if(a>b) a=a-b else b=b-a until a=b;
   USCLN = a;
   */

   printf("\na="); scanf("%d",&a);
   printf("\nb="); scanf("%d",&b);
   if(a==b)
   {
   	U=a;
   	printf("U=%d",U);
   	printf("\n");
   }
   else
   {
   	while(a!=b)
   	{
   		if(a>b) a=a-b;

   		else b=b-a;
	}
	U=a;
	printf("U=%d",U);
   	printf("\n");
   }
   }







