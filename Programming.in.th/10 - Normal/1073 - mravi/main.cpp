#include<stdio.h>
#include<stdlib.h>

int compare( const void *a , const void *b )
{
    return ( *( int *)a - *( int *)b );
}
int l, t, n, i, ans[100001];
int main()
{
    scanf("%d %d",&l,&t);
    scanf("%d",&n);

    for( i = 0 ; i < n ; i++ ){
        int pos;
        char side;
        scanf("%d %c",&pos,&side);
        //pos -= 1;

        if( side == 'L' ){
            pos = pos - t;
           /* if( t == -1 ){
                t = 0;
            }
            else */if( pos < 0 ){
                pos = 0 -  pos;
            }
        }
        else{
            pos = pos + t;
            //printf("[p\%d\n",pos);
            /*if( pos == l ){
                pos = l - 1;
            }*/
            if( pos > l ){
                pos = ( 2 * l ) - pos;
            }
        }
       // printf("%d\n",pos);
        while( pos > l || pos < 0 ){
            //printf("%d\n",pos);
            if( pos < 0 ){
                pos = 0 - pos;
        //printf("%d\n",pos);
            }
            else{
                pos = ( 2 * l ) - pos;
            }
        }
        ans[i] = pos;
    }
    //printf(" %d\n",i);
    qsort( ans , n , sizeof( int ) , compare );
    for( int j = 0 ; j < n ; j++ ){
        printf("%d ",ans[j]);
    }
    return 0;
}
