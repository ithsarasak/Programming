#include <bits/stdc++.h>
 
using namespace std;
string s[5];
int m;  
int main() {
 
    for ( int i = 0 ; i < 2 ; i++ ){
        cin >> s[i];
        m = s[i].length();
    }
    int ans = 0;
    int empty = 0;
    for ( int i = 0 ; i < m ; i++ ){
        int current = ( s[0][i] == '0' ) + ( s[1][i] == '0' );
        empty += current;
        if( empty >= 3 ) {
            empty -= 3;
            ans++;
        }
        else
            empty = current;
    }
    cout << ans;
}