#include<bits/stdc++.h>

using namespace std;
int n, e, qq, visit[1010];
int f, t;
queue<int> q;
vector<int> g[1010];
int main()
{
    scanf("%d %d %d",&n,&e,&qq);
    for( int i = 0 ; i < e ; i++ ){
        scanf("%d %d",&f,&t);
        g[f].push_back(t);
    }
    for( int i = 0 ; i < qq ; i++ ){
        scanf("%d %d",&f,&t);
        q.push( f );
        memset( visit, 0, sizeof visit );
        while( !q.empty() ){
            int te = q.front();
            q.pop();
            visit[te] = 1;
            if( te == t ) break;
            for( int j = 0 ; j < g[te].size() ; j++ ){
                if( !visit[g[te][j]] ){
                    q.push( g[te][j] );
                }
            }
        }
        if( visit[t] )printf("Yes\n");
        else printf("No\n");
        while( !q.empty() ) q.pop();
    }
    return 0;
}
