#include<bits/stdc++.h>
struct A{
    char word[100];
}a[15000];
int compare7( const void *a , const void *b ){
    struct A *p, *q;
    p = ( A *)a, q = ( A *)b;
    return strcmp( p -> word , q -> word );
}
char words[100];
int n, m, k, i;
int main()
{
    scanf("%d %d %d",&n,&m,&k);
    for( i = 0 ; i < n ; i++ ){
        scanf(" %s",a[i].word);
    }
    qsort( a , n , sizeof( a[0] ) , compare7 );
    for( i = 0 ; i < m ; i++ ){
        scanf(" %s",words);
        int first = 0, last = n - 1, mid;
        while( 1 ){
            mid = ( first + last ) / 2;
            if( strcmp( a[first].word , words ) == 0 ){
                printf("Accepted\n");
                break;
            }
            if( strcmp( a[last].word , words ) == 0 ){
                printf("Accepted\n");
                break;
            }
            if( strcmp( a[mid].word , words ) == 0 ){
                printf("Accepted\n");
                break;
            }
            if( first + 1 == last ){
                printf("Rejected\n");
                break;
            }
            if( strcmp( a[mid].word , words ) > 0 ){
                last = mid;
            }
            else if( strcmp( a[mid].word , words ) < 0 ){
                first = mid;
            }
        }
    }
}
