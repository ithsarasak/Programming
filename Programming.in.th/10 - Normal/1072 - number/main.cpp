#include<stdio.h>
int a[500001], i, j, amount, acom, help1[500001], help2[500001], t, pos1, pos2;
char command;
int main()
{
    scanf("%d %d",&amount,&acom);

    for( i = 1 ; i <= amount ; i++ ){
        scanf("%d",&a[i]);
    }
    for( i = 1 ; i <= acom ; i++ ){
        /*for( j = 1 ; j <= amount ; j++ ){
            printf(" %d",a[j]);
        }
        printf("\n");*/
        scanf(" %c",&command);

        if( command == 'a' ){
            scanf("%d %d",&pos1,&pos2);

            if( pos1 != pos2 ){
                t = a[pos1];
                a[pos1] = a[pos2];
                a[pos2] = t;
            }
        }
        else if( command == 'b' ){
            scanf("%d %d",&pos1,&pos2);

            a[pos1] = pos2;
        }
        else if( command == 'c' ){
            scanf("%d",&pos1);

            for( j = 1 ; j <= pos1 ; j++ ){
                help1[j-1] = a[j];
            }
            for( j = pos1 + 1 ; j <= amount ; j++ ){
                help2[j-pos1-1] = a[j];
            }
            for( j = 1 ; j <= pos1 ; j++ ){
                a[j] = help1[pos1-1-j+1];
            }
            for( j = pos1 + 1 ; j <= amount ; j++ ){
                a[j] = help2[amount-j];
            }
        }
        else{
            scanf("%d",&pos1);

            printf("%d\n",a[pos1]);
        }
    }
    return 0;
}
