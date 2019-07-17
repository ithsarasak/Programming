#include<bits/stdc++.h>

using namespace std;
long long n, mic[1010];
int main()
{
    mic[0] = 1;
    for( int i = 1 ; i <= 1000 ; i++ ){
        for( int j = 0 ; j < i ; j++ ){
            mic[i] += mic[j] * mic[i - j - 1];
            mic[i] %= 10001;
        }
    }
    scanf("%lld",&n);
    printf("%lld\n",mic[n]);
    return 0;
}
