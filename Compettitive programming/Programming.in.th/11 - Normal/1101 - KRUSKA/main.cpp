#include <stdio.h>
int map[201][201], turn, di = 'R', i, j, k, side, amountwiz, day = 0;
struct wizard{
    int x,y;
    char daily[10];
}allwiz[10000];
int main()
{
    scanf("%d %d",&side,&turn);
    scanf("%d",&amountwiz);

    for( i = 0 ; i < amountwiz ; i++ )
    {
        int pos1,pos2;
        scanf("%d %d",&pos1,&pos2);

        map[pos1][pos2] = 1;
        allwiz[i].x = pos1;
        allwiz[i].y = pos2;
        scanf("%s",allwiz[i].daily);
    }
    /*for( i = 1 ; i <= side ; i++ )
    {
        for( j = 1 ; j <= side ; j++ )
        {
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
    printf("\n");*/
    i = 1;
    j = 1;
    while( turn > 0 )
    {
        //printf("%d %d\n",i,j);
        //printf("map[%d][%d] : %d day : %d\n",i,j,map[i][j],day);
        if( map[i][j] == 1 )
        {
            for( k = 0 ; k < amountwiz ; k++ )
            {
                //printf("allwiz[%d].x : %d allwiz[%d].y : %d\n",k,allwiz[k].x,k,allwiz[k].y);
                if( allwiz[k].x == i && allwiz[k].y == j )
                {
                    /*printf("map[%d][%d] : %d day : %d\n",i,j,map[i][j],day);
                    printf("turn : %d\n",turn);*/
                    if( allwiz[k].daily[(day)%7] == 'R' )
                    {
                        if( di == 'R' )
                        {
                            di = 'D';
                            turn -= 1;
                            if( i + 1 > side )
                            {
                                turn -= 1;
                                di = 'F';
                            }
                            else
                            {
                                i += 1;
                                if( turn != 0 )
                                {
                                    day += 1;
                                }
                            }
                            //printf("turn : %d day : %d\n",turn,day);
                        }
                        else if( di == 'L' )
                        {
                            di = 'F';
                            turn -= 1;
                            if( i - 1 <= 0 )
                            {
                                turn -= 1;
                                di = 'D';
                            }
                            else
                            {
                                i -= 1;
                                if( turn != 0 )
                                {
                                    day += 1;
                                }
                            }
                            ///printf("turn : %d day : %d\n",turn,day);
                        }
                        else if( di == 'F' )
                        {
                            di = 'R';
                            turn -= 1;
                            if( j + 1 > side )
                            {
                                turn -= 1;
                                di = 'L';
                            }
                            else
                            {
                                j += 1;
                                if( turn != 0 )
                                {
                                    day += 1;
                                }
                            }
                            //printf("turn : %d day : %d\n",turn,day);
                        }
                        else if( di == 'D' )
                        {
                            di = 'L';
                            turn -= 1;
                            if( j - 1 <= 0 )
                            {
                                turn -= 1;
                                di = 'R';
                            }
                            else
                            {
                                j -= 1;
                                if( turn != 0 )
                                {
                                    day += 1;
                                }
                            }
                            //printf("turn : %d day : %d\n",turn,day);
                        }
                    }
                    else if( allwiz[k].daily[(day)%7] == 'L' )
                    {
                        if( di == 'R' )
                        {
                            //printf("turn : %d\n",turn);
                            di = 'F';
                            turn -= 1;
                            if( i - 1 <= 0 )
                            {
                                turn -= 1;
                                di = 'D';
                            }
                            else
                            {
                                i -= 1;
                                if( turn != 0 )
                                {
                                    day += 1;
                                }
                            }
                            //printf("turn : %d day : %d\n",turn,day);
                        }
                        else if( di == 'L' )
                        {
                            di = 'D';
                            turn -= 1;
                            if( i + 1 > side )
                            {
                                turn -= 1;
                                di = 'F';
                            }
                            else
                            {
                                i += 1;
                                if( turn != 0 )
                                {
                                    day += 1;
                                }
                            }
                            //printf("turn : %d day : %d\n",turn,day);
                        }
                        else if( di == 'F' )
                        {
                            di = 'L';
                            turn -= 1;
                            if( j - 1 <= 0 )
                            {
                                turn -= 1;
                                di = 'R';
                            }
                            else
                            {
                                j -= 1;
                                if( turn != 0 )
                                {
                                    day += 1;
                                }
                            }
                            //printf("turn : %d day : %d\n",turn,day);
                        }
                        else if( di == 'D' )
                        {
                            di = 'R';
                            turn -= 1;
                            if( j + 1 > side )
                            {
                                turn -= 1;
                                di = 'L';
                            }
                            else
                            {
                                j += 1;
                                if( turn != 0 )
                                {
                                    day += 1;
                                }
                            }
                            //printf("turn : %d day : %d\n",turn,day);
                        }
                    }
                    else
                    {
                        if( di == 'D' )
                        {
                            if( i + 1 > side )
                            {
                                turn -= 1;
                                di = 'F';
                            }
                            else
                            {
                                i += 1;
                                if( turn != 0 )
                                {
                                    day += 1;
                                }
                            }
                        }
                        else if( di == 'F' )
                        {
                            if( i - 1 <= 0 )
                            {
                                turn -= 1;
                                di = 'D';
                            }
                            else
                            {
                                i -= 1;
                                if( turn != 0 )
                                {
                                    day += 1;
                                }
                            }
                        }
                        else if( di == 'R' )
                        {
                            if( j + 1 > side )
                            {
                                turn -= 1;
                                di = 'L';
                            }
                            else
                            {
                                j += 1;
                                if( turn != 0 )
                                {
                                    day += 1;
                                }
                            }
                        }
                        else if( di == 'L' )
                        {
                            if( j - 1 <= 0 )
                            {
                                turn -= 1;
                                di = 'R';
                            }
                            else
                            {
                                j -= 1;
                                if( turn != 0 )
                                {
                                    day += 1;
                                }
                            }
                        }
                    }
                    break;
                }
            }
        }
        else
        {
            if( di == 'D' )
            {
                if( i + 1 > side )
                {
                    turn -= 1;
                    di = 'F';
                }
                else
                {
                    i += 1;
                    day += 1;
                }
            }
            else if( di == 'F' )
            {
                if( i - 1 <= 0 )
                {
                    turn -= 1;
                    di = 'D';
                }
                else
                {
                    i -= 1;
                    day += 1;
                }
            }
            else if( di == 'R' )
            {
                if( j + 1 > side )
                {
                    turn -= 1;
                    di = 'L';
                }
                else
                {
                    j += 1;
                    day += 1;
                }
            }
            else if( di == 'L' )
            {
                if( j - 1 <= 0 )
                {
                    turn -= 1;
                    di = 'R';
                }
                else
                {
                    j -= 1;
                    day += 1;
                }
            }
        }
    }
    printf("%d",day);
}
