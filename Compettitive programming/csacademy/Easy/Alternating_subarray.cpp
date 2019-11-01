#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int n, num[N], mx, now = 1;
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ) {
        scanf("%d",&num[i]);
        if( i > 1 ) {
            if( i == 2 ) {
                if( num[i] == num[i-1] ) now = 1;
                else now = 2;
            } 
            else {
                if( num[i] == num[i-1] ) now = 1;
                else if( num[i] < num[i-1] == num[i-1] < num[i-2]  ) now = 2;
                else now+= 1;
            } 
        }
        mx = max( mx, now );
    }
    printf("%d",mx);
    return 0;
}