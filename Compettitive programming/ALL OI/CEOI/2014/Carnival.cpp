#include <bits/stdc++.h>

using namespace std;

const int N = 200;
int n, c, mark[N];
vector<int> all;
int ask( vector<int> v ) {
    int ret;
    printf("%d ",v.size() );
    for( int i = 0 ; i < ( int )v.size() - 1 ; i++ ) printf("%d ",v[i]);
    printf("%d\n",v[(int)v.size()-1]);
    fflush( stdout );
    scanf("%d",&ret);
    return ret;
}

void process( int l, int r, int nu ) {
    //printf("L : %d R : %d\n",l,r);
    if( l == r ) {
        vector<int> t;
        t.emplace_back( all[l] ), t.emplace_back( nu );
        if( ask( t ) == 1 ) mark[all[l]] = c; 
        return ;
    }
    int mid = ( l + r ) >> 1;
    vector<int> v, v2;
    for( int i = l ; i <= mid ; i++ ) v.emplace_back( all[i] );
    for( int i = mid+1 ; i <= r ; i++ ) v2.emplace_back( all[i] );
    int a = ask( v ), b = ask( v2 );
    v.emplace_back( nu ), v2.emplace_back( nu );
    int c = ask( v ), d = ask( v2 );
    //printf("%d %d %d %d\n",a,b,c,d);
    if( c == 1 ) for( int i = 0 ; i < v.size() ; i++ ) mark[v[i]] = mark[nu];
    if( d == 1 ) for( int i = 0 ; i < v2.size() ; i++ ) mark[v2[i]] = mark[nu];
    if( a == c && c != 1 ) process( l, mid, nu );
    if( b == d && d != 1 ) process( mid + 1, r, nu );
}

int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ) all.emplace_back( i );
    for( int i = 1 ; i <= n ; i++ ) if( !mark[i] ) {
        ++c;
        all.erase( all.begin() );
        mark[i] = c;
        int x = all.size();
        if( x == 0 ) break;
        process( 0, x-1, i );
        all.clear();
        for( int j = 1 ; j <= n ; j++ ) if( !mark[j] ) all.emplace_back( j );
        //printf("END\n");
    }
    printf("0 ");
    for( int i = 1 ; i <= n ; i++ ) printf("%d ",mark[i]);
    return 0;
}