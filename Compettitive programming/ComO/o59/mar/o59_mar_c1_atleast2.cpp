#include <bits/stdc++.h>

using namespace std;

struct node {
    int va, l, r;
    node() {}
    node( int va, int l, int r ) : va( va ), l( l ), r( r ) {}
};

node 
int n, m;

void build( int l = 1, int r = n )  {

}
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 1 ; i <= n ; i++ ) {
        scanf("%f",&a[i]);
        coord.emplace_back( a[i] );
    }
    ver[0] = build();
    sort( coord.begin(), coord.end() );
    for( int i = 1 ; i <= n ; i++ ) ver[1] = update( get( a[i] ) );
    while( m-- ) {
        int s, t;
        double u;
        scanf("%d %d %f",&s,&t,&u);
    }
    return 0;
}