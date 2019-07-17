#include<bits/stdc++.h>

using namespace std;
string ans = "UUDDLRLRBAS";
string input;
int now;
int main()
{
    cin >> input;
    int l = input.length();
    for( int i = max( 0, l - 11 ) ; i < l ; i++ ){
        string tt = input.substr( i, ( l - i ) );
        int l2 = tt.length();
        string tt2 = ans.substr( 0, l2 );
        if( tt == tt2 ){
            now = l2;
            break;
        }
    }
    for( int i = now ; i < 11 ; i++ )cout << ans[i];
    return 0;
}
