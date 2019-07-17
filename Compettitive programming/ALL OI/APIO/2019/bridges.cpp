#include <bits/stdc++.h>
#define pll pair<long long, long long>
#define t first
#define d second

using namespace std;

const int N = 1e5 + 10;
const int M = 3e5 + 10;
struct bb {
    long long f, t, d;
}bri[M];
int visit[N];
vector<pll> g[N];
int n, m, qe;
queue<int> q;

int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 1 ; i <= m ; i++ ) {
        scanf("%lld %lld %lld",&bri[i].f,&bri[i].t,&bri[i].d);
        g[bri[i].f].emplace_back( pll( bri[i].t, bri[i].d ) ), g[bri[i].t].emplace_back( pll( bri[i].f, bri[i].d ) );
    }
    scanf("%d",&qe);
    //for( int i = 1 ; i <= m ; i++ ) cout << bri[i].f << " " << bri[i].t << " " << bri[i].d << endl;
    while( qe-- ) {
        int op;
        long long a, b;
        scanf("%d %lld %lld",&op,&a,&b);
        if( op == 1 ) {
            long long f = bri[a].f, t = bri[a].t;
            //printf("ft%lld %lld\n",f,t);
            for( int i = 0 ; i < g[f].size() ; i++ ) {
                //cout << g[f][i].t << endl;
                if( g[f][i].t == t ) {
                //cout << f << " " << t << endl;
                g[f][i].d = b;
            }
            }
            for( int i = 0 ; i < g[t].size() ; i++ ) if( g[t][i].t == f ) g[t][i].d = b;
        }
        else {
            int ans = 0;
            memset( visit, 0, sizeof visit );
            q.emplace( a );
            // for( int i = 1 ; i <= n ; i++ ) {
            //     printf("i : \n");
            //     for( pll j : g[i] ) printf("%lld %lld\n",j.t,j.d);
            //     printf("\n");
            // }
            while( !q.empty() ) {
                int t = q.front(); q.pop();
                visit[t] = 1;
                //printf("%d\n",t);
                for( pll i : g[t] ) if( !visit[i.t] && i.d >= b ) {
                    visit[i.t] = 1;
                    q.emplace( i.t );
                }
            }
            for( int i = 1 ; i <= n ; i++ ) if( visit[i] ) ans++;
            printf("%d\n",ans);
        }
    }
    return 0;
}