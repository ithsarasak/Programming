#include<bits/stdc++.h>
using namespace std;
vector<int> g[400010], re[400010];
stack<int> sta;
int mark1[400010], mark2[400010], q = 5, coun, n, m, a, b;
void play1( int p )
{
    mark1[p] = 1;
    for( int i = 0 ; i < g[p].size() ; i++ ){
        if( !mark1[g[p][i]] )
            play1( g[p][i] );
    }
    sta.push( p );
}
void play2( int p )
{
    mark2[p] = coun;
    for( int i = 0 ; i < re[p].size() ; i++ )
        if( !mark2[re[p][i]] )
            play2( re[p][i] );
}
int main()
{
    while( q-- ){
        scanf("%d %d",&n,&m);
        coun=0;
        memset( mark1, 0, sizeof mark1 );
        memset( mark2, 0, sizeof mark2 );
        for( int i = 0 ; i < n ; i++ ){
            scanf("%d %d",&a,&b);
            g[a*2+1].push_back(b*2);
            g[b*2+1].push_back(a*2);
            re[b*2].push_back(a*2+1);
            re[a*2].push_back(b*2+1);
        }
        for( int i = 0 ; i < m / 2 ; i++ ){
            scanf("%d %d",&a,&b);
            g[a*2].push_back(b*2+1);
            g[b*2].push_back(a*2+1);
            re[a*2+1].push_back(b*2);
            re[b*2+1].push_back(a*2);
        }
        for( int i = 2 ; i < 2*m+1 ; i++ ){
            if( !mark1[i] )
                play1( i );
        }
        while( !sta.empty() ){
            if( !mark2[sta.top()] ){
                coun++;
                play2( sta.top() );
            }
            sta.pop();
        }
        int ch = 0;
        for( int i = 1 ; i <= m ; i++ ){
            if( mark2[i*2] == mark2[i*2+1] ){
                ch = 1;
            }
        }
        if( ch ){
            printf("N");
        }
        else{
            printf("Y");
        }
        for( int i = 0 ; i <= m ; i++ ){
            g[i*2].clear();
            g[i*2+1].clear();
            re[i*2].clear();
            re[i*2+1].clear();
        }

    }
}
