#include<bits/stdc++.h>

using namespace std;
long long rose[1000010], n, m, ans, rose2[1000010];
int main()
{
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&rose[i]);
        rose2[i] = rose[i];
    }
    for(int i=1;i<=m;i++){
        int t;
        scanf("%d",&t);
        if( i >= rose2[t] ){
            ans++,rose2[t]=i+rose[t];
        }
    }
    printf("%lld",ans);
    return 0;
}
