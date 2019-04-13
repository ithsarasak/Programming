#include<bits/stdc++.h>

using namespace std;
vector<int> v, chk;
int n, ans;
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ){
        int a;
        scanf("%d",&a);
        v.push_back( a );
    }
    for( int i = 1 ; i <= ( n + 1 ) / 2 ; i++ ){
        chk.push_back( i );
        if( n-i+1 > i ) chk.push_back( n-i+1 );
    }
    for( auto j : chk ){
        int now = j, k = 0;
        for( ; k < v.size() ; k++ )if( now == v[k] ) break;
        if( k + 1 == now ) continue;
        ans++;
        v.erase( v.begin()+k );
        v.insert( v.begin()+now-1, now );
    }
    printf("%d",n-ans);
    return 0;
}

