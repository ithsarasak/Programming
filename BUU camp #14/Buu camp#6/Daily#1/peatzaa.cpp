#include<bits/stdc++.h>

using namespace std;
int q, n, mic[1010];
int main()
{
    mic[0] = 1;
    for( int i = 1 ; i < 1010 ; i++ ){
        for( int j = 0 ; j < i ; j++ ){
            mic[i] += mic[j] * mic[i - j - 1];
            mic[i] %= 9973;
        }
    }
    scanf("%d",&q);
    for( int i = 0 ; i < q ; i++ ){
        scanf("%d",&n);
        printf("%d\n",mic[n-1]);
    }
    return 0;
}
