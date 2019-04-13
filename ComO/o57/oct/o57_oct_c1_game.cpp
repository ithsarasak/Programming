#include<bits/stdc++.h>

using namespace std;
struct qq{
    int no, lv;
}t;
vector<int> g[5010], g2[5010], g3[5010];
stack<int> st;
queue<qq> q;
int n, p, k;
int visit[5010], visit2[5010], mark[5010], lv[5010], ind[5010], ans[5010];
void dfs( int no )
{
    visit[no] = 1;
    for( int i = 0 ; i < g[no].size() ; i++ ){
        if( !visit[g[no][i]] )dfs( g[no][i] );
    }
    st.push( no );
    return ;
}
void dfs2( int no, int co )
{
    visit2[no] = co;
    for( int i = 0 ; i < g2[no].size() ; i++ ){
        if( !visit2[g2[no][i]] )dfs2( g2[no][i] , co );
    }
    return ;
}
int main()
{
    scanf("%d %d",&n,&p);
    for( int i = 0 ; i < p ; i++ ){
        int f, t;
        scanf("%d %d",&f,&t);
        f++, t++;
        g[f].push_back( t );
        g2[t].push_back( f );
    }
    for( int i = 1 ; i <= n ; i++ ){
        if( !visit[i] )dfs( i );
    }
    int co = 0;
    while( !st.empty() ){
        int tt = st.top();
        st.pop();
        if( !visit2[tt] )co++,dfs2( tt , co );
    }
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 0 ; j < g[i].size() ; j++ ){
            if( visit2[i] != visit2[g[i][j]] ){
                g3[visit2[i]].push_back( visit2[g[i][j]] );
                ind[visit2[g[i][j]]]++;
            }
        }
    }
    for( int i = 1 ; i <= n ; i++ ){
        if( ind[i] == 0 && mark[i] == 0 ){
            q.push({ i, 0 });
            while( !q.empty() ){
                t = q.front();
                q.pop();
                mark[t.no] = 1;
                lv[t.no] = max( lv[t.no], t.lv );
                for( int j = 0 ; j < g3[t.no].size() ; j++ ){
                    ind[g3[t.no][j]]--;
                    lv[g3[t.no][j]] = max( lv[t.no] + 1, lv[g3[t.no][j]] );
                    if( ind[g3[t.no][j]] == 0 ){
                        q.push({ g3[t.no][j], t.lv + 1 });
                    }
                }
            }
        }
    }
    for( int i = 1 ; i <= n ; i++ ){
        //printf("%d %d\n",visit2[i],lv[visit2[i]]);
        ans[lv[visit2[i]]]++;
        k = max( k, lv[visit2[i]] );
    }
    for( int i = 0 ; i <= k ; i++ ){
        printf("%d ",ans[i]);
    }
    return 0;
}
