#include<bits/stdc++.h>

using namespace std;
struct ee{
    int t, d;
};
struct qq{
    int no, d, bi;
    bool operator<( const qq &k )const{
        return d > k.d;
    }
}t;
int n, m, k, mf;
int sp[210][210], va[210], dis[210][32100], mark[210][32100];
vector<int> fri;
vector<ee> g[210];
priority_queue<qq> q;
int main()
{
    scanf("%d %d %d",&n,&m,&k);
    fri.push_back( 1 );
    for( int i = 0 ; i < k ; i++ ){
        scanf("%d",&mf);
        va[mf] = 1 << i;
        fri.push_back( mf );
    }
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            if( i == j )sp[i][j] = 0;
            else sp[i][j] = 1e9;
        }
    }
    fri.push_back( n );
    for( int i = 0 ; i < m ; i++ ){
        int f, t, d;
        scanf("%d %d %d",&f,&t,&d);
        g[f].push_back({ t, d });
        g[t].push_back({ f, d });
        sp[f][t] = min( sp[f][t], d );
        sp[t][f] = min( sp[t][f], d );
    }

    for( int k = 1 ; k <= n ; k++ ){
        for( int i = 1 ; i <= n ; i++ ){
            for( int j = 1 ; j <= n ; j++ ){
                sp[i][j] = min( sp[i][j], sp[i][k] + sp[k][j] );
            }
        }
    }
    int s = fri.size();
    q.push({ 1, 0, 0 });
    memset( dis, 127, sizeof dis );
    while( !q.empty() ){
        t = q.top();
        q.pop();
        if( mark[t.no][t.bi] )continue;
        mark[t.no][t.bi] = 1;
        if( t.no == n && t.bi == (1<<k)-1 ){
            printf("%d",t.d);
            return 0;
        }
        for( int i = 0 ; i < s ; i++ ){
            if( t.no == fri[i] )continue;
            if( !mark[fri[i]][t.bi|va[fri[i]]] ){
                if( dis[fri[i]][t.bi|va[fri[i]]] > t.d + sp[t.no][fri[i]] ){
                    dis[fri[i]][t.bi|va[fri[i]]] = t.d + sp[t.no][fri[i]];
                    q.push({ fri[i], t.d + sp[t.no][fri[i]], t.bi|va[fri[i]] });
                }
            }
        }
    }
}
