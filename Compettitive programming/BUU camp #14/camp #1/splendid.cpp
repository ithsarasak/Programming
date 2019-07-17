#include<bits/stdc++.h>

using namespace std;

const int mod = 1e7 + 19;
struct Matrix{
    long long a[2][2];
    Matrix operator*( const Matrix &o ){
        Matrix tmp;
        for( int i = 0 ; i < 2 ; i++ ){
            for( int j = 0 ; j < 2 ; j++ ){
                tmp.a[i][j] = 0;
                for( int k = 0 ; k < 2 ; k++ ){
                    tmp.a[i][j] += a[i][k]*o.a[k][j];
                    tmp.a[i][j] %= mod;
                }
            }
        }
        return tmp;
    }
};
Matrix Fib = { 1 , 1,
               1 , 0 };
Matrix ans;
void power( long long n )
{
    if( n == 1 ){
        ans = Fib;
        return ;
    }
    power( n / 2 );
    ans = ans * ans;
    if( n % 2 )ans = ans * Fib;
    return ;
}
int main()
{
    int q;
    scanf("%d",&q);
    while( q-- ){
        long long n;
        cin >> n;
        power( n + 1 );
        printf("%lld\n",ans.a[1][1]);
    }
    return 0;
}
