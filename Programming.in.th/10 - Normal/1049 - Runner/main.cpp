#include<stdio.h>
#include<string.h>
#include<math.h>

int n, m, win[100002], a, l, s, max[100002]={}, i, count[100002]={}, j=0, check[100002]={}, lane[100002];
int main()
{
    scanf("%d %d",&n,&m);
    for( i = 1 ; i <= n ; i++ ){
        scanf("%d %d %d",&a,&l,&s);
        count[l]++;
        if( count[ l ] > j ){
            j = count[ l ];
        }
        if( max[ count[ l ] ] < s ){
            check[ count[ l ] ] = 1;
            win[ count[ l ] ] = a;
            lane[ count[ l ] ] = l;
            max[ count[ l ] ] = s;
        }
        if( max[ count[ l  ] ] == s ){
            if( l < lane[ count[ l ] ] ){
                win[ count[ l ] ] = a;
            }
        }
        //printf("%d %d\n",max[count[l]],count[l]);
    }
    for( i = 1 ; i <= j ; i++ ){
        printf("%d\n",win[i]);
    }
}
