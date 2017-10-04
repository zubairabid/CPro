#include<stdio.h>
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int a[n],b[10000];
	for(int i=0;i<10000;i++)
		b[i]=0;
	int max=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		b[a[i]]++;
		max=a[i]>max?a[i]:max;
	}
	int sum=0,c=0;
	for(int i=max;i>=0;i--)
	{
		if(b[i]>0)
		{
			for(int j=1;j<=b[i];j++)
			{
				c++;
				sum+=i;
				if(sum>=k)
					break;
			}
			if(sum>=k)
				break;
		}
	}
	if(c>0)
		printf("%d\n", c);
	else
		printf("-1");
	return 0;
}