#include<bits/stdc++.h>

using namespace std;
int lis[500010];
int li[500010], n, s;
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d",&li[i]);
    }
    lis[s] = li[0];
    s++;
    for( int i = 1 ; i < n ; i++ ){
        if( li[i] > lis[s-1] ){
            lis[s] = li[i];
            s++;
        }
        else{
            int idx = upper_bound( lis, lis + s, li[i] ) - lis;
            lis[idx] = li[i];
        }
    }
    printf("%d",n-s);
    return 0;
}
