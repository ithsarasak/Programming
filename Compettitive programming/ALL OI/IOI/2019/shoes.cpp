#include <bits/stdc++.h>
#include "shoes.h"
#define pii pair<int, int>
#define x first
#define y second 

using namespace std;

const int N = 1e5 + 10;
vector<int> vec[2*N];
int n, arr[2*N], sz;
long long ans, fen[2*N];

long long query( int x ) {
    long long ret = 0;
    for( int i = x ; i > 0 ; i -= i & -i ) ret += fen[i];
    return ret;
}

void up( int x ) {
    for( int i = x ; i < 2*N ; i += i & -i ) fen[i] += 1;
}

long long count_swaps( vector<int> s ) {
    n = s.size() / 2;
    sz = s.size();
    for( int i = 0 ; i < sz ; i++ ) vec[s[i]+N].emplace_back( i );
    memset( arr, -1, sizeof arr );
    for( int i = sz - 1 ; i >= 0 ; i-- ) {
        if( arr[i] != -1 ) continue ;
        vec[s[i]+N].pop_back();
        int pos = vec[-1*s[i]+N].back(); vec[-1*s[i]+N].pop_back();
        if( s[i] < 0 ) arr[i] = n*2-1, arr[pos] = n*2;
        else arr[i] = n*2, arr[pos] = n*2-1;
        n--;
        //printf("%d %d %d %d\n",i,s[i],pos,s[pos]);
    }
    /*for( int i = 0 ; i < sz ; i++ ) printf("%d ",arr[i]);
    printf("\n");*/
    for( int i = sz-1 ; i >= 0 ; i-- ) {
        //printf("%d ",arr[i]);
        ans += query( arr[i] ), up( arr[i] );
    }
    return ans;
}

/*int main()
{
    int ne;
    vector<int> vec;
    scanf("%d",&ne);
    for( int i = 0, a ; i < ne ; i++ ) {
        scanf("%d",&a);
        vec.emplace_back( a );
    }
    printf("%lld",count_swaps( vec ) );
}*/