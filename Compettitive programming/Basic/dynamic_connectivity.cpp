#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 3e5 + 10;

int dsu[N], n, k;
bool ask[N];
vector<pii> seg[4*N]; 
stack<pii> stk;
map<pii,int> mp;

int find( int now ) { return dsu[now] < 0 ? now : find( dsu[now] ); }

bool mer( int u, int v ) {
    int a = find( u ), b = find( v );
    if( a == b ) return false;
    if( abs( dsu[a] ) < abs( dsu[b] ) ) swap( a, b );
    stk.emplace( pii( a, dsu[a] ) ), stk.emplace( pii( b, dsu[b] ) );
    dsu[a] += dsu[b];
    dsu[b] = a;
    return true; 
}

void recall( int ver ) {
    while( stk.size() > ver ) {
        dsu[stk.top().x] = stk.top().y;
        stk.pop();
    }
}

void solve( int com, int l = 1, int r = k+1, int now = 1 ) {
    int ver = ( int )stk.size();
    for( pii i : seg[now] ) if( mer( i.x, i.y ) ) com--;
    //printf("L:%d R:%d\n",l,r);
    if( l != r ) {
        int mid = ( l + r ) >> 1;
        solve( com, l, mid, now << 1 );
        //printf("%d %d %d\n",l,r,mid);
        solve( com, mid + 1, r, now << 1 | 1 );
    } 
    else {
        //for( int i = 1 ; i <= k ; i++ ) if( ask[i] ) printf("%d ",i);
        //printf("\n");
       //printf("%d ", l);
       // if( ask[l] ) printf("%d\n",l);
        if( ask[l] ) printf("%d\n",com);
       // printf("\n");
    }
    recall( ver );
}
void update( int ll, int rr, pii va, int l = 1, int r = k + 1, int now = 1 ) {
    if( l > rr || r < ll ) return ;
    if( l >= ll && r <= rr ) return void( seg[now].emplace_back( va ) );
    int mid = ( l + r ) >> 1;
    update( ll, rr, va, l, mid, now << 1 ), update( ll, rr, va, mid + 1, r, now << 1 | 1 );
    return ;
}

int main()
{
    freopen("connect.in", "r", stdin);
    freopen("connect.out", "w", stdout);
    scanf("%d %d",&n,&k);
    memset( dsu, -1, sizeof dsu );
    for( int i = 1 ; i <= k ; i++ ) {
        char c;
        int a, b;
        scanf(" %c",&c);
        if( c == '+' ) {
            scanf("%d %d",&a,&b);
            if( a > b ) swap( a, b );
            mp[pii( a, b )] = i;
        }
        else if( c == '-' ) {
            scanf("%d %d",&a,&b);
            if( a > b ) swap( a, b );
            update( mp[pii( a, b )], i, pii( a, b ) );
            mp[pii( a, b )] = 0;
        }
        else ask[i] = true;
    }
    for( auto x : mp ) if( x.y ) {
        update( x.y, k + 1, x.x );
    }
    //for( int i = 1 ; i <= k ; i++ ) if( ask[i] ) printf("%d ",i);
    solve(n);
    return 0;
}