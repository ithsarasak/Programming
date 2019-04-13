#include<bits/stdc++.h>

using namespace std;
string num1, num2;
long long compute[200100], sum[200100];
int n, m;
long long ans;
const int mod = 998244353;
int main()
{
    compute[0] = 1;
    for( int i = 1 ; i <= 200000 ; i++ ){
        compute[i] = compute[i-1] * 2;
        compute[i] %= mod;
    }
    //ios::sync_with_stdio( false );
    scanf("%d %d",&n,&m);
    cin >> num1;
    cin >> num2;

    reverse( num1.begin(), num1.end() );
    reverse( num2.begin(), num2.end() );
    sum[0] = num1[0] - '0';
    while( n < m ){
        num1 += '0';
        n++;
    }
    for( int i = 1 ; i < n ; i++ ){
        sum[i] = sum[i-1] + compute[i]*( num1[i]-'0' );
        sum[i] %= mod;
    }
    for( int i = 0 ; i < m ; i++ ){
        ans += sum[i] * ( num2[i] - '0' );
        ans %= ( long long )mod;
    }
    cout << ans;
    return 0;
}
