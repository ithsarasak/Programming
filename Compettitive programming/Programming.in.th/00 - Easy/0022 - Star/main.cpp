#include<stdio.h>
char star[1001][1001];
main()
{
    int num,i,j;

    scanf("%d",&num);

    if(num%2==1)
    {
        for(i=0;i<num;i++)
        {
            for(j=0;j<num;j++)
            {
                star[i][j]='-';
            }
        }

        int posx,posy;

        for(i=0;i<num;i++)
        {
            if(i==num/2)
            {
                star[0][i]='*';
                star[num-1][i]='*';
                posx=0;
                posy=i;
                break;
            }
        }

        for(i=0;i<(num/2)-1;i++)
        {
            star[posx+1][posy-(i+1)]='*';
            star[posx+1][posy+(i+1)]='*';
            star[num-(posx+2)][posy-(i+1)]='*';
            star[num-(posx+2)][posy+(i+1)]='*';
            posx=posx+1;
        }

        star[(num/2)][0]='*';
        star[(num/2)][num-1]='*';

        for(i=0;i<num;i++)
        {
            for(j=0;j<num;j++)
            {
                printf("%c",star[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        for(i=0;i<num;i++)
        {
            for(j=0;j<num-1;j++)
            {
                star[i][j]='-';
            }
        }

        int posx,posy;

        for(i=0;i<num;i++)
        {
            if(i==(num-1)/2)
            {
                star[0][i]='*';
                star[num-1][i]='*';
                posx=0;
                posy=i;
                break;
            }
        }

        for(i=0;i<(num/2)-2;i++)
        {
            star[posx+1][posy-(i+1)]='*';
            star[posx+1][posy+(i+1)]='*';
            star[num-(posx+2)][posy-(i+1)]='*';
            star[num-(posx+2)][posy+(i+1)]='*';
            posx=posx+1;
        }

        star[(num/2)-1][0]='*';
        star[(num/2)-1][num-2]='*';
        star[(num/2)][0]='*';
        star[(num/2)][num-2]='*';

        for(i=0;i<num;i++)
        {
            for(j=0;j<num-1;j++)
            {
                printf("%c",star[i][j]);
            }
            if(i!=num-1)
                printf("\n");
        }
    }
}
