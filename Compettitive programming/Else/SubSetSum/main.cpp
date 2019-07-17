#include<stdio.h>

 int num[101], i, j, value, amount;

bool SubsetSum(int set[], int n, int sum)
{
   if ( sum == 0 )
     return true;
   if ( n == 0 && sum != 0 )
     return false;

   if ( set[n-1] > sum )
     return SubsetSum( set, n - 1, sum );

   return ( SubsetSum( set, n - 1, sum ) || SubsetSum( set, n - 1, sum - set[n - 1] ) );
}
int main()
{
    scanf("%d",&amount);

    for( i = 0 ; i < amount ; i++ ){
        scanf("%d",&num[i]);
    }
    scanf("%d",&value);

    if( SubsetSum( num , amount , value ) ){
        printf("Found");
    }
    else{
        printf("NotFound");
    }
    return 0;
}
