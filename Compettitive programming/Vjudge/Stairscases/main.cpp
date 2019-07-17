#include<bits/stdc++.h>
const int MAXN = 500 + 10 ;
unsigned long long DP[MAXN][MAXN];


using namespace std ;
int main(){
    int n ;
    cin >> n ;

    DP[0][0] = 1ll ;

    for(int i = 1 ; i <= n ; i ++)
        for(int j = 1 ; j <= i ; j ++){
            for(int k = 0 ; k < j && k <= i-j ; k ++)
                DP[i][j] +=DP[i-j][k];
        }

    unsigned long long sum = 0ll;

    for(int i = 1 ; i < n ; i ++)
        sum += DP[n][i];
    cout << sum ;
}
