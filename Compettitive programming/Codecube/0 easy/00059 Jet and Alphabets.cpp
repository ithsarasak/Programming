#include<bits/stdc++.h>

using namespace std;
int n, m, now = 65;
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < m ; j++ ){
            printf("%c",now);
            if( now == 90 ){
                now = 65;
            }
            else{
                now++;
            }
        }
        printf("\n");
    }
}
