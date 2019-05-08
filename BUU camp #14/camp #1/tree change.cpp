#include<bits/stdc++.h>

using namespace std;

vector< int > tree[1010];
int q, n, maxcut = -1;
int mark[1010];
int testroot( int curnode )
{
    mark[curnode] = 1;
    int ma1 = -1, ma2 = -1;
    for( int i = 0 ; i < tree[curnode].size() ; i++ ){
        if( mark[tree[curnode][i]] ) continue;
        int now = testroot( tree[curnode][i] );
        if( now > ma1 ){
            ma1 = now;
            ma2 = ma1;
        }
        else{
            ma2 = max( ma2, now );
        }
    }
    if( ma1 == -1 || ma2 == -1 ){
        return 1;
    }
    return ma1 + ma2 + 1;
}
int main()
{
    scanf("%d",&q);
    while( q-- ){
        maxcut = 0;
        for( int i = 0 ; i < 1010 ; i++ ){
            tree[i].clear();
        }
        scanf("%d",&n);
        for( int i = 0 ; i < n - 1 ; i++ ){
            int f, t;
            scanf("%d %d",&f,&t);
            tree[f].push_back( t );
            tree[t].push_back( f );
        }
        for( int i = 1 ; i <= n ; i++ ){
            for( int j = 0 ; j < 1010 ; j++ ){
                mark[j] = 0;
            }
            if( tree[i].size() != 0 )
                if( maxcut < n - testroot( i ) ){
                    maxcut = n - testroot( i );
                }
        }
        printf("%d\n",maxcut);
    }
}
