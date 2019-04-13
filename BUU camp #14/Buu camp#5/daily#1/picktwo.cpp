#include<bits/stdc++.h>
using namespace std;
long long a[100100];
long long r[100100];
long long l[100100];
int main()
{
    long long ma,num,n,q,s=0,ma1=0,ma2=0;
    scanf("%lld",&q);
    while(q--)
    {
        s=0;
        ma=0;
        scanf("%lld",&n);
        for(long long i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            s+=a[i];
            if(s<0) s=0;
            l[i]=s;
            l[i] = max(l[i],l[i-1]);
        }
        s=0;
        for(long long i=n;i>=1;i--)
        {
            s+=a[i];
            if(s<0) s=0;
            r[i]=s;
            r[i]=max(r[i],r[i+1]);
        }
        for(long long i=0;i<=n;i++)
        {
            ma=max(ma,l[i]+r[i+1]);
        }
        printf("%lld\n",ma);
        memset(l,0,sizeof l);
        memset(r,0,sizeof r);
    }
    return 0;
}


