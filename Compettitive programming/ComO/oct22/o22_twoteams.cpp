#include<bits/stdc++.h>

using namespace std;
struct qq{
    int no, co;
}t;
struct cc{
    int a, b;
}day[100100];
int n, m;
int visit[100100];
vector<int> g[100100];
queue<qq> q;
int check( int mid )
{
    for( int i = 1 ; i <= n ; i++ )g[i].clear();
    memset( visit, -1, sizeof visit );
    for( int i = 1 ; i <= mid ; i++ ){
        g[day[i].a].push_back( day[i].b );
        g[day[i].b].push_back( day[i].a );
    }
    int ch = 0;
    for( int i = 1 ; i <= n ; i++ ){
        if( visit[i] == -1 ){
            q.push({ i , 1 });
            while( !q.empty() ){
                t = q.front();
                q.pop();
                visit[t.no] = t.co;
                for( int i = 0 ; i < g[t.no].size() ; i++ ){
                    if( visit[g[t.no][i]] == -1 ){
                        q.push({ g[t.no][i], t.co^1 });
                    }
                    else if( visit[g[t.no][i]] == t.co ){
                        ch = 1;
                        break;
                    }
                }
            }
        }
        if( ch == 1 )break;
    }
    return ch;
}
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 1 ; i <= m ; i++ ){
        scanf("%d %d",&day[i].a,&day[i].b);
    }
    int l = 1, r = m;
    while( l < r ){
        int mid = ( l + r + 1 ) / 2;
        if( check( mid ) )r = mid - 1;
        else l = mid;
    }
    printf("%d",l);
    return 0;
}
