#include<bits/stdc++.h>

using namespace std;

struct walk{
    int sum , curnode;
    bool operator<( const walk &k )const{
        return sum > k.sum;
    }
}t;
struct point{
    int a, b;
}allpoint[10010];
priority_queue<walk> q;
vector<point> graph[10010];
int n, m, k, st, en, c, visit[10010], dis[10010];
char maps[10010][10010];
int main()
{
    scanf("%d %d %d",&n,&m,&k);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%s",maps[i] + 1);
    }
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= m ; j++ ){
            if( maps[i][j] != '.' ){
                allpoint[c].a = i;
                allpoint[c].b = j;
                if( maps[i][j] == 'A' ){
                    st = c;
                }
                else if( maps[i][j] == 'B' ){
                    en = c;
                }
                c++;

            }
        }
    }
    //printf("%d %d %d %d\n",allpoint[st].a,allpoint[st].b,allpoint[en].a,allpoint[en].b);
    for( int i = 0 ; i < c ; i++ ){
        for( int j = i + 1 ; j < c ; j++ ){
            if( abs( allpoint[i].a - allpoint[j].a ) + abs( allpoint[i].b - allpoint[j].b ) <= k ){
                graph[i].push_back({ j, abs( allpoint[i].a - allpoint[j].a ) + abs( allpoint[i].b - allpoint[j].b ) });
                graph[j].push_back({ i, abs( allpoint[i].a - allpoint[j].a ) + abs( allpoint[i].b - allpoint[j].b ) });
            }
        }
    }
    q.push({ 0 , st });
    while( !q.empty() ){
        t = q.top();
        q.pop();
        if(visit[t.curnode])   continue;
        visit[t.curnode] = 1;
        if(t.curnode == en){
            printf("%d\n",t.sum);
            return 0;
        }
        for( int i = 0 ; i < graph[t.curnode].size() ; i++ ){
            q.push({ t.sum + graph[t.curnode][i].b , graph[t.curnode][i].a });
        }
    }
    printf("-1");
    return 0;
}
