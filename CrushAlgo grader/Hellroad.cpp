#include<bits/stdc++.h>

using namespace std;
struct ee{
    int f, t;
    long long d;
    bool operator<( const ee &k )const{
        return d < k.d;
    }
};
vector<ee> v;
int n;
int par[1010];
long long k;
int findroot( int num )
{
    if( par[num] == num )return num;
    else return par[num] = findroot( par[num] );
}
int cost( int mid )
{
    long long path = 0;
    for( int i = 1 ; i <= n ; i++ )par[i] = i;
    for( int i = mid ; i <= v.size() - 1 ; i++ ){
        int a = findroot( v[i].f );
        int b = findroot( v[i].t );
        if( a != b ){
            par[a] = b;
            path += v[i].d;
        }
    }
    int cc = findroot( 1 ), ch = 0;
    for( int i = 2 ; i <= n ; i++ ){
        if( cc != findroot( i ) ){
            ch = 1;
            break;
        }
    }
    if( ch || path > k )return 0;
    else return 1;
}
int main()
{
    scanf("%d %lld",&n,&k);
    for( int i = 0 ; i < (n*(n-1))/2 ; i++ ){
        int f, t;
        long long d;
        scanf("%d %d %lld",&f,&t,&d);
        v.push_back({ f, t, d });
    }
    sort( v.begin(), v.end() );
    //for( int i = 0 ; i < v.size() ; i++ )printf("%lld ",v[i].d);
    int l = 0, r = v.size() - 1;
    while( l < r ){
        int mid = ( l + r + 1 ) / 2;
        if( cost( mid ) )l = mid;
        else r = mid - 1;
    }
    long long path = 1e9;
    for( int i = 1 ; i <= n ; i++ )par[i] = i;
    for( int i = l ; i <= v.size()-1 ; i++ ){
        int a = findroot( v[i].f );
        int b = findroot( v[i].t );
        if( a != b ){
            par[a] = b;
            path = min( path,v[i].d );
        }
    }
    printf("%lld",path);
    return 0;
}
