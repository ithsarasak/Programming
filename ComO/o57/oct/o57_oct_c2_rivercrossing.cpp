#include<bits/stdc++.h>

using namespace std;
struct rr{
    int st, en;
}t[50100], t2[50100];
int n, m, k, l;
int mic[50100][15];
int ans;
vector<int> g[50100], g2[50100];
int main()
{
    for( int i = 0 ; i <= 50000 ; i++ )mic[i][0] = 1;
    scanf("%d %d %d %d",&n,&m,&k,&l);
    for( int i = 0 ; i < l ; i++ ){
        int f, t;
        scanf("%d %d",&f,&t);
        g[f].push_back( t );
        g2[t].push_back( f );
    }
    for( int i = 1 ; i <= n ; i++ ){
        sort( g[i].begin(), g[i].end() );
    }
    for( int i = 1 ; i <= m ; i++ ){
        sort( g2[i].begin(), g2[i].end() );
    }
    for( int i = 1 ; i <= n ; i++ ){
        int ho;
        scanf("%d %d",&ho,&t[i].st);
        t[i].en = t[i].st + ho - 1;
        for( int j = 0 ; j < g[i].size() ; j++ ){
            if( g[i][j] >= t[i].st && g[i][j] <= t[i].en )t[i].en++;
        }
    }
    for( int i = 1 ; i <= m ; i++ ){
        int ho;
        scanf("%d %d",&ho,&t2[i].st);
        t2[i].en = t2[i].st + ho - 1;
        for( int j = 0 ; j < g2[i].size() ; j++ ){
            if( g2[i][j] >= t2[i].st && g2[i][j] <= t2[i].en )t2[i].en++;
        }
    }
    for( int i = 1 ; i <= k ; i++ ){
        if( i % 2 ){
            for( int j = 1 ; j <= n ; j++ ){
                mic[t[j].st][i] += mic[j][i-1];
                mic[t[j].en+1][i] -= mic[j][i-1];
                for( int o = 0 ; o < g[j].size() ; o++ ){
                    if( g[j][o] >= t[i].st && g[j][o] <= t[i].en ){
                        mic[g[j][o]][i] -= mic[j][i-1];
                        mic[g[j][o]+1][i] += mic[j][i-1];
                    }
                }
            }
            for( int j = 1 ; j <= m ; j++ ){
                mic[j][i] += mic[j-1][i];
                mic[j][i] %= 30011;
                ans += mic[j][i];
                ans %= 30011;
            }
        }
        else{
            for( int j = 1 ; j <= m ; j++ ){
                mic[t2[j].st][i] += mic[j][i-1];
                mic[t2[j].en+1][i] -= mic[j][i-1];
                for( int o = 0 ; o < g2[j].size() ; o++ ){
                    if( g2[j][o] >= t2[i].st && g2[j][o] <= t2[i].en ){
                        mic[g2[j][o]][i] -= mic[j][i-1];
                        mic[g2[j][o]+1][i] += mic[j][i-1];
                    }
                }
            }
            for( int j = 1 ; j <= n ; j++ ){
                mic[j][i] += mic[j-1][i];
                mic[j][i] %= 30011;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
