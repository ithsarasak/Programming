#include<stdio.h>
int side, cmount[22][22], i, j, max = -6;
int sx,sy;
int rising( int ss , int sd , int temp )
{
    //printf("cmount[%d][%d] : %d temp : %d max : %d\n",ss,sd,cmount[ss][sd],temp,max);
    if( cmount[ss][sd] <= temp ){
        return 0;
    }
    if( cmount[ss][sd] == 100 ){
        return 0;
    }

    if( max < cmount[ss][sd] ){
            max = cmount[ss][sd];
    }

    rising( ss - 1 , sd , cmount[ss][sd] );
    rising( ss + 1 , sd , cmount[ss][sd] );
    rising( ss , sd - 1 , cmount[ss][sd] );
    rising( ss , sd + 1 , cmount[ss][sd] );
}
int main()
{
    scanf("%d",&side);

    scanf("%d %d",&sy,&sx);

    for( i = 1 ; i <= side; i++ ){
        for( j = 1 ; j <= side ; j++ ){
            scanf("%d",&cmount[i][j]);
        }
    }
    rising( sx , sy , -6 );
    printf("%d",max);
}
