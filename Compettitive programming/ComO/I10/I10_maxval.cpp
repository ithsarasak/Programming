#include<bits/stdc++.h>

using namespace std;
int n, k;
int num[1000100];
int sum = 0;
int mx = -2000000001;
int main()
{
    scanf("%d %d",&n,&k);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&num[i]);
        if( i < k )sum += num[i];
        else{
            sum += num[i];
            mx = max( mx, sum );
            sum -= num[i-k+1];
        }
    }
    cout << mx;
}
