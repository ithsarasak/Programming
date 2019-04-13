#include<bits/stdc++.h>

using namespace std;
long long n, m, ma[1010][1010], ans = -1;
long long dp1[1010][1010], dp2[1010][1010], dp3[1010][1010], dp4[1010][1010];
int main()
{
    cin >> n >> m;
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= m ; j++ ){
            cin >> ma[i][j];
        }
    }
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= m ; j++ ){
            dp1[i][j] = ma[i][j] + max( dp1[i-1][j], dp1[i][j-1] );
        }
    }
    for( int i = n ; i >= 1 ; i-- ){
        for( int j = m ; j >= 1 ; j-- ){
            dp2[i][j] = ma[i][j] + max( dp2[i+1][j], dp2[i][j+1] );
        }
    }
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = m ; j >= 1 ; j-- ){
            dp3[i][j] = ma[i][j] + max( dp3[i-1][j], dp3[i][j+1] );
        }
    }
    for( int i = n ; i >= 1 ; i-- ){
        for( int j = 1 ; j <= m ; j++ ){
            dp4[i][j] = ma[i][j] + max( dp4[i+1][j], dp4[i][j-1] );
        }
    }

    for( int i = 2 ; i < n ; i++ ){
        for( int j = 2 ; j < m ; j++ ){
            long long temp = dp1[i][j-1]+dp2[i][j+1]+dp3[i-1][j]+dp4[i+1][j];
            long long temp2 = dp1[i-1][j]+dp2[i+1][j]+dp3[i][j+1]+dp4[i][j-1];
            ans = max( ans, max( temp, temp2 ) );
        }
    }
    cout << ans;
    return 0;
}
