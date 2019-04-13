#include<bits/stdc++.h>
#define mod 997
using namespace std;
struct mm{
    int mat[2][2];
    mm operator*( const mm &o ){
        mm temp;
        for( int i = 0 ; i < 2 ; i++ ){
            for( int j = 0 ; j < 2 ; j++ ){
                temp.mat[i][j] =0;
                for( int k = 0 ; k < 2 ; k++ ){
                    temp.mat[i][j] += mat[i][k] * o.mat[k][j];
                    temp.mat[i][j] += mod;
                    temp.mat[i][j] %= mod;
                }
            }
        }
        return temp;
    }
};
mm start, temp;
int q, ori[2] = { 2, 3 };
void mul( int a )
{
    if( a == 1 )return ;
    mul( a / 2 );
    temp = temp * temp;
    if( a % 2 == 1 )temp = temp * start;
}
int main()
{
    scanf("%d",&q);
    start.mat[0][0] = 3;
    start.mat[0][1] = 4;
    start.mat[1][0] = 1;
    start.mat[1][1] = 0;
    while( q-- ){
        int a;
        temp = start;
        scanf("%d",&a);
        if( a == 0 ){
            printf("3 ");
            continue;
        }
        else if( a == 1 ){
            printf("2 ");
            continue;
        }
        a -= 1;
        mul( a );
        int sum = 0;
        /*for( int i = 0 ; i < 2 ; i++ ){
            for( int j = 0 ; j < 2 ; j++ ){
                printf("%d ",temp.mat[i][j]);
            }
            printf("\n");
        }*/
        for( int i = 0 ; i < 2 ; i++ ){
            sum += ori[i] * temp.mat[0][i];
            sum %= mod;
        }
        printf("%d ",sum);
    }
    return 0;
}
