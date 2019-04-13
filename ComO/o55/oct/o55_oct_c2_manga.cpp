#include<bits/stdc++.h>

using namespace std;
struct rr{
    int f, t;
    long long d;
}road[100100];
struct gg{
    int t;
    long long d;
};
struct qq{
    int no;
    long long d;
    bool operator<( const qq &k )const{
        return d > k.d;
    }
}tt;
int n, m;
long long k;
vector<gg> g[50100];
long long dis[50100];
priority_queue<qq> q;
int check( int mid )
{
    memset( dis, 127, sizeof dis );
    for( int i = 0 ; i <= 50010 ; i++ )g[i].clear();
    for( int i = 1 ; i <= mid ; i++ ){
        g[road[i].f].push_back({ road[i].t, road[i].d });
        g[road[i].t].push_back({ road[i].f, road[i].d });
    }
    q.push({ 1, 0 });
    dis[1] = 0;
    while( !q.empty() ){
        tt = q.top();
        q.pop();
        for( int i = 0 ; i < g[tt.no].size() ; i++ ){
            if( dis[g[tt.no][i].t] > tt.d + g[tt.no][i].d ){
                dis[g[tt.no][i].t] = tt.d + g[tt.no][i].d;
                q.push({ g[tt.no][i].t, tt.d + g[tt.no][i].d });
            }
        }
    }
    if( dis[n] <= k )return 1;
    else return 0;
}
int main()
{
    scanf("%d %d %lld",&n,&m,&k);
    for( int i = 1 ; i <= m ; i++ ){
        scanf("%d %d %lld",&road[i].f,&road[i].t,&road[i].d);
    }
    int l = 1, r = m;
    if( !check( m ) ){
        printf("-1");
        return 0;
    }
    while( l < r ){
        int mid = ( l + r ) / 2;
        if( check( mid ) )r = mid;
        else l = mid + 1;
    }
    printf("%d",l);
    return 0;
}
