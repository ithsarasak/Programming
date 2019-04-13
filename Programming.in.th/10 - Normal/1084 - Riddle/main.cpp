#include<stdio.h>

int sum, i, j, x, y, k, temp, f, d[15];

int main()
{
    scanf("%d %d %d",&x,&y,&k);
    int f = 5;
    for( i = 0 ; i < 13 ; i++ ){
        d[i] = f;
        f *= 5;
        //printf("%d\n",d[i]);
    }
    j = 0;
    while( j < 13 ){
        sum += x / d[j];
        j++;

    }
    temp = sum;
    /*printf("%d ",sum);
    printf("%d\n",temp);*/
    //return 0;
    for( i = x + 1 ; i <= y ; i++ ){
        //printf("%d\n",i%125);
        if( i % 25 == 0 ){
            j = 0;
            temp = 0;
            while( j < 13 ){
                temp += i / d[j];
                j++;
            }
            //printf("%d\n",temp);
        }
        else if( i % 5 == 0 ){
            temp += 1;
        }
        sum += temp;
        sum %= k;
        /*printf("%d ",sum);
        printf("%d\n",temp);*/
    }

    printf("%d",sum%k);
}
