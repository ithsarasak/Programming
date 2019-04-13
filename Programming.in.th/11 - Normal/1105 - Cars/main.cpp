#include<stdio.h>
int car[2000001], max = 0, i, temp;
int main()
{
    int n, k, t;
    scanf("%d %d",&n,&k);

    for( i = 0 ; i < n ; i++ ){
        scanf("%d",&t);
        car[t]++;
        if( max < t )
        {
            max = t;
        }
    }
    /*printf("%d",max);
    for( i = 1 ; i <= 8 ; i++ ){

        printf("%d ",car[i]);
    }*/
    for( i = max ; i >= 1 ; i-- ){
        if( car[i] > 0 ){
            temp++;
        }
        if( temp == k ){
            break;
        }
    }
    printf("%d",i);
}
