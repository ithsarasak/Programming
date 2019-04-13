#include<bits/stdc++.h>

using namespace std;

int n, k, i, j, temp, counts, count2;
long long sum[1500];
struct dif{
    long long diff, book;
    bool operator<( const dif &k )const{
        return diff < k.diff;
    }
}differ[510000], com[510000];
int main()
{
    scanf("%d %d",&n,&k);
    for( i = 1 ; i <= n ; i++ ){
        scanf("%d",&temp);
        sum[i] = sum[i - 1] + temp;
    }
    for( i = 1 ; i <= n ; i++ ){
        for( j = i ; j <= n ; j++ ){
            differ[counts].diff = sum[j] - sum[i - 1];
            differ[counts].book = j - i + 1;
            counts++;
        }
    }
    sort( differ , differ + counts );
   /* for( i = 0 ; i < counts ; i++ ){
        printf("%d %d\n",differ[i].diff,differ[i].book);
    }
    printf("\n");*/
    com[0] = differ[0];
    count2 = 1;
    for( i = 1 ; i < counts ; i++ ){
        if( differ[i].diff != differ[ i - 1 ].diff ){
            com[count2] = differ[i];
            count2++;
        }
        else if( differ[i].diff == com[count2 - 1].diff && differ[i].book > com[count2 - 1].book ){
            com[count2 - 1] = differ[i];
        }
    }
    for( i = 1 ; i < count2 ; i++ ){
        //printf("%d ",com[i].diff);
        if( com[i].book < com[i - 1].book ){
            com[i].book = com[i - 1].book;
        }
    }
    /*for( i = 0 ; i < count2 ; i++ ){
        printf("%d %d\n",com[i].diff,com[i].book);
    }
    printf("\n");*/
    for( i = 0 ; i < k ; i++ ){
        scanf("%d",&temp);
        if( temp < com[0].diff ){
            printf("0\n");
        }
        else if( temp > com[count2 - 1].diff ){
            printf("%d\n",n);
        }
        else{
            int first = 0, last = count2 - 1, mid;
            while( 1 ){
                mid  = ( first + last ) / 2;
                if( com[first].diff == temp ){
                    printf("%lld\n",com[first].book);
                    break;
                }
                else if( com[last].diff == temp ){
                    printf("%lld\n",com[last].book);
                    break;
                }
                else if( com[mid].diff == temp ){
                    printf("%lld\n",com[mid].book);
                    break;
                }
                if( first + 1 == last ){
                    printf("%lld\n",com[first].book);
                    break;
                }
                else if( com[mid].diff > temp ){
                    last = mid;
                }
                else if( com[mid].diff < temp ){
                    first = mid;
                }
            }
        }
    }
    return 0;
}
