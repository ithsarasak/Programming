#include<stdio.h>

int place[10001], town ,start, day, i, j, b;
int max;

int travel( int n , int s , int d , int sum , int check[] )
{
    printf("%d %d %d %d\n",n,s,d,sum);
    if( d <= 0 ){
        if( max < sum ){
            max = sum;
        }
        return 0;
    }
    if( s < 0 ){
        return 0;
    }
    if( s >= town ){
        return 0;
    }
    travel( n , s - 1 , d - 1 , sum , check );
    if( check[s] == 0 ){
        sum += place[s];
        check[s] = 1;
    }
    travel( n , s , d - 1 , sum , check );
    travel( n , s + 1 , d - 1 , sum , check );
    return 0;
}
int main()
{
    scanf("%d %d %d",&town,&start,&day);

    for( i = 0 ; i < town ; i++ ){
        scanf("%d",&place[i]);
    }
    int sum = 0;
    int check[10001];
    char di;

    for( i = 0 ; i < 10001 ; i++ ){
        check[i] = 0;
    }
    travel( town , start , day , sum, check );
    printf("%d",max);
}
