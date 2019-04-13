#include<bits/stdc++.h>

using namespace std;
int se[1010], n, k;
int main()
{
    scanf("%d %d",&n,&k);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d",&se[i]);
    }
    while( k-- ){
        for( int i = 0 ; i < n ; i++ ){
            if( se[i] > se[i + 1] ){
                for( int j = i ; j < n ; j++ ){
                    se[j] = se[j+1];
                }
                break;
            }
        }
        n--;
    }
    for( int i = 0 ; i < n ; i++ ){
        printf("%d ",se[i]);
    }
    return 0;
}
