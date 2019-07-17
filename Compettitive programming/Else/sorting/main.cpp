#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n, i, j, k, num;
int numba[100010];
double number[100010];
char ch[100010];
struct A{
    char word[110];
}aa[100100];
int compare( const void *a , const void *b ){
    if( *( int *) a > *( int *)b ){
        return 1;
    }
    else{
        return -1;
    }
}
int compare3( const void *a , const void *b ){
    if( *( double *) a > *( double *)b ){
        return 1;
    }
    else{
        return -1;
    }
}
int compare5( const void *a , const void *b ){
    return ( *( char *)a - *( char *)b );
}
int compare7( const void *a , const void *b ){
    struct A *p, *q;
    p = ( A *)a, q = ( A *)b;
    return strcmp( p -> word , q -> word );
}
int main()
{
    scanf("%d",&n);
    if( n == 1 ){
        scanf("%d",&num);
        for( i = 0 ; i < num ; i++ ){
            scanf("%d",&numba[i]);
        }
        qsort( numba , num , sizeof( int ) , compare );
        for( i = 0 ; i < num ; i++ ){
            printf("%d ",numba[i]);
        }
        printf("\n");
        for( i = num - 1 ; i >= 0 ; i-- ){
            printf("%d ",numba[i]);
        }
        printf("\n");
    }
    else if( n == 2 ){
        scanf("%d",&num);
        for( i = 0 ; i < num ; i++ ){
            scanf("%lf",&number[i]);
        }
        qsort( number , num , sizeof( double ) , compare3 );
        for( i = 0 ; i < num ; i++ ){
            printf("%.0lf ",number[i]);
        }
        printf("\n");
        for( i = num - 1 ; i >= 0 ; i-- ){
            printf("%.0lf ",number[i]);
        }
        printf("\n");
    }
    else if( n == 3 ){
        scanf("%d",&num);
        for( i = 0 ; i < num ; i++ ){
            scanf(" %c",&ch[i]);
        }
        qsort( ch , num , sizeof( char ) , compare5 );
        for( i = 0 ; i < num ; i++ ){
            printf("%c ",ch[i]);
        }
        printf("\n");
        for( i = num - 1 ; i >= 0 ; i-- ){
            printf("%c ",ch[i]);
        }
        printf("\n");
    }
    else{
        scanf("%d",&num);
        for( i = 0 ; i < num ; i++ ){
            scanf(" %s",aa[i].word);
        }
        qsort( aa , num , sizeof( aa[0] ) , compare7 );
        for( i = 0 ; i < num ; i++ ){
            printf("%s ",aa[i].word);
        }
        printf("\n");
        for( i = num - 1 ; i >= 0 ; i-- ){
            printf("%s ",aa[i].word);
        }
    }
    return 0;
}
