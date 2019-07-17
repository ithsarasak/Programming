#include<stdio.h>
int n, k, a, i, j, diary[150], mark[50000], count = 1, count2 = 1, max, minpage = 1;
int main()
{
    scanf("%d %d %d",&n,&k,&a);
    for( i = 1 ; i <= n ; i++ ){
        scanf("%d",&diary[i]);
    }
    for( i = 1 ; i <= n ; i++ ){
        for( j = 1 ; j <= diary[i] ; j++ ){
            mark[count] = count2;
            count++;
        }
        count2++;
    }
    for( i = 1 ; i <= count - 1 ; i++ ){
        int num = k - 1, prev = mark[i], j = i, count2 = 1;
        while( num > 0 && j + a <= count - 1 ){
            j += a;
            if( mark[j] != prev ){
                count2++;
            }
            num--;
            prev = mark[j];
        }
        if( max < count2 ){
            max = count2;
            minpage = i;
        }
        //printf("%d %d %d %d\n", i, max, minpage,mark[i]);
    }
    printf("%d %d",minpage, max);
    return 0;
}
