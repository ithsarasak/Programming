#include<bits/stdc++.h>

using namespace std;

struct A{
    long long mat[5][5];
    A operator*(const A&o)const{
        A temp;
        for( int i = 0 ; i < 4 ; i++ ){
            for( int j = 0 ; j < 4 ; j++ ){
                temp.mat[i][j] = 0;
                for( int k = 0 ; k < 4 ; k++ ){
                    temp.mat[i][j] += mat[i][k] * o.mat[k][j];
                    temp.mat[i][j] %= 10000019;
                }
            }
        }
        return temp;
    }
};
A mu;
A ans;
void kuay( long long n )
{
    if( n == 1 ){
        return ;
    }
    kuay( n / 2 );
    ans = ans * ans;
    if( n % 2 ){
        ans = ans * mu;
    }
    return ;
}
int main()
{

    int q;
    scanf("%d",&q);
    while( q-- ){
        mu.mat[0][0] = 0;
        mu.mat[0][1] = 0;
        mu.mat[0][2] = 1;
        mu.mat[0][3] = 0;
        mu.mat[1][0] = 1;
        mu.mat[1][1] = 0;
        mu.mat[1][2] = 1;
        mu.mat[1][3] = 0;
        mu.mat[2][0] = 0;
        mu.mat[2][1] = 0;
        mu.mat[2][2] = 0;
        mu.mat[2][3] = 1;
        mu.mat[3][0] = 0;
        mu.mat[3][1] = 1;
        mu.mat[3][2] = 0;
        mu.mat[3][3] = 0;
        ans = mu;
        long long n;
        scanf("%lld",&n);
        n -= 1;
        if( n == 0 ){
            printf("1 0 0 0\n");
            continue ;
        }
        kuay( n );
        for( int i = 0 ; i < 4 ; i++ ){
            printf("%lld ",ans.mat[i][0]);
        }
        printf("\n");
    }
    return 0;
}
