#include<bits/stdc++.h>

using namespace std;
struct qq{
    int lv, node;
}t;
int com[100010], n, mxlv, m, k, mark[100010];
long long ans;
vector<int> lan[100010], lv[200010];
queue<qq> q;
priority_queue<int> pq;
void bfs( int k )
{
    q.push({ 0, k });
    while( !q.empty() ){
        t = q.front();
        q.pop();
        mark[t.node] = 1;
        if( mxlv < t.lv ){
            mxlv = t.lv;
        }
        lv[t.lv].push_back( t.node );
        for( int i = 0 ; i < lan[t.node].size() ; i++ ){
            if( mark[lan[t.node][i]] == 0 ){
                mark[lan[t.node][i]] = 1;
                q.push({ t.lv + 1, lan[t.node][i] });
            }
        }
    }
}
int main()
{
    scanf("%d %d %d",&n,&m,&k);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&com[i]);
    }
    for( int i = 0 ; i < m ; i++ ){
        int f, t;
        scanf("%d %d",&f,&t);
        lan[f].push_back( t );
        lan[t].push_back( f );
    }
    bfs( k );
    for( int i = 1 ; i <= n ; i++ ){
        if( !mark[i] ){
            ans = max( ans, ans + ( long long )com[i] );
        }
    }
    for( int i = mxlv ; i >= 1 ; i-- ){
        for( int j = 0 ; j < lv[i].size() ; j++ ){
            pq.push({ com[lv[i][j]] });
        }
        int te = pq.top();
        pq.pop();
        ans = max( ans , ans + ( long long )te );
    }
    printf("%lld",ans);
    return 0;
}

