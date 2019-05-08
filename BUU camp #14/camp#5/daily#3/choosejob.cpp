#include<bits/stdc++.h>

using namespace std;
struct w{
    int f, t, d;
    bool operator<( const w &k )const{
        if( t == k.t ) return f < k.f;
        return t < k.t;
    }
}wo[100010];
int n, st[100010], en[100010], mo[100010], dp[100010], ans;
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d %d %d",&wo[i].f,&wo[i].t,&wo[i].d);
    }
    sort( wo + 1, wo + n + 1 );
    for( int i = 1 ; i <= n ; i++ ){
        st[i] = wo[i].f;
        en[i] = wo[i].t;
        mo[i] = wo[i].d;
    }
    dp[0] = 0;
    for( int i = 1 ; i <= n ; i++ ){
        int idx = lower_bound( en + 1, en + n + 1, st[i] ) - en;
        idx--;
        dp[i] = max( dp[i-1], dp[idx] + mo[i] );
        ans = max( ans, dp[i] );
    }
    printf("%d",ans);
    return 0;
}
