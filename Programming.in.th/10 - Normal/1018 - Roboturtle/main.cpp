#include<stdio.h>
#include<string.h>
int x, y, i, check = 0, amount;
int dis;
char command[3], di = 'E';
int main()
{
    scanf("%d",&amount);

    for( i = 0 ; i < amount ; i++ )
    {
        scanf("%s %d",command,&dis);

        if( command[0] == 'L' )
        {
            //printf("%c %s %d\n",di,command,dis );
            if( di == 'E' )
            {
                di = 'N';

                y += dis;
            }
            else if( di == 'N' )
            {
                di = 'W';

                x -= dis;
            }
            else if( di == 'S' )
            {
                di = 'E';

                x += dis;
            }
            else if( di == 'W' )
            {
                di = 'S';

                y -= dis;
            }
        }
        else if( command[0] == 'R' )
        {
            if( di == 'E' )
            {
                di = 'S';

                y -= dis;
            }
            else if( di == 'N' )
            {
                di = 'E';

                x += dis;
            }
            else if( di == 'S' )
            {
                di = 'W';

                x -= dis;
            }
            else if( di == 'W' )
            {
                di = 'N';

                y += dis;
            }
        }
        else if( command[0] == 'B' )
        {
            if( di == 'E' )
            {
                di = 'W';

                x -= dis;
            }
            else if( di == 'N' )
            {
                di = 'S';

                y -= dis;
            }
            else if( di == 'S' )
            {
                di = 'N';

                y += dis;
            }
            else if( di == 'W' )
            {
                di = 'E';

                x += dis;
            }
        }
        else if( command[0] == 'F' )
        {
            if( di == 'E' )
            {
                x += dis;
            }
            else if( di == 'N' )
            {
                y += dis;
            }
            else if( di == 'S' )
            {
                y -= dis;
            }
            else if( di == 'W' )
            {
                x -= dis;
            }
        }
        if( x >= 50000 || x <= -50000 || y >= 50000 || y <= -50000 )
        {
            check = 1;
        }
    }
    if( check )
    {
        printf("DEAD");
    }
    else
    {
        printf("%d %d\n%c",x,y,di);
    }
}
