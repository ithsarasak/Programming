#include<bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second 
using namespace std;

const int N = 2e5 + 10;
int tes, n;
int t[N], a[N], okpre[N], oksuf[N], chk[N];

void up( int x ) { for( int i = x ; i < N ; i += ( i & -i ) ) t[i] += 1; }
int query( int x ) {
    int ret = 0;
    for( int i = x ; i > 0 ; i -= i & -i ) ret += t[i];
    return ret;
}

int main()
{
    scanf("%d",&tes);
    while( tes-- ) {
        int mx = 0;
        memset( okpre, 0, sizeof okpre ), memset( oksuf, 0, sizeof oksuf );
        vector<pii> ans;
        scanf("%d",&n);
        for( int i = 1 ; i <= n ; i++ ) scanf("%d",&a[i]);
        memset( t, 0, sizeof t );
        memset( chk, 0, sizeof chk );
        for( int i = 1 ; i <= n ; i++ ) {
            mx = max( mx, a[i] );
            if( !chk[a[i]] ) {
                chk[a[i]] = 1;
                up( a[i] );
            }
            //printf("%d %d %d\n",mx,query(mx),a[i]);
            if( query( mx ) == i && mx == i ) okpre[i] = 1;
        }
        mx = 0;
        memset( chk, 0, sizeof chk );
        memset( t, 0, sizeof t );
        for( int i = n ; i >= 1 ; i-- ) {
            mx = max( mx, a[i] );
            if( !chk[a[i]] ) {
                chk[a[i]] = 1;
                up( a[i] );
            }
            if( query( mx ) == n - i + 1 && mx == n - i + 1 ) oksuf[i] = 1;
        }
        for( int i = 1 ; i <= n - 1 ; i++ ) {
            if( okpre[i] && oksuf[i+1] ) ans.emplace_back( i, n-i );
        }
        printf("%d\n",ans.size());
        for( pii i : ans ) printf("%d %d\n",i.x,i.y);
    }
    return 0;
}