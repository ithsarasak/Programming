#include<bits/stdc++.h>

using namespace std;
int n, b, k, bucket[500010];
int main()
{
    scanf("%d",&n);
    scanf("%d",&b);
    for( int i = 2 ; i <= n ; i++){
        if( !bucket[i] ){
            //printf("%d\n",i);
            for( int j = i ; j <= n ; j += i ){
                bucket[j] = 1;
            }
            k++;
        }
    }
    printf("%d",max( k - b , 0 ));
    return 0;
}
