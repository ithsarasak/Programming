#include <stdio.h>

long long n, mic[32];
int i, j;

int main()
{
    scanf("%lld",&n);
    mic[0] = 1;
    for( i = 1 ; i <= 32 ; i++ ){
        for( j = 0 ; j < i ; j++ ){
            mic[i] += mic[j] * mic[i - j - 1];
        }
    }
    printf("%lld",mic[n]);
    return 0;
}
