#include<bits/stdc++.h>

using namespace std;
long long n, mat[10][10];
long long cal( int si, long long mat[][10] )
{
    if( si == 2 ){
        return (mat[0][0]*mat[1][1])-(mat[1][0]*mat[0][1]);
    }
    else if( si == 3 ){
        return (mat[0][0]*mat[1][1]*mat[2][2])+(mat[0][1]*mat[1][2]*mat[2][0])+(mat[0][2]*mat[1][0]*mat[2][1])-(mat[2][0]*mat[1][1]*mat[0][2])-(mat[2][1]*mat[1][2]*mat[0][0])-(mat[2][2]*mat[1][0]*mat[0][1] );
    }
    else{
        long long mat2[10][10], w = 0;
        long long sum = 0;
        for( int k = 0 ; k < si ; k++ ){
            for( int i = 1 ; i < n ; i++ ){
                w = 0;
                for( int j = 0 ; j < n ; j++ ){
                    if( j == k )continue;
                    mat2[i-1][w] = mat[i][j];
                    w++;
                }
            }
            if( k % 2 == 0 ) sum += mat[0][k]*cal( si-1, mat2 );
            else sum -= mat[0][k]*cal( si-1, mat2 );
        }
        return sum;
    }
}
int main()
{
    scanf("%lld",&n);
    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < n ; j++ ){
            scanf("%lld",&mat[i][j]);
        }
    }
    if( n == 1 ){
        printf("%d",mat[0][0]);
        return 0;
    }
    printf("%lld",cal( n, mat ));
}
