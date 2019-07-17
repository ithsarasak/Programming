#include <stdio.h>
long long id[1000], i, j, k, amount, pair;
int main()
{
    scanf("%d",&amount);

    for( i = 0 ; i < amount ; i++ )
    {
        int ids;

        scanf("%d",&ids);

        id[ids]++;
    }
    /*for( i = 0 ; i < 1000 ; i++ )
    {
        printf("%d ",id[i]);
    }
    printf("\n");*/
    for( i = 0 ; i < 1000 ; i++ )
    {
        for( j = i ; j < 1000 ; j++ )
        {
            if( id[i] > 0 && id[j] > 0 )
            {
                if( i == j )
                {
                    /*printf("idi : %d ",id[i]);
                    printf("idj : %d\n",id[j]);*/
                    if( id[i] > 1 )
                    {
                        for( k = 1 ; k < id[i] ; k++ )
                        {
                            pair += k;
                        }
                    }
                    //printf("pair : %d\n",pair);
                }
                else
                {
                    int help1 = i / 100 , help2 = j / 100;
                    int help3 = ( i - ( 100 * help1 ) ) / 10  , help4 = ( j - ( 100 * help2 ) ) / 10;
                    int help5 = ( i - ( 100 * help1 ) - ( 10 * help3 ) ) , help6 = ( j - ( 100 * help2 ) - ( 10 * help4 ) );
                    /*printf("i : %d ",i);
                    printf("j : %d\n",j);
                    printf("idi : %d idj : %d\n",id[i],id[j]);
                    printf("help1 : %d\nhelp2 : %d\nhelp3 : %d\nhelp4 : %d\nhelp5 : %d\nhelp6 : %d\n",help1,help2,help3,help4,help4,help5,help6);*/


                    if( help1 == help2 )
                    {
                        pair += id[i] * id[j];
                    }
                    else if( help3 == help4 )
                    {
                        pair += id[i] * id[j];
                    }
                    else if( help5 == help6 )
                    {
                        pair += id[i] * id[j];
                    }
                    //printf("pair : %d\n",pair);
                }
            }
        }
    }
    printf("%lld",pair);

    return 0;
}
