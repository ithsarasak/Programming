#include <stdio.h>
long long id[100], i, j, k, amount, pair;
int main()
{
    scanf("%d",&amount);

    for( i = 0 ; i < amount ; i++ ){
        int ids;
        scanf("%d",&ids);
        id[ids]++;
    }
    for( i = 0 ; i < 100 ; i++ ){
        for( j = i ; j < 100 ; j++ ){
            if( id[i] > 0 && id[j] > 0 ){
                if( i == j ){
                    if( id[i] > 1 ){
                        for( k = 1 ; k < id[i] ; k++ ){
                            pair += k;
                        }
                    }
                }
                else{
                    int help1 = i / 10 , help2 = j / 10;
                    int help3 = ( i - ( 10 * help1 ) ) , help4 = ( j - ( 10 * help2 ) );

                    if( help1 == help2 ){
                        pair += id[i] * id[j];
                    }
                    else if( help3 == help4 ){
                        pair += id[i] * id[j];
                    }
                }
            }
        }
    }
    printf("%lld",pair);

    return 0;
}
