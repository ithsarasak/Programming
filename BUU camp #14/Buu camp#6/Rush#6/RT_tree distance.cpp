#include<bits/stdc++.h>
using namespace std;
vector<int> g[50050];
long long dp[50050][505];
long long ans=0;
int k;
void dfs(int now,int p){
    dp[now][0]=1;
    int i,j;
    for(i=0;i<g[now].size();i++){
        if(g[now][i]==p) continue;
        dfs(g[now][i],now);
        for(j=0;j<k;j++){
            ans+=dp[now][j]*dp[g[now][i]][k-1-j];
        }
        for(j=1;j<=k;j++){
            dp[now][j]+=dp[g[now][i]][j-1];
        }
    }
}
int main()
{
    int n,a,b,i;
    scanf(" %d %d",&n,&k);
    for(i=1;i<n;i++){
        scanf(" %d %d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,1);
    printf("%lld",ans);
    return 0;
}
