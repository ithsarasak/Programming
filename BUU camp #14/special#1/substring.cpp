#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
int n, q;
map<string, int> m;
string s, w[N], se;

int main()
{
    ios_base::sync_with_stdio( false ), cin.tie( NULL );
    cin >> n;
    for( int i = 1 ; i <= n ; i++ ) {
        cin >> se;
        int len = se.length();
        //printf("%d %d %d\n",i,n,len);
        for( int j = 0 ; j < len ; j++ ) {
            s += w[i][j];
            m[s]++;
        }
        s = "";
        w[i] = se;
        // for( int j = 1 ; j <= i ; j++ ) cout << w[i] << endl;
    }
    cin >> q;
    //printf("%d\n",q);
    int cnt = n + 1;
    while( q-- ) {
        int op; 
        //printf("hhh");
        cin >> op;
        if( op == 1 ) {
            cin >> se;
            int len = se.length();
            for( int j = 0 ; j < len ; j++ ) {
                s += se[j];
                m[s]++;
            }
            w[cnt] = se;
            cnt++;
            s = "";
            //cout << w[cnt-1] << endl;
        }
        else {
            int x;
            cin >> x;
            // cout << w[x] << endl;
            cout << m[w[x]] << endl;
        }
    }
    return 0;
}