#include<bits/stdc++.h>
int m, n, i, j, first, last, mid, scoreg[200010], scorek[200010];
int main()
{
    scanf("%d %d",&m,&n);
    for( i = 0 ; i < m ; i++ ){
        scanf("%d",&scoreg[i]);
    }
    for( j = 0 ; j < n ; j++ ){
        scanf("%d",&scorek[i]);
        if( scorek[i] >= scoreg[m - 1] ){
            printf("1\n");
        }
        else if( scorek[i] < scoreg[ 0 ] ){
            printf("%d\n",m + 1);
        }
        else{
            first = 0;
            last = m - 1;
            while( 1 ){
                mid = ( first + last ) / 2;
                if( first + 1 == last ){
                    printf("%d\n", m - last + 1);
                    break;
                }
                if( scoreg[mid] > scorek[i] ){
                    last = mid;
                }
                else{
                    first = mid;
                }
            }
        }
    }
    return 0;
}
