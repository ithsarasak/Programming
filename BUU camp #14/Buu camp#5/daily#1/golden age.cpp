#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long mic[50100][150];
long long val[50500];
long long play(long long node,long long ma)
{
    long long maxx=-1;
    if(mic[node][ma]!=-1)   return mic[node][ma];
    if(node>n)    return 0;
    if(ma==0)   return mic[node][0]=0;
    for(long long i=0;i<ma;i++)
    {
            maxx=max(maxx,play(node*2,i)+play(node*2+1,ma-i-1));
    }
    return mic[node][ma]=maxx+val[node];
}
int main()
{
    long long ans=-1;
    scanf("%lld %lld",&n,&k);
    for(long long i=1;i<=n;i++)
    {
        scanf("%lld",&val[i]);
    }
    memset(mic,-1,sizeof mic);
    for(long long i=1;i<=n;i++)
    {
        ans=max(ans,play(i,k));
    }
    printf("%lld\n",ans);
    return 0;
}

