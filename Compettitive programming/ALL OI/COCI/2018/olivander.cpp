#include <bits/stdc++.h>

using namespace std;

int n, x[110], y[110];
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ) scanf("%d",&x[i]);
    for( int i = 0 ; i < n ; i++ ) scanf("%d",&y[i]);
    sort( x, x + n ), sort( y, y + n );
    for( int i = 0 ; i < n ; i++ ) {
        if( x[i] > y[i] ) return !printf("NE");
    }
    printf("DA");
    return 0;
}