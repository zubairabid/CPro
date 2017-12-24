#include<stdio.h>
int main()
{
	long long int i,a=1,x,sum=0;
	scanf("%lld",&x);

	while(a<x)
	{
		a=a*5;
		sum=sum+x%a;
	}
	printf("%lld",sum);
	return 0;
}
