#include<bits/stdc++.h>

using namespace std;
struct qq{
    long long di, idx;
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
long long ti, n, ind[300010], mark[300010], ma[300010];
int main()
{
    scanf("%lld",&ti);
    while( ti-- ){
        while( !q.empty() ){
            q.pop();
        }
        memset( mark, 0, sizeof( mark ));
        memset( ind, 0, sizeof( ind ));
        memset( ma, 0, sizeof( ma ));
        for (int i = 0 ; i<300010;i++ ){
            g[i].clear();
        }
        scanf("%lld",&n);
        for( int i = 0 ; i < n - 1 ; i++ ){
            long long f, t, d;
            scanf("%lld %lld %lld",&f,&t,&d);
            g[f].push_back({ t, d });
            g[t].push_back({ f, d });
            ind[f]++;
            ind[t]++;
        }
        for( int i = 1 ; i <= n ; i++ ){
            //printf("%d %d\n",i,ind[i]);
            if( ind[i] == 1 ){
                q.push({ 0, i });
            }
        }
        for( int i = 0 ; i < n - 1 ; i++ ){
            t = q.top();
            q.pop();
            mark[t.idx] = 1;
            //printf("1 %d %d\n",t.di,t.idx);
            for( int j = 0 ; j < g[t.idx].size() ; j++ ){
                ind[g[t.idx][j].go]--;
                if( !mark[g[t.idx][j].go] ){
                    ma[g[t.idx][j].go] = max( ma[g[t.idx][j].go], t.di + g[t.idx][j].w );
                    if( ind[g[t.idx][j].go] == 1 )
                        q.push({ ma[g[t.idx][j].go] ,g[t.idx][j].go });

                }
            }
        }
        for( int i = 1 ; i <= n ; i++ ){
            if( !mark[i] ){
                printf("%lld %lld\n",i,ma[i]);
            }
        }
    }
    return 0;
}
