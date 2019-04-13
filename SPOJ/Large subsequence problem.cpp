#include<bits/stdc++.h>
using namespace std;
#define MaxN 10005
#define mod 1000000000+7
char str[MaxN];
long long fw[10];
void update(long long idx,long long val)
{
    while(idx<=9)
    {
        fw[idx]+=val;
        idx+=idx&-idx;
    }
}
long long query(long long idx)
{
    long long ans=0;
    while(idx>0)
    {
        ans+=fw[idx];
        idx-=idx&-idx;
    }
    return ans;
}
int main()
{
    long long q,n,now,x;
    long long ans=0;
    scanf("%lld",&q);
    for(int j=1;j<=q;j++)
    {
        ans=0;
        scanf(" %s",str+1);
        n=strlen(str+1);
        memset(fw,0,sizeof fw);
        update(1,1);
        for(long long i=1;i<=n;i++)
        {
            now=str[i]-'0';
            x=query(now);
            x%=mod;
            ans+=x;
            ans%=mod;
//            //ans=(ans+mod)%mod;
            update(now+1,x);
        }
        printf("Case %d: %lld\n",j,ans);
    }
    return 0;
}

