#include<stdio.h>
#include<math.h>
int main()
{
int n,x,s=0;
scanf("%d",&n);
for(int i=1;i<=n;i++)
{
	scanf("%d",&x);
	if((i+1)%2==0)
		{s=s+pow(x,3);}
	if((i+1)%2!=0)
		{s=s-pow(x,3);}
}
printf("%d\n",s);}
