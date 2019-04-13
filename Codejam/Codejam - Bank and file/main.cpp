#include <stdio.h>
int i;
int count[2501];
int j,k;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int amount;

    scanf("%d",&amount);

    for( i = 1 ; i <=amount ; i++ )
    {
        for( j = 0 ; j <= 2500 ; j++ )
        {
            count[j] = 0;
        }
        int length;

        scanf("%d",&length);

        int soilder[(length*2)-1][length],collect[2500],aans=0;

        for( j = 0 ; j < ( 2 * length ) - 1 ; j++ )
        {
            for( k = 0 ; k < length ; k++ )
            {
                scanf("%d",&soilder[j][k]);
            }
        }

        for( j = 0 ; j < ( 2 * length ) - 1 ; j++ )
        {
            for( k = 0 ; k < length ; k++ )
            {
                count[soilder[j][k]]++;
            }
        }

        /*for( j = 0 ; j < 7 ; j++ )
        {
            printf("%d ",count[j]);
        }*/

        //printf("\n");
        for( j = 1 ; j <= 2500 ; j++ )
        {
            if( count[j] % 2 == 1 )
            {
                collect[aans] = j;
                aans++;
            }
        }
        printf("Case #%d:",i);
        for( j = 0 ; j < aans ; j++)
        {
            printf(" %d",collect[j]);
        }
        printf("\n");
    }
    return 0;
}
