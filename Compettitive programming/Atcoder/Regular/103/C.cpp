#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int n, cnt1[N], cnt2[N];
int main()
{
    scanf("%d",&n);
    for( int i = 1, x ; i <= n ; i++ ) {
        scanf("%d",&x);
        if( i % 2 ) cnt1[x]++;
        else cnt2[x]++;
    }
    
    return 0;
}