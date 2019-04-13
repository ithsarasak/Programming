#include<bits/stdc++.h>

using namespace std;
int n, k;
int segmi[400100], segmx[400100], dvd[100100];
void build( int l, int r, int now )
{
    if( l == r ){
        segmi[now] = l;
        segmx[now] = l;
        return ;
    }
    int mid = ( l + r ) / 2;
    build( l, mid, now * 2 );
    build( mid + 1, r, now * 2 + 1 );
    segmi[now] = min( segmi[now*2], segmi[now*2+1] );
    segmx[now] = max( segmx[now*2], segmx[now*2+1] );
    return ;
}
void up( int l,int r, int idx, int now, int va )
{
    if( l > idx || r < idx || l > r )return ;
    if( l == r ){
        segmi[now] = va;
        segmx[now] = va;
        return;
    }
    int mid = ( l + r ) / 2;
    up( l, mid, idx, now * 2, va );
    up( mid + 1, r, idx, now * 2 + 1, va );
    segmi[now] = min( segmi[now*2], segmi[now*2+1] );
    segmx[now] = max( segmx[now*2], segmx[now*2+1] );
    return ;
}
int query( int l, int r, int ll, int rr, int now )
{
    if( l > rr || r < ll || l > r )return 1e9;
    if( l >= ll && r <= rr )return segmi[now];
    int mid = ( l + r ) / 2;
    return min( query( l, mid, ll, rr, now*2 ), query( mid + 1, r, ll, rr, now * 2 + 1 ) );
}
int query2( int l, int r, int ll, int rr, int now )
{
    if( l > rr || r < ll || l > r )return -1e9;
    if( l >= ll && r <= rr )return segmx[now];
    int mid = ( l + r ) / 2;
    return max( query2( l, mid, ll, rr, now*2 ), query2( mid + 1, r, ll, rr, now * 2 + 1 ) );
}
int main()
{
    for( int i = 1 ; i <= 100000 ; i++ )dvd[i] = i;
    scanf("%d %d",&n,&k);
    build( 1, n, 1 );
    //printf("%d %d\n",segmi[1],segmx[1]);
    while( k-- ){
        int c;
        scanf("%d",&c);
        if( c ){
            int f, t;
            scanf("%d %d",&f,&t);
            f++, t++;
            int mi = query( 1, n, f, t, 1 );
            int mx = query2( 1, n, f, t, 1 );
            //printf("%d %d\n",mi,mx);
            if( f == mi && t == mx )printf("YES\n");
            else printf("NO\n");
        }
        else{
            int a, b;
            scanf("%d %d",&a,&b);
            a++, b++;
            up( 1, n, a, 1, dvd[b] );
            up( 1, n, b, 1, dvd[a] );
            swap( dvd[a], dvd[b] );
        }
    }
    return 0;
}
