#include<stdio.h>
#include<queue>

using namespace std;

int i, j, pound = 0, customers,  counts = 0;
int num;
int sum[5];
int main()
{
    scanf("%d",&customers);

    for( i = 0 ; i < customers ; i++ )
    {
        for( j = 0 ; j < 5 ; j++ )
        {
            scanf("%d",&num);
            sum[j] = sum[j] + num;
        }
    }

    /*for( i = 0 ; i < 5 ; i++ )
    {
        printf("%d ",sum[i]);
    }*/
    pound = sum[0] + sum[1] + ( sum[2] + 1 ) / 2;
    counts  = sum[1] + ( ( sum[2] % 2 ) * 2 );
    //printf("%d\n",pound);
    while( sum[3] >  counts )
    {
        counts += 4;
        pound += 1;
    }
    counts = counts - sum[3];
    sum[3] = 0;
    counts = counts * 2;
    while( sum[4] >  counts )
    {
        counts += 8;
        pound += 1;
    }
    printf("%d",pound);
}
