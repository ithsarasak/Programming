#include<bits/stdc++.h>
using namespace std;
int lowlink[100100], Index[100100], cnt = 1, onstack[100100], comp[100100], cnt2 = 1;
vector<int> g[100100];
stack<int> st;
int dfs( int u )
{
    lowlink[u] = Index[u] = cnt++;
    st.push(u);
    onstack[u] = 1;
    for( auto &x : g[u] ){
        if( Index[x] == 0 ){
            dfs(x);
            lowlink[u] = min( lowlink[u], lowlink[x] );
        }
        else if( onstack[x] ){
            lowlink[u] = min( lowlink[u], Index[x] );
        }
    }
    if( Index[u] == lowlink[u] ){
        while( st.top() != u ){
            int now = st.top();
            st.pop();
            onstack[now] = 0, comp[now] = cnt2;
        }
        st.pop();
        onstack[u] = 0, comp[u] = cnt2;
        cnt2++;
    }
}
int main()
{
    int n, m, k, i, j, d;
    scanf("%d %d %d",&n,&m,&k);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&d);
        while( d-- ){
           scanf("%d",&j);
           g[i].push_back( j );
        }
    }
    for(int i = 1 ; i <= n ; i++ ){
        if( Index[i] == 0 ){
            dfs(i);
        }
    }
    for( int i = 0 ; i < k ; i++ ){
        scanf("%d %d",&j,&d);
        printf((comp[j] == comp[d] )?"yes\n":"no\n");
    }
}
