#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 10;
map<string, int> ma;
int n;
string s[N];
 
 
int main() 
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ) cin >> s[i], ++ma[s[i]];
    int ans = 0;
    for( int i = 1 ; i <= n ; i++ ) {
        vector<string > v;
        int l = s[i].size();
        for( int leng = 1 ; leng <= l ; leng++ ) {
            for( int j = 0 ; j + leng - 1 < l ; j++ ) {
                string k = s[i].substr( j, leng );
                v.push_back( k );
            }
        }
        sort( v.begin(), v.end() );
        v.resize( unique( v.begin(), v.end() )-v.begin() );
        for( string k : v ) ans += ma[k];
    }
    printf("%d",ans-n);
    return 0;
}