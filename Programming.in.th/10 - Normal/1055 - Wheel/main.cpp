#include<stdio.h>
int n, k;
int i, j, wheel[110], dice[110], player[25], count;
int main()
{
    scanf("%d %d",&n,&k);
    for( i = 1 ; i <= n ; i++ ){
        scanf("%d",&wheel[i]);
    }
    for( i = 1 ; i <= n ; i++ ){
        scanf("%d",&dice[i]);
    }
    j = 1;
    for( i = 1 ; i <= n ; i++ ){
        count = 0;
        while( 1 ){
            if( wheel[j] != 0 ){
                count++;
            }
            if( count == dice[i] + 1 ){
                    //printf(" j : %d\n",j);
                player[( i - 1 ) % k] += wheel[j];
                wheel[j] = 0;
                break;
            }
            j++;
            if( j == n + 1 ){
                j = 1;
            }
        }
        j += 1;
        if( j == n + 1 ){
            j = 1;
        }
    }
    for( i = 0 ; i < k ; i++ ){
        printf("%d\n",player[i]);
    }
    return 0;
}
