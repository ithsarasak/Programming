#include<stdio.h>
int sumscore, score;
int i;
int main()
{
    for( i = 0 ; i < 3 ; i++ ){
        scanf("%d",&score);
        sumscore += score;
    }
    if( sumscore >= 80 ){
        printf("A");
    }
    else if( sumscore >= 75 ){
        printf("B+");
    }
    else if( sumscore >= 70 ){
        printf("B");
    }
    else if( sumscore >= 65 ){
        printf("C+");
    }
    else if( sumscore >= 60 ){
        printf("C");
    }
    else if( sumscore >= 55 ){
        printf("D+");
    }
    else if( sumscore >= 50 ){
        printf("D");
    }
    else{
        printf("F");
    }
    return 0;
}

