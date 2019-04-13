#include <bits/stdc++.h>

using namespace std;

int n, k, i, sum[50000], temp;

int main()
{
    scanf("%d %d",&n,&k);
    for( i = 1 ; i <= n ; i++ ){
        scanf("%d",&temp);
        sum[i] = temp + sum[i - 1];
    }
    for( i = 0 ; i < k ; i++ ){
        scanf("%d",&temp);
        int first = 1;
        int last = n, mid;
        if( temp > sum[n] ){
            printf("%d\n",n);
        }
        else if( temp < sum[1] ){
            printf("%d\n",0);
        }
        else{
            while( 1 ){
                mid  = ( first + last ) / 2;
                if( sum[first] == temp ){
                    printf("%d\n",first);
                    break;
                }
                else if( sum[last] == temp ){
                    printf("%d\n",last);
                    break;
                }
                else if( sum[mid] == temp ){
                    printf("%d\n",mid);
                    break;
                }
                if( first + 1 == last ){
                    printf("%d\n",first);
                    break;
                }
                else if( sum[mid] > temp ){
                    last = mid;
                }
                else if( sum[mid] < temp ){
                    first = mid;
                }
            }
        }
    }
    return 0;
}
