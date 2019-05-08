#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long t, st[3] = { 14,15,63 };
struct A{
    long long mat[4][4];
    A operator*(const A &o){
        A temp;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                temp.mat[i][j] = 0;
                for(int k=0;k<3;k++){
                    temp.mat[i][j] += mat[i][k] * o.mat[k][j];
                    temp.mat[i][j] %= mod;
                    temp.mat[i][j] += mod;
                    temp.mat[i][j] %= mod;
                }
            }
        }
        return temp;
    }
};
A start, temp;
void mul( long long n )
{
    if( n == 1 ) return ;
    mul( n / 2 );
    temp = temp * temp;
    if( n % 2 ) temp = temp * start;
    return ;
}
int main()
{
    scanf("%lld",&t);
    for( int z = 1 ; z <= t ; z++ ){
        long long a;
        scanf("%lld",&a);
        start.mat[0][0] = 0;
        start.mat[0][1] = 1;
        start.mat[0][2] = 0;
        start.mat[1][0] = 0;
        start.mat[1][1] = 0;
        start.mat[1][2] = 1;
        start.mat[2][0] = 6;
        start.mat[2][1] = 5;
        start.mat[2][2] = -2;

        temp = start;
        if( a == 0 ){
            printf("Case #%d: 14\n",z);
            continue;
        }
        else if( a == 1 ){
            printf("Case #%d: 15\n",z);
            continue;
        }
        else if( a == 2 ){
            printf("Case #%d: 63\n",z);
            continue;
        }
        a -= 2;
        mul( a );
        long long ans = 0;
        for( int j = 0 ; j < 3 ; j++ ){
            ans += st[j] * temp.mat[2][j];
            ans %= mod;
            ans += mod;
            ans %= mod;
        }
        printf("Case #%d: %lld\n",z,ans);
    }
    return 0;
}
