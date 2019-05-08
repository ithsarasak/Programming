#include<bits/stdc++.h>

using namespace std;
struct qq{
    int di, idx;
    bool operator<( const qq &k )const{
        if( di == k.di ){
            return idx < k.idx;
        }
        else return di > k.di;
    }
}t;
struct gg{
    int go, w;
};
priority_queue< qq > q;
vector< gg > g[300010];
int ti, n, ind[300010], mark[300010], ma[300010];
int main()
{
    scanf("%d",&ti);
    while( ti-- ){
        scanf("%d",&n);
        for( int i = 0 ; i < n - 1 ; i++ ){
            int f, t, d;
            scanf("%d %d %d",&f,&t,&d);
            g[f].push_back({ t, d });
            g[t].push_back({ f, d });
            ind[f]++;
            ind[t]++;
        }
        for( int i = 0 ; i < n ; i++ ){
            if( ind[i] == 1 ){
                q.push({ 0, i });
            }
        }
        for( int i = 0 ; i < n - 1 ; i++ ){
            t = q.top();
            q.pop();
            mark[t.idx] = 1;
            for( int j = 0 ; j < g[t.idx].size() ; j++ ){
                if( !mark[g[t.idx][j].go] ){
                    ind[g[t.idx][j].go]--;
                    ma[g[t.idx][j].go] = max( ma[g[t.idx][j].go], t.di + g[t.idx][j].w );
                    if( ind[g[t.idx][j].go] == 1 || ind[g[t.idx][j].go] == 0 ){
                        q.push({ g[t.idx][j].go, ma[g[t.idx][j]] });
                    }
                }
            }
        }
        for( int i = 1 ; i <= n ; i++ ){
            if( !mark[i] ){
                printf("%d %d\n",i,ma[i]);
            }
        }
    }
    return 0;
}
