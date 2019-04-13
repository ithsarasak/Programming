#include<stdio.h>
#include<string.h>

int lak, i, j, num;
char permu[100000][16], stunt[15];

int space( int d , char k )
{
    if( d != -1 ){
        stunt[d] = k;
    }
    if( d == lak - 1 ){
        strcpy( permu[num] , stunt );
        //printf("stunt : %s\n",stunt);
        num++;
        return 0;
    }
    //printf("d : %d k : %c\n",d,k);
    space( d + 1 , '0' );
    space( d + 1 , '1' );
    return 0;
}
int main()
{
    scanf("%d",&lak);

    space( -1 , '0' );
    /*printf("num :  %d\n",num);
    for( i = 0 ; i < num ; i++ ){
        printf("permu :  %s\n",permu[i]);
    }*/
    int k, count = 0;
    for( i = 0 ; i < num  - 1 ; i++ ){
        char numer[100];
        strcpy( numer , permu[i] );
        for( j = lak - 1 ; j >= 0 ; j-- ){
            if( numer[j] != '1' ){
                numer[j] = '1';
                printf("%s %s\n",permu[i],numer);
                numer[j] = '0';
            }
        }
    }
}
