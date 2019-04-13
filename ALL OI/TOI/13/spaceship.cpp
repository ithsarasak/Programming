#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

struct vertex{
    int x, y, z;
    int moni, key, mach;
}point[10];
int computer, mins = 2000000001;
int ashop, sx, sy, sz, hx, hy, hz, c;
int i, j, k;
int num[15], summoni, sumkey, summach, mindis;

int main()
{
    scanf("%d",&computer);

    scanf("%d %d %d",&sx,&sy,&sz);
    hx = sx;
    hy = sy;
    hz = sz;

    scanf("%d",&ashop);

    for( i = 0 ; i < ashop ; i++ )
    {
        scanf("%d %d %d",&point[i].x,&point[i].y,&point[i].z);
        scanf("%d %d %d",&point[i].moni,&point[i].key,&point[i].mach);
        num[i] = i + 1 ;
    }

    do{
        /*printf("num : ");
        for( j = 0 ; j < ashop ; j++ )
        {
            printf("%d ",num[j]);
        }
        printf("\n");*/
        for( j = 0 ; j < ashop ; j++ )
        {
            summoni += point[num[j]-1].moni;
            sumkey += point[num[j]-1].key;
            summach += point[num[j]-1].mach;
            mindis += ( ( ( point[num[j] - 1].x - hx ) * ( point[num[j] - 1].x - hx ) ) + ( ( point[num[j] - 1].y - hy ) * ( point[num[j] - 1].y - hy ) ) +  ( ( point[num[j] - 1].z - hz ) * ( point[num[j] - 1].z - hz ) ) );
            //printf("mindis : %d\n",mindis);

            if( summoni >= computer && sumkey >= computer && summach >= computer )
            {
                if( mins > mindis )
                {
                    mins = mindis;
                    //printf("min : %d\n",mins);
                }
                break;
            }
            hx = point[num[j] - 1].x;
            hy = point[num[j] - 1].y;
            hz = point[num[j] - 1].z;
        }
        summoni = 0;
        sumkey = 0;
        summach = 0;
        hx = sx;
        hy = sy;
        hz = sz;
        mindis = 0;
    }while( next_permutation( num , num + ashop ) );

    printf("%d",mins);
    return 0;
}

