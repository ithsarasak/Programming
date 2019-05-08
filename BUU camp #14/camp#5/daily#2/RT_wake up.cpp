#include<bits/stdc++.h>

using namespace std;

struct pp{
    int x, y;
}po[15010];
int n;
int mark[15010];
priority_queue<int> pq;
int main()
{
    scanf("%d",&n);
    scanf("%d %d %d",&p,&s,&o);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d %d",&po[i].x,&po[i].y);
    }
    pq.push( s );
    while( !pq.empty() ){
        int t = pq.top();
        for( int i = 1 ; i <= n ; i++ ){
            if( t != i ){
                pq.push( i );
            }
        }
    }
}
