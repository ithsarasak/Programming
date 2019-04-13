#include<bits/stdc++.h>

using namespace std;

struct a{
    int m, n;
    bool operator<( const a &o )const{
        return m < o.m;
    }
}ans[300010];
vector< int > g[300010];
int visit[300010], mother[300010], sizes, counts, ss, num;
stack< int > st;
int dfs( int k , int before )
{
    if( g[k].size() != 0 )
    {
        //printf("! %d %d\n",k,before);
    }
    if( visit[k] == 0 ){
        visit[k] = 1;
    }
    st.push( k );
    for( int j = 0 ; j < g[k].size() ; j++ ){
        if( g[k][j] != before ){
            if( visit[g[k][j]] == 1 ){
                while( !st.empty() ){
                    int t;
                    t = st.top();
                    //printf("t = %d gkj = %d\n",t,g[k][j]);
                    visit[t] = 2;
                    mother[sizes] = t;
                    sizes++;
                    st.pop();
                    if( t == g[k][j] ){
                        break;
                    }
                }
            }
            else if( visit[g[k][j]] == 0 ){
                dfs( g[k][j] , k );
            }
        }
    }
    if( !st.empty() ){
        st.pop();
    }
}
int dfs2( int k, int prev )
{
    //printf("k%d %d\n",k,prev);
    if( visit[k] == 1 ){
        counts++ ;
        visit[k] = 2;
    }
    for( int j = 0 ; j < g[k].size() ; j++ ){
        if( visit[g[k][j]] == 1 ){
            dfs2( g[k][j] , k );
        }
    }
}
int main()
{
    scanf("%d",&num);
    for( int i = 0 ; i < num ; i ++ ){
        int f, t;
        scanf("%d %d",&f,&t);
        g[f].push_back( t );
        g[t].push_back( f );
    }
    for( int i = 0 ; i <= 300000 ; i++ ){
        if( visit[i] == 0 ){
            while( !st.empty() ){
                st.pop();
            }
            dfs( i , -99 );
        }
    }
    /*for( int i = 0 ; i < 300000 ; i++ ){
        if( visit[i] == 2 ){
            printf("%d ",i);
        }
        //printf("%d ",mother[i]);
    }
    printf("\n");*/
    for( int i = 0 ; i < sizes ; i++ ){
        dfs2( mother[i] , -99 );
        ans[ss].m = mother[i];
        ans[ss].n = counts;
        counts = 0;
        ss++;
    }
    sort( ans , ans + ss );
    for( int i = 0 ; i < ss ; i++ ){
        printf("%d %d\n",ans[i].m,ans[i].n);
    }
    return 0;
}
