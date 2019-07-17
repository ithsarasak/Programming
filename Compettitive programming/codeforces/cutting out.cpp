#include <bits/stdc++.h>
using namespace std;
#define MaxN 200005
int mark[MaxN];
int cntsort[MaxN];
int ans[MaxN];
int main()
{
    int n,l,r,k,mid,now,num;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&num);
        cntsort[num]++;
    }
    l=1,r=n;
    while(l<r)
    {
        mid=(l+r+1)/2;
        now=0;
        for(int i=1;i<=MaxN-5;i++)
        {
            if(cntsort[i]/mid+now>=k)
            {
                mark[i]=k-now;
                now=k;
                break;
            }
            else
            {
                mark[i]=cntsort[i]/mid;
                now+=cntsort[i]/mid;
            }
        }
        if(now>=k)
        {
            l=mid;
        }
        else
        {
            r=mid-1;
        }

        //memset(mark,0,sizeof mark);
    }
    memset(mark,0,sizeof mark);
    now=0;
    for(int i=1;i<=MaxN-5;i++)
        {
            if(cntsort[i]/l+now>=k)
            {
                mark[i]=k-now;
                now=k;
                break;
            }
            else
            {
                mark[i]=cntsort[i]/l;
                now+=cntsort[i]/l;
            }
        }
    for(int i=1;i<=MaxN-5;i++)
    {
        while(mark[i]!=0)   printf("%d ",i),mark[i]--;
    }
    return 0;
}