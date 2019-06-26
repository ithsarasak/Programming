#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
int n, shout[N], fen[N];
vector<int> ans;

void up( int idx, int va ) { for( int i = idx ; i < N ; i += ( i & -i ) ) fen[i] += va; }

int query( int idx ) {
    int ret = 0;
    for( int i = idx ; i > 0 ; i -= ( i & -i ) ) ret += fen[i];
    return ret;
}

int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ) up( i, 1 );
    for( int i = 1 ; i <= n ; i++ ) scanf("%d",&shout[i]);
    for( int i = n ; i >= 1 ; i-- ) {
        int l = 1, r = n, can = query( n ) - shout[i];
        while( l < r ) {
            int mid = ( l + r ) >> 1;
            int qq = query( mid );
            if( qq >= can ) r = mid;
            else l = mid + 1;
        }
        ans.emplace_back( l );
        up( l, -1 );
    }
    for( int i = ( int )ans.size() - 1 ; i >= 0 ; i-- ) printf("%d ",ans[i]);
    return 0;
}