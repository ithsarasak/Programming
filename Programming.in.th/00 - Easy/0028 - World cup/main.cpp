#include<stdio.h>
struct country{
    char name[1000];
    int point = 0;
    int enemygoal = 0;
    int owngoal = 0;
}all[5];
int main()
{
    int i,j;
    int score[4][4];

    for( i = 0 ; i < 4; i++ )
    {
        scanf("%s",all[i].name);
    }
    for( i = 0 ; i < 4 ; i++ )
    {
        for( j = 0 ; j < 4 ; j++ )
        {
            scanf("%d",&score[i][j]);
        }
    }
    for( i = 0 ; i < 4 ; i++ )
    {
        for( j = 0 ; j < 4 ; j++ )
        {
            if( score[i][j] > score[j][i] )
            {
                all[i].point = all[i].point + 3;
            }
            else if( score[i][j] == score[j][i] && i != j )
            {
                all[i].point = all[i].point + 1;
            }
        }
    }
    for( i = 0 ; i < 4 ; i++ )
    {
        for( j = 0 ; j < 4 ; j++ )
        {
            all[i].enemygoal = all[i].enemygoal + score[i][j];
        }
    }
    for( j = 0 ; j < 4 ; j++ )
    {
        for( i = 0 ; i < 4 ; i++ )
        {
            all[j].owngoal = all[j].owngoal + score[j][i];
        }
    }
    country temp;
    for( i = 0 ; i < 4 ; i++ )
    {
        for( j = 0 ; j < 4 ; j++ )
        {
            if( all[i].point < all[j].point )
            {
                temp = all[i];
                all[i] = all[j];
                all[j] = temp;
            }
            else if( all[i].point == all[j].point )
            {
                if( ( all[i].enemygoal - all[i].owngoal ) < ( all[j].enemygoal - all[j].owngoal ) )
                {
                    temp = all[i];
                    all[i] = all[j];
                    all[j] = temp;
                }
                else if( ( all[i].enemygoal - all[i].owngoal ) == ( all[j].enemygoal - all[j].owngoal ) )
                {
                    if( all[i].enemygoal < all[j].enemygoal )
                    {
                        temp = all[i];
                        all[i] = all[j];
                        all[j] = temp;
                    }
                }
            }
        }
    }
    for( i = 3 ; i >= 0 ; i-- )
    {
        printf("%s %d\n",all[i].name,all[i].point);
    }
    return 0;
}
