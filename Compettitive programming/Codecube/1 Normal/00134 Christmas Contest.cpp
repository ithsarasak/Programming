#include<bits/stdc++.h>

using namespace std;
int n, m;
int a[100100], tran[31];
int b[2][31];
long long sum;
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    for( int i = 0 ; i < m ; i++ ){
        int num;
        scanf("%d",&num);
        for( int j = 0 ; j < 31 ; j++ ){
            b[num%2][j]++;
            num /= 2;
        }
    }
    /*for( int i = 0 ; i < 2 ; i++ ){
        for( int j = 0 ; j <= 10 ; j++ ){
            printf("%d",b[i][j]);
        }
        printf("\n");
    }*/
    for( int i = 0 ; i < n ; i++ ){
        memset( tran, 0, sizeof tran );
        int nu = a[i], h = 1;
        tran[0] = nu % 2;
        nu /= 2;
        while( nu > 0 ){
            tran[h] = nu % 2;
            nu /= 2;
            h++;
        }
        for( int j = 0 ; j < 31 ; j++ ){
            sum += ( long long )b[1^tran[j]][j] * ( long long )( 1 << j );
        }
    }
    printf("%lld",sum);
    return 0;
}
