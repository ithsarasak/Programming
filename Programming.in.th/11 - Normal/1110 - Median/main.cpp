#include<stdio.h>
#include<math.h>

long long ans;
long long i, j, k, count1[500005][2], count2[500005][2], n, f, arr[1000005], pos, count, qsum1, qsum2, max;

int main()
{
    scanf("%lld %lld",&n,&f);
    for( i = 0 ; i < n ; i++ ){
        scanf("%lld",&arr[i]);
        if( !count ){
            if( arr[i] == f ){
                pos = i;
                count = 1;
                for( j = pos - 1 ; j >= 0 ; j-- ){
                    if( arr[j] > f ){
                        qsum1++;
                    }
                    else{
                        qsum1--;
                    }
                    if( qsum1 > max ){
                        max = qsum1;
                    }
                    if ( qsum1 >= 0 ){
                        count1[ qsum1 ][0]++;
                    }
                    else{
                        count1[ qsum1 * ( -1 ) ][1]++;
                    }
                }
            }
        }
        else{
            if( arr[i] > f ){
                qsum2++;
            }
            else{
                qsum2--;
            }
            if( qsum2 > max ){
                max = qsum2;
            }
            if( qsum2 >= 0 ){
                count2[qsum2][0]++;
            }
            else{
                count2[qsum2*(-1)][1]++;
            }
        }
    }
    for( i = 1 ; i <= max ; i++ ){
        ans += ( long long )( count1[i][1] * count2[i][0] );
        ans += ( long long )( count2[i][1] * count1[i][0] );
    }
    ans = ans + count1[0][0] + count2[0][0]+1+( long long )( count1[0][0] * count2[0][0] );
    printf("%lld",ans);
	return 0;
}
