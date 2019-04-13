#include<stdio.h>
#include<string.h>
main()
{
    char word[20];

    scanf("%s",word);

    int len = strlen( word );

    int side = ( ( len - 1 ) * 4 ) + 5;

    int i, j, pos, k = 0;

    for( i = 0 ; i < 5 ; i++ )
    {
        pos = 0;
        for( j = 0 ; j < side ; j++ )
        {
            if( i == 0 || i == 4 )
            {
                if( j == 2 )
                {
                    printf("#");
                    pos = j + 4;
                }
                else if( j == 10 || j == 22 || j == 34 || j == 46 || j == 58 )
                {
                    printf("*");
                    pos = pos + 4;
                }
                else if( j == pos && j != 0 )
                {
                    printf("#");
                    pos = j + 4;
                }
                else
                {
                    printf(".");
                }
            }
            else if( i == 1 || i == 3 )
            {
                if( j == 9 || j == 11 || j == 21 || j == 23 || j == 33 || j == 35 || j == 45 || j == 47 || j == 57 || j == 59 )
                {
                    printf("*");
                }
                else if( j % 2 == 1 )
                {
                    printf("#");
                }
                else
                {
                    printf(".");
                }
            }
            else
            {
                if( j == side - 1 && ( j != 12 && j != 24 && j != 36 && j != 48 && j != 60 ) )
                {
                    printf("#");
                }
                else if( j == 8 || j == 12 || j == 20 || j == 24 || j == 32 || j == 36 || j == 44 || j == 48 || j == 56 || j == 60 )
                {
                    printf("*");
                }
                else if( j % 4 == 0 )
                {
                    printf("#");
                }
                else if( j == 2 )
                {
                    printf("%c",word[k]);
                    k++;
                    pos = j + 4;
                }
                else if( j == pos )
                {
                    printf("%c",word[k]);
                    k++;
                    pos = j + 4;
                }
                else
                {
                    printf(".");
                }
            }
        }
        printf("\n");
    }
}
