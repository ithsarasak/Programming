#include<stdio.h>

int station, i, j, k, electric[1000001], mincost[1000001], min, mix;
int main()
{
    scanf("%d",&station);
    scanf("%d",&k);

    for( i = 0 ; i < station ; i++ ){
        scanf("%d",&electric[i]);

        if( i == 0 ){
            mincost[i] = electric[i];
            min = mincost[i];
        }
        else{
            //printf("min :  %d\n",min);
            if( mix >= i - k ){
                mincost[i] = min + electric[i];
            }
            else{
                min = 999999999;
                for( j = i - 1 ; j >= i - k ; j-- ){
                    if( j < 0 ){
                        break;
                    }
                    //printf("electic[%lld] : %lld",j,electric[j]);
                    if( min > mincost[j] ){
                        //printf("electic[%lld] : %lld",j,electric[j]);
                        min = mincost[j];
                        mix = j;
                    }
                }
                //printf("min : %lld\n",min);
                mincost[i] = min + electric[i];
            }
        }
    }
    printf("%d",mincost[station-1]);
    return 0;
}
