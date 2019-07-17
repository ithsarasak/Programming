#include<bits/stdc++.h>

using namespace std;
int q, n, mic[12];
int main()
{
    mic[0] = 1;
    for( int i = 1 ; i <= 11 ; i++ ){
        for( int j = 0 ; j < i ; j++ ){
            mic[i] += mic[j] * mic[i - j - 1];
        }
    }
    while( scanf("%d",&n) != EOF ){
        printf("%d\n\n",mic[n]);
    }
    return 0;
}
