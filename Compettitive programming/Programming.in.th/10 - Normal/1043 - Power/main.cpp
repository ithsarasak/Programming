#include<stdio.h>
#include<math.h>

int root, factor[10010], count;
int n, i, num, j;
int gcd( int x, int y ){
    if( x % y == 0 ){
        return y;
    }
    return gcd( y , x % y );
}
int main()
{
    scanf("%d",&n);
    for( i = 0 ; i < n ; i++ ){
        for( j = 0 ; j < 10010 ; j++ ){
            factor[j] = 0;
        }
        count = 0;
        scanf("%d",&num);
        root = sqrt( num );
        for( j = 2 ; j <= root ; j++ ){
            if( num % j == 0 ){
                while( num % j == 0 ){
                    num /= j;
                    factor[count]++;
                }
                count++;
            }
        }
        if( num != 1 ){
            printf("NO\n");
            continue;
        }
        /*for( j = 0 ; j < count ; j++ ){
            printf("%d ",factor[j]);
        }
        printf("\n");*/
        int ans = factor[0];
        for( j = 1 ; j < count ; j++ ){
            ans = gcd( factor[j] , ans );
        }
        if( ans == 1 ){
            printf("NO\n");
        }
        else{
            printf("%d\n",ans);
        }
    }
    return 0;
}
