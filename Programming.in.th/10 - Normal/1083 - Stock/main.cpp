#include<stdio.h>

int day, f[1000001], stock[1000001], i, startd, endd, time, num, j;
int main()
{
    scanf("%d",&day);

    for( j = 1 ; j <= day ; j++ ){
        scanf("%d",&stock[j]);
        if( j == 1 ){
            f[j] = 0;
        }
        else{
            if( f[j-1] + ( stock[j] - stock[j-1] ) > f[j-1] ){
                f[j] = f[j-1] + ( stock[j] - stock[j-1] );
                //printf("Add f[num] : %ld\n",f[num]);
            }
            else{
                f[j] = f[j-1];
                //printf("NO f[num] : %ld\n",f[num]);
            }
        }
    }
    scanf("%d",&time);
    /*for( j = 1 ; j <= day ; j++ ){
        printf("%d ",f[j]);
    }
    printf("\n");*/

    for( i = 0 ; i < time ; i++ ){
        num = 0;
        scanf("%d %d",&startd,&endd);

        printf("%d\n",f[endd]-f[startd]);
    }
    return 0;
}
