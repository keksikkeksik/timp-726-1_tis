#include<stdio.h>
int main()
{
int n,x,pred,k=1;
scanf("%d",&n);
for (int i=0;i<n;i++)
{
scanf("%d",&x);
if(i==0)pred=x;
else if (pred<=x)pred=x;
else k=0;
pred=x;
}
printf("%d\n",k);
return(0);
}
