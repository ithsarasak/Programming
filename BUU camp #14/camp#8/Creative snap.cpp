#include <bits/stdc++.h>

using namespace std;
int n, k;
long long a, b;
int pos[100100];
long long sol( int l, int r )
{
    int idx = lower_bound( pos + 1, pos + 1 + k, l ) - pos, idx2 = upper_bound( pos + 1, pos + 1 + k, r ) - pos;
    //printf("%d %d %d %d\n",l,r,idx,idx2);
    int hero = idx2 - idx, mid = ( l + r ) / 2;
    if( hero == 0 )return a;
    else{
        if( l == r )return b*hero;
        else return min( b*hero*(r-l+1), sol( l, mid ) + sol( mid + 1, r ) );
    }
}
int main()
{
    scanf("%lld %lld %lld %lld",&n,&k,&a,&b);
    for( int i = 1 ; i <= k ; i++ )scanf("%lld",&pos[i]);
    sort( pos + 1, pos + 1 + k );
    printf("%lld",sol( 1, 1<<n ));
    return 0;
}
