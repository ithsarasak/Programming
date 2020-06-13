#include <bits/stdc++.h>
#include "trilib.h"

using namespace std;

/*int is_clockwise( int a, int b, int c ) {
    printf("ASK %d %d %d\n",a,b,c);
    int x;
    scanf("%d",&x);
    return x;
}*/

void buildhull( vector<int> &v ) {
    vector<int> ans;
    for( int x : v ) {
        while( ans.size() > 1 && !is_clockwise( ans[(int)ans.size()-2], ans.back(), x ) ) ans.pop_back();
        ans.emplace_back( x );
    }
    v = ans;
}

int main()
{
    int n;
    n = get_n();
    //scanf("%d",&n);
    vector<int> l, r;
    for( int i = 3 ; i <= n ; i++ ) {
        if( !is_clockwise( 1, 2, i ) ) l.emplace_back( i );
        else r.emplace_back( i );
    }
    sort( l.begin(), l.end(), [&]( const int &a, const int &b ){
        return is_clockwise( 1, a, b );
    });
    sort( r.begin(), r.end(), [&]( const int &a, const int &b ){
        return is_clockwise( 1, a, b );
    });
    l.emplace_back( 2 ), r.emplace_back( 1 );
    /*for( int i : l ) printf("%d ",i);
    printf("\n");
    for( int i : r ) printf("%d ",i);
    printf("\n");*/
    buildhull( l ), buildhull( r );
    for( int x : r ) l.emplace_back( x );
    buildhull( l );
    bool check = true;
    deque<int> L( l.begin(), l.end() );
    while( check ) {
        check = false;
        if( is_clockwise( L[(int)L.size()-2], L[0], L.back() ) ) L.pop_back(), check = true;
        if( is_clockwise( L.back(), L[1], L[0] ) ) L.pop_front(), check = true;
    }
    give_answer( L.size() );
    return 0;
}