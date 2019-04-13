#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+100;

int fw[N], mark[N], n, nex;

void up( int idx, int va ) { for( int i = idx ; i < N ; i += ( i & -i ) ) fw[i] += va; }

int query( int idx ) {
    int sum = 0;
    for( int i = idx ; i > 0 ; i -= ( i & -i ) ) sum += fw[i];
    return sum;
}

int main()
{
    scanf("%d %d",&n,&nex);
    for( int i = 1 ; i <=n ; i++ ) up( i, 1 );
    for( int i = 1 ; i <= n - 1 ; i++ ) {
        int l = 1, r = n;
        while( l < r ){
            int mid = ( l + r ) >> 1;
            if( query( mid ) < nex ) l = mid + 1;
            else r = mid;
        }
        nex = ( l + query( l ) - 1 ) % ( n - i );
        if( !nex ) nex = n - i;
        up( l, -1 );
        mark[l] = 1;
    }
    for( int i = 1 ; i <= n ; i++ ) if( !mark[i] ){
        printf("%d\n",i);
        break;
    }
    return 0;
}
