#include<bits/stdc++.h>

using namespace std;
struct vv{
    int t;
    long long d;
};
struct qq{
    int t, pre, sp;
    long long d;
    bool operator<( const qq &k )const{
        return d > k.d;
    }
}te;
int n, m, l, qe;
long long dis[80100][15], mi = 1e18;
vector<vv> v[80100];
priority_queue<qq> q;
int mark[80100];
int main()
{
    scanf("%d %d %d %d",&n,&m,&l,&qe);
    for( int i = 0 ; i < m ; i++ ){
        int a, b;
        long long w;
        scanf("%d %d %lld",&a,&b,&w);
        v[a].push_back({ b, w });
    }
    for( int i = 0 ; i < l ; i++ ){
        int ro;
        scanf("%d",&ro);
        mark[ro] = 1;
    }
    for( int i = 0 ; i <= 80000 ; i++ ){
        for( int j = 0 ; j <= 11 ; j++ ){
            dis[i][j] = 1e18;
        }
    }
    dis[1][0] = 0;
    q.push({ 1, -1, 0, 0 });
    while( !q.empty() ){
        te = q.top();
        q.pop();
        //printf("%d %d %d %lld\n",te.t,te.pre,te.sp,te.d);
        if( mark[te.t] && te.pre != te.t && te.sp < qe ){
            te.sp++;
            te.pre = te.t;
        }
        for( int i = 0 ; i < v[te.t].size() ; i++ ){
            if( dis[v[te.t][i].t][te.sp] > te.d + ( v[te.t][i].d / ( 1 << te.sp ) ) ){
                dis[v[te.t][i].t][te.sp] = te.d + ( v[te.t][i].d / ( 1 << te.sp ) );
                q.push({ v[te.t][i].t, te.pre, te.sp, te.d + ( v[te.t][i].d / ( 1 << te.sp ) ) });
            }
        }
    }
    for( int i = 0 ; i <= qe ; i++ ){
        mi = min( mi, dis[n][i] );
    }
    printf("%lld",mi);
    return 0;
}
