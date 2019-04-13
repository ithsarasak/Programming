#include<stdio.h>
int m, n, l, i;
int j[1010],k[1010];
struct node{
    int day, min;
}temp, temp1, temp2;
struct node work[1010][1010];
int main()
{
    scanf("%d %d",&m,&n);
    for( i = 0 ; i < n ; i++ ){
        scanf("%d",&j[i]);
    }
    for( i = 0 ; i < n ; i++ ){
        scanf("%d",&k[i]);
    }
    for( i = 1 ; i <= n ; i++ ){
        temp.day = work[0][i - 1].day;
        temp.min = work[0][i - 1].min + j[i - 1];
        if( temp.min > m ){
            temp.day += 1;
            temp.min = j[i - 1];
        }
        work[0][i] = temp;
    }
    for( i = 1 ; i <= n ; i++ ){
        temp.day = work[i - 1][0].day;
        temp.min = work[i - 1][0].min + k[i - 1];
        if( temp.min > m ){
            temp.day += 1;
            temp.min = k[i - 1];
        }
        work[i][0] = temp;
    }
    for( i = 1 ; i <= n ; i++ ){
        for( l = 1 ; l <= n ; l++ ){
            temp1.day = work[i][l - 1].day;
            temp1.min = work[i][l - 1].min + j[l - 1];
            if( temp1.min > m ){
                temp1.day += 1;
                temp1.min = j[l - 1];
            }
            temp2.day = work[i - 1][l].day;
            temp2.min = work[i - 1][l].min + k[i - 1];
            if( temp2.min > m ){
                temp2.day += 1;
                temp2.min = k[i - 1];
            }
            if( temp1.day < temp2.day ){
                work[i][l] = temp1;
            }
            else if( temp2.day < temp1.day ){
                work[i][l] = temp2;
            }
            else if( temp1.min <= temp2.min ){
                work[i][l] = temp1;
            }
            else{
                work[i][l] = temp2;
            }
        }
    }
    printf("%d\n%d",work[n][n].day + 1,work[n][n].min);
    return 0;
}
