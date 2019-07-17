#include<stdio.h>
#include<string.h>
#include<math.h>

char walk[1000];

int main()
{
    double x = 0, y = 0, dis;
    int i = 0, j, dist = 0,lake = 0;

    do
    {
        i = 0;
        lake = 0;
        scanf("%s",&walk);
        //printf("%s",walk);
        if( walk[0] != '*' )
        {
            //printf("%s",walk);
            int len = strlen( walk );
            //printf("%d\n",len);
            while( walk[i] >= '0' && walk[i] <= '9' )
            {
                //printf("%d\n",lake);
                lake *= 10;
                lake += walk[i] - '0';
                i++;
            }
            if( walk[i] == 'N' )
            {
                if( walk[ i + 1 ] == '\0' )
                {
                    y += lake;
                }
                else if( walk[ i + 1 ] == 'E' )
                {
                    y += lake * ( sqrt(2) / 2 );
                    x += lake * ( sqrt(2) / 2 );
                }
                else if( walk[ i + 1 ] == 'W' )
                {
                    y += lake * ( sqrt(2) / 2 );
                    x -= lake * ( sqrt(2) / 2 );
                }
            }
            else if( walk[i] == 'S' )
            {
                if( walk[ i + 1 ] == '\0' )
                {
                    y -= lake;
                }
                else if( walk[ i + 1 ] == 'E' )
                {
                    y -= lake * ( sqrt(2) / 2 );
                    x += lake * ( sqrt(2) / 2 );
                }
                else if( walk[ i + 1 ] == 'W' )
                {
                    y -= lake * ( sqrt(2) / 2 );
                    x -= lake * ( sqrt(2) / 2 );
                }
            }
            else if( walk[i] == 'E' )
            {
                if( walk[ i + 1 ] == '\0' )
                {
                    x += lake;
                }
                else if( walk[ i + 1 ] == 'N' )
                {
                    y += lake * ( sqrt(2) / 2 );
                    x += lake * ( sqrt(2) / 2 );
                }
                else if( walk[ i + 1 ] == 'S' )
                {
                    y -= lake * ( sqrt(2) / 2 );
                    x += lake * ( sqrt(2) / 2 );
                }
            }
            else if( walk[i] == 'W' )
            {
                if( walk[ i + 1 ] == '\0' )
                {
                    x -= lake;
                }
                else if( walk[ i + 1 ] == 'N' )
                {
                    y += lake * ( sqrt(2) / 2 );
                    x -= lake * ( sqrt(2) / 2 );
                }
                else if( walk[ i + 1 ] == 'S' )
                {
                    y -= lake * ( sqrt(2) / 2 );
                    x -= lake * ( sqrt(2) / 2 );
                }
            }

        }
    }while( walk[0] != '*' );
    dis = sqrt( ( x * x) + ( y * y ) );
    printf("%.3lf %.3lf\n%.3lf",x,y,dis);
    return 0;
}
