#include<stdio.h>
#include<stdlib.h>

char mother1[200], mother2[200], key[200], temp[5], t;
int i, j, l, k, len1, len2;

int main()
{
    scanf("%d %d",&len1,&len2);

    scanf("%s",mother1);
    scanf("%s",mother2);
    scanf("%s",key);

    for( i = 0 ; i < len2 ; i++ ){
        for( j = 0 ; j < len1 ; j++ ){
            temp[0] = mother1[j];
            temp[1] = key[i];
            temp[2] = mother2[j];
            /*printf("Before : ");
            for( k = 0 ; k < 3 ; k++ ){
                printf("%c",temp[k]);
            }
            printf("\n");
            printf("Sort : ");*/
            for( k = 0 ; k < 3 ; k++ ){
                for( l = k + 1 ; l < 3 ; l++ ){
                    if( temp[k] < temp[l] ){
                        t = temp[k];
                        temp[k] = temp[l];
                        temp[l] = t;
                    }
                    /*printf("%s",temp);
                    printf("\n");*/
                }
            }
            /*printf("After : ");
            for( k = 0 ; k < 3 ; k++ ){
                printf("%c",temp[k]);
            }
            printf("\n\n");*/
            key[i] = temp[1];
        }
    }
    printf("%s",key);
}
