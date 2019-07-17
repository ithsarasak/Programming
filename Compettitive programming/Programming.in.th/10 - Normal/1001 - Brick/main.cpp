#include <stdio.h>
char map[20][21] = {{'.'}};
main()
{
    int side1,side2;

    scanf("%d %d",&side1,&side2);

    int i, j, k;

    for( i = 0 ; i < side1 ; i++ )
    {
        scanf("%s",map[i]);
    }

    int game[20];

    for( i = 0 ; i < side2 ; i++ )
    {
        scanf("%d",&game[i]);
    }
    int l = 0;
    for( i = 0 ; i < side2 ; i++ )
    {
        for( k = 0 ; k < game[l] ; k++ )
        {
            for( j = 0 ; j < side1 ; j++ )
            {
                if( map[j][i] == '.' )
                {
                    map[j][i] = '#';
                    if( j != 0 )
                    {
                        map[ j - 1 ][i] = '.';
                    }
                }
                else
                {
                    break;
                }
            }
        }
        l++;
    }

    for( i = 0 ; i < side1 ; i++ )
    {
        for( j = 0 ; j < side2 ; j++ )
        {
            printf("%c",map[i][j]);
        }
        printf("\n");
    }
}
