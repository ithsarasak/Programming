#include<bits/stdc++.h>

using namespace std;
int n, mi = 2000000001, ma = -2000000001;
int num[1000010];
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d",&num[i]);
        if( mi > num[i] ){
            mi = num[i];
        }
        if( ma < num[i] ){
            ma = num[i];
        }
    }
    printf("%d\n%d",ma,mi);
    return 0;
}
