#include<stdio.h>
int all, k;
struct node{
    long long min, max;
};
typedef struct node node;
long long mins( long long a , long long b )
{
    return ( a < b ? a : b );
}
long long maxs( long long a , long long b )
{
    return ( a > b ? a : b );
}
int main()
{
    scanf("%d",&all);
    for( k = 0 ; k < all ; k++ ){
        long long n, num[4000], i, j;
        node product[4000];
        for( i = 0 ; i < 3601 ; i++ ){
            product[i].min = 0;
            product[i].max = 0;
        }
        scanf("%lld",&n);
        for( i = 0 ; i < n ; i++ ){
            scanf("%lld",&num[i]);
            if( i == 0 ){
                product[i].min = mins( num[i] , 0 );
                product[i].max = maxs( num[i] , 0 );
            }
            else if( i == 1 ){
                if( num[i] > 0 ){
                    product[i].min = product[i - 1].min;
                    product[i].max = maxs( num[i] , product[i - 1].max );
                }
                else{
                    product[i].min = mins( num[i] , product[i - 1].min );
                    product[i].max = product[i - 1].max;
                }
            }
            else{
                if(  num[i] > 0 ){
                    product[i].max = maxs( num[i] , maxs( num[i] * product[i - 2].max , product[i - 1].max ) );
                    product[i].min = mins( num[i] , mins( num[i] * product[i - 2].min , product[i - 1].min ) );
                }
                else{
                    product[i].max = maxs( num[i] , maxs( num[i] * product[i - 2].min , product[i - 1].max ) );
                    product[i].min = mins( num[i] , mins( num[i] * product[i - 2].max , product[i - 1].min ) );
                }
            }
        }
        if( n == 1 ){
            printf("Case #%d: %lld\n",k + 1,num[0]);
        }
        else if( n == 2 ){
            printf("Case #%d: %lld\n",k + 1,maxs( num[0] , num[1] ));
        }
        else{
            printf("Case #%d: %lld\n",k + 1,product[n - 1].max);
        }
        /*for( i = 0 ; i < n ; i++ ){
            printf("min : %lld max : %lld\n",product[i].min,product[i].max);
        }*/
    }
}
