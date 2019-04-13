#include <bits/stdc++.h>

using namespace std;
const int mod = 1e4+1;
int q, n, mic[1010];
int main()
{
    mic[0] = 1;
    for( int i = 1 ; i <= 1010 ; i++ ){
        for( int j = 0 ; j < i ; j++ ){
            mic[i] += mic[j] * mic[i - j - 1];
            mic[i] %= mod;
        }
    }
    scanf("%d",&n);
    printf("%d",mic[n]);
    return 0;
}
