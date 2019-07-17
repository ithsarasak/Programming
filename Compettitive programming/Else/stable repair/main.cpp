#include<bits/stdc++.h>
int m, c, s, i, live[300], dif[300], sum;
int compare( const void *a, const void *b ){
    return ( *( int *)b - *( int *)a );
}
int compare2( const void *a, const void *b ){
    return ( *( int *)a - *( int *)b );
}
int main()
{
    scanf("%d %d %d",&m,&c,&s);
    for( i = 0 ; i < s; i++ ){
        scanf("%d",&live[i]);
    }
    qsort( live , s , sizeof( int ), compare2 );
    for( i = 1 ; i < s ; i++ ){
        dif[i - 1] = live[i] - live[i - 1];
    }
    qsort( dif , s - 1 , sizeof( int ), compare );
    /*for( i = 0 ; i < s - 1 ; i++ ){
        printf("%d ",dif[i]);
    }*/
    for( i = m - 1 ; i < s - 1 ; i++ ){
        sum += dif[i];
    }
    if( m > s ){
        printf("%d",s);
        return 0;
    }
    printf("%d",sum+m);
    return 0;
}
