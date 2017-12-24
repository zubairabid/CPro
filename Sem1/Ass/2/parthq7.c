#include<stdio.h>
#define N 10000001
long long int arr[N];
long long int count[N*10];
int main()
{
        long long int n,a,i,sum=0,p,m,mean,median,b,c,count,max,ind;

        scanf("%lld",&n);

        for (a=0;a<n;a++)
        {scanf("%lld",&arr[a]);
        count[arr[a]]++;
        }
        p=0;
        for(i=0;i<N*10;i++)
        {if (count[i]!=0)
            {while(count[i]--)
                {
                    arr[p]=i;
                    p++;
                }
            }
        }
        for(m=0;m<n;m++)
         {sum=sum+arr[m];
         }

        mean=sum/n;

        median=(arr[n/2]+arr[(n/2)+1])/2;

        max=0;
        for (b=0;b<n;b++)
         {count=1;
            for (c=b+1;c<n;c++)
            {  if (arr[b] == arr[c])
                        count++;
                if (max<count)
                {        max=count;
                         ind=b;
                }
             }
         }

        printf("%lld %lld %lld\n",mean,median,arr[ind]);

return 0;
}
