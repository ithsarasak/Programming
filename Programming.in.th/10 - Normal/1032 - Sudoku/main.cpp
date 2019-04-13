#include <stdio.h>

int jode[9][9], setall[9][9], check[10], amount;

int sudoku()
{
    //printf("SUdoku");
    int i, j, k, l;

    for( i = 0 ; i < 9; i++ )
    {
        for( j = 0 ; j < 9; j++ )
        {
            scanf("%d",&setall[i][j]);
        }
    }

    for( i = 0 ; i < 9; i++ )
    {
        for( j = 0 ; j < 9; j++ )
        {
            if( jode[i][j] != 0 && jode[i][j] != setall[i][j])
            {
                return 0;
            }
        }
    }

    for( i = 0 ; i <= 9 ; i++ )
    {
        check[i] = 0;
    }

    for( i = 0 ; i < 9 ; i++ )
    {
        for( j = 0 ; j < 9 ; j++ )
        {
            check[setall[i][j]]++;
        }
        for( k = 1 ; k <= 9 ; k++ )
        {
            if( check[k] == 0 )
            {
                return 0;
            }
        }
        for( k = 0 ; k <= 9 ; k++ )
        {
            check[k] = 0;
        }
    }

    for( i = 0 ; i < 9 ; i++ )
    {
        for( j = 0 ; j < 9 ; j++ )
        {
            check[setall[j][i]]++;
        }
        for( k = 1 ; k <= 9 ; k++ )
        {
            if( check[k] == 0 )
            {
                return 0;
            }
        }
        for( k = 0 ; k <= 9 ; k++ )
        {
            check[k] = 0;
        }
    }

    for( i = 0 ; i < 9 ; i += 3 )
    {
        for( j = 0 ; j < 9 ; j += 3 )
        {
             for( k = i ; k < i + 3 ; k++ )
             {
                for( l = j ; l < j + 3 ; l++ )
                {
                    check[setall[k][l]]++;
                }
             }
             for( k = 1 ; k <= 9 ; k++ )
             {
                if( check[k] == 0 )
                {
                    return 0;
                }
            }
            for( k = 0 ; k <= 9 ; k++ )
            {
                check[k] = 0;
            }
        }
    }

    return 1;
}



int main()
{
    int m, n;

    scanf("%d",&amount);

    for( m = 0 ; m < 9 ; m++ )
    {
        for( n = 0 ; n < 9 ; n++)
        {
            scanf("%d",&jode[m][n]);
        }
    }

    for( m = 1 ; m <= amount ; m++ )
    {
        if( sudoku() )
        {
            printf("%d\n",m);
        }
    }

    printf("END");

    return 0;

}
