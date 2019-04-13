#include<bits/stdc++.h>

using namespace std;

int q, k, ma, pos;
string w, ans;

int main()
{
    scanf("%d",&q);
    while( q-- ){
        unordered_map<string,int> mark;
        ma = 1;
        scanf("%d",&k);
        cin >> w ;
        int len = w.length();
        for( int i = 0 ; i <= len - k ; i++ ){
            string te = w.substr( i, k );
            mark[te]++;
        }
        for( int i = 0 ; i <= len - k ; i++ ){
            string te = w.substr( i, k );
            if( mark[te] > ma ){
                ma = mark[te];
                ans = te;
            }
        }
        if( ma == 1 ){
            cout << w.substr( 0, k );
        }
        else{
            cout << ans << endl;
        }
    }
    return 0;
}
