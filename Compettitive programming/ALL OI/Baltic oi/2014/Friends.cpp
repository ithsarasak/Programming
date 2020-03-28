#include <bits/stdc++.h>

using namespace std;

string t;
int n;

int process( int k ) {
    string l, r;
    for( int i = 0 ; i < k ; i++ ) l += t[i];
    for( int i = k ; i < n ; i++ ) r += t[i];
    int p1 = 0, p2 = 0, len1 = l.length(), len2 = r.length();
    //cout << l << " " << r << " " << len1 << " " << len2 << endl;
    while( p1 < len1 && p2 < len2 && l[p1] == r[p2] ) {
        p1++, p2++;
    } 
    if( p1 == len1 ) return len1 + p2;
    else if( p2 == len2 ) return p1;
    int now;
    if( k == n/2 ) { 
        now = len1 + p2;
        p2++;
    }
    else {
        now = p1;
        p1++;
    }
    //printf("%d %d\n",p1,p2);
    for( ; p1 < len1 && p2 < len2 ; p1++, p2++ ) {
        //cout << l[p1] << " " << r[p2] << endl;
        if( l[p1] != r[p2] ) return -1; 
    }
    return now;
}

int check() {
    for( int i = 0 ; i < n - 1 ; i++ ) {
        if( t[i] != t[i+1] ) return 0;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
    cin >> n >> t;
    if( n % 2 == 0 ) return !printf("NOT POSSIBLE");
    char a = t[0], b = t[1];
    int chk = 1;
    if( check() ) {
        for( int i = 0 ; i < n / 2 ; i ++ ) cout << t[i];
        return 0;
    }
    /*for( int i = 2 ; i < n ; i++ ) {
        if( i % 2 == 0 && t[i] != a ) chk = 0;
        else if( i % 2 && t[i] != b ) chk = 0; 
    }
    if( chk ) return !printf("NOT UNIQUE");*/
    int x = process( n/2 ), y = process( n/2 + 1 );
    //printf("%d %d\n",x,y);
    if( x != -1 && y != -1 && x != y ) return !printf("NOT UNIQUE");
    if( x != -1 ) {
        //printf("%d\n",x);
        int cnt = 0;
        for( int i = 0 ; cnt < n/2 ; i++ ) {
            if( i == x ) continue ;
            cout << t[i];
            cnt++;
        }
        return 0;
    } 
    else if( y != -1 ) {
        //printf("%d\n",y);
        int cnt = 0;
        for( int i = 0 ; cnt < n/2 ; i++ ) {
            if( i == y ) continue ;
            cout << t[i];
            cnt++;
        }
        return 0;
    } 
    printf("NOT POSSIBLE");
    return 0;
}