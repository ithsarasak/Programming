#include<bits/stdc++.h>

using namespace std;
struct qq{
    int no, d;
}t;
int dis2[200100], cn[200100];
int n, k, qu, dis[200100], fen[200100];
vector<qq> g[200100];
queue<qq> q;
int cal( int f, int t )
{
    if( f > t )swap( f, t );
    int sum1 = 0, sum2 = 0;
    for( int i = t - 1 ; i > 0 ; i -= ( i & -i ) )sum1 += fen[i];
    for( int i = f - 1 ; i > 0 ; i -= ( i & -i ) )sum1 -= fen[i];
    for( int i = n ; i > 0 ; i -= ( i & -i ) )sum2 += fen[i];
    //printf("%d %d %d",sum1,sum2,sum3);
    return min( sum1, sum2 - sum1 );
}
int main()
{
    scanf("%d %d %d",&n,&k,&qu);
    memset( dis2, -1, sizeof dis2 );
    for( int i = 1 ; i <= k ; i++ ){
        scanf("%d",&dis[i]);
        for( int j = i ; j <= n ; j += ( j & -j ) ){
            fen[j] += dis[i];
        }
    }
    for( int i = k + 1 ; i <= n ; i++ ){
        int t, d;
        scanf("%d %d",&t,&d);
        g[i].push_back({ t, d });
        g[t].push_back({ i, d });
    }
    for( int i = 1 ; i <= k ; i++ ){
        if( dis2[i] == -1 ){
            q.push({ i, 0 });
            while( !q.empty() ){
                t = q.front();
                q.pop();
                dis2[t.no] = t.d;
                cn[t.no] = i;
                //printf("%d\n",t.no);
                for( int j = 0 ; j < g[t.no].size() ; j++ ){
                    if( dis2[g[t.no][j].no] == -1 )q.push({ g[t.no][j].no, t.d + g[t.no][j].d });
                }
            }
        }
    }
    while( qu-- ){
        int a, b, c;
        scanf("%d %d %d",&c,&a,&b);
        if( c == 0 ){
            for( int i = a ; i <= n ; i += ( i & -i ) ){
                fen[i] += b - dis[a];
            }
            dis[a] = b;
        }
        else{
            if( cn[a] == cn[b] )printf("%d\n",abs(dis2[a]-dis2[b]));
            else printf("%d\n",dis2[a]+dis2[b]+cal(cn[a],cn[b]));
        }
    }
    return 0;
}
