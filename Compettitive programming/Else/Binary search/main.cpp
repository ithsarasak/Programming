#include<stdio.h>
#include<algorithm>

struct number{
    int num;
    int pos;
}input[100];
int n, find;
bool compare( struct number a, struct number b )
{
    return ( a.num < b.num );
}
int binarysearch( int k , int start , int end )
{
    while( start <= end ){
        int m = ( start + end ) / 2;
        if( k > input[m].num ){
            start = m + 1;
        }
        else if( k < input[m].num ){
            end = m - 1;
        }
        else{
            return input[m].pos;
        }
    }
    return -1;
}
int main()
{
    scanf("%d",&n);

    for( int i = 0 ; i < n ; i++ ){
        scanf("%d",&input[i].num);
        input[i].pos = i;
    }
    std::sort( input , input + n , compare );
    for( int i = 0 ; i < n ; i++ ){
        printf("%d ",input[i].num);
    }
    printf("\n");
    scanf("%d",&find);
    int ans = binarysearch( find , 0 , n - 1 );
    if( ans == -1 ){
        printf("No number found");
        return 0;
    }
    printf("%d",ans);
    return 0;
}
