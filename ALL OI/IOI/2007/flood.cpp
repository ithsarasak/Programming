#include <bits/stdc++.h>
#define ppi pair<pair<int, int>, int>
#define pii pair<int, int>
#define x first
#define y second
 
using namespace std;
 
const int N = 1e5 + 10;
pii p[N];
vector<ppi> v;
vector<int> ans;
int n, w, f[2*N], t[2*N], chk[2*N][2], di[2*N][4], visit[2*N];
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ) scanf("%d %d",&p[i].x,&p[i].y);
    scanf("%d",&w);
    for( int i = 1 ; i <= w ; i++ ) {
        scanf("%d %d",&f[i],&t[i]);
        if( p[f[i]].x > p[t[i]].x || p[f[i]].y > p[t[i]].y ) swap( f[i], t[i] );
		if( p[f[i]].x == p[t[i]].x ) di[f[i]][3] = i, di[t[i]][1] = i;
		else di[f[i]][0] = i, di[t[i]][2] = i;
        v.emplace_back( ppi( pii( p[t[i]].x, -1*p[t[i]].y ), i ) );
    }
    sort( v.begin(), v.end(), greater<ppi>() );
    for( int i = 0 ; i < v.size() ; i++ ) {
        int wall = v[i].y; 
        if( visit[wall] ) continue;
        int now = f[wall], ty = p[f[wall]].y == p[t[wall]].y ? 2 : 1;
        vector<int> outside;
        while( 1 ) {
            int dir, to;
            for( int j = 0 ; j < 4 ; j++ ) {
                dir = ( ty + j + 3 ) % 4;
                to = di[now][dir];
                if( to > 0 && !visit[to] ) break; 
            }
            if( chk[to][dir/2] ) break;
            chk[to][dir/2] = 1;
            outside.emplace_back( to );
            ty = dir;
            if( now == f[to] ) now = t[to];
            else now = f[to];
        }
        for( int j = 0 ; j < outside.size() ; j++ ) visit[outside[j]] = 1;
    }
    for( int i = 1 ; i <= w ; i++ ) if( chk[i][0] > 0 && chk[i][1] > 0 ) ans.emplace_back( i );
    printf("%d\n",ans.size());
    for( int i = 0 ; i < ans.size() ; i++ ) printf("%d ",ans[i]);
    return 0;
}
