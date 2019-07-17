#include<stdio.h>
#include<string.h>
char one[201], two[201];
int all[201][201], len1, len2, max, posx, posy, i, j;
int main()
{
    scanf("%s",one);
    scanf("%s",two);

    len1 = strlen( one );
    len2 = strlen( two );
    for( i = 0 ; i < len1 ; i++ ){
        for( j = 0 ; j < len2 ; j++ ){
            /*printf("%d %d\n",i,j);
            printf("%c %c\n",one[i],two[j]);*/
            if( one[i] == two[j] && ( i == 0 || j == 0 ) ){
                all[i][j] = 1;
            }
            else if( one[i] == two[j] ){
                all[i][j] = all[i - 1][j - 1] + 1;
            }
            if( max < all[i][j] ){
                max = all[i][j];
                posx = i;
                posy = j;
            }
        }
    }
    for( i = 0 ; i < len1 ; i++ ){
            for( j = 0 ; j < len2 ; j++ ){
                printf(" %d ",all[i][j]);
            }
            printf("\n");
    }
    for( i = posx - max + 1 ; i <= posx  ; i++ ){
        printf("%c",one[i]);
    }
    return 0;
}
