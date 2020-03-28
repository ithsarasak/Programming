#include <bits/stdc++.h>

using namespace std;

int k, n;
int main()
{
    scanf("%d %d",&k,&n);
    for( int i = 1 ; i < n ; i++ ) printf("%d\n",i);
    printf("%d\n",k - (n*(n-1))/2 );
    return 0;
}