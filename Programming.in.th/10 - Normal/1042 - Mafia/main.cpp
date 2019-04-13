#include<stdio.h>
struct circle{
    int x1, x2, y1, y2;
}mafia[10000];
int i, j, amountm, side1, side2, x, y, radius, count, max;

int main()
{
    scanf("%d %d %d",&side1,&side2,&amountm);

    for( i = 0 ; i < amountm ; i++ ){
        scanf("%d %d %d",&x,&y,&radius);

        mafia[i].x1 = x - radius;
        mafia[i].y1 = y - radius;
        mafia[i].x2 = x + radius;
        mafia[i].y2 = y + radius;
    }

    for( i = 0 ; i <= side1 ; i++ ){
            count = 0;
        for( j = 0 ; j < amountm ; j++ ){
            if( i >= mafia[j].x1 && i <= mafia[j].x2 ){
                count++;
            }
        }
        if( max < count ){
            max = count;
        }
    }
    for( i = 0 ; i <= side2 ; i++ ){
            count  = 0;
        for( j = 0 ; j < amountm ; j++ ){
            if( i >= mafia[j].y1 && i <= mafia[j].y2 ){
                count++;
            }
        }
        if( max < count ){
            max = count;
        }
    }
    printf("%d",max);

    return 0;
}
