#include<bits/stdc++.h>

using namespace std;
int n, k, i;
unsigned long long t1 = 1, t2 = 1;
int main()
{
    scanf("%d %d",&k,&n);
    if( k < n / 2 ){
        for( i = n - k + 1 ; i <= n ; i++ ){
            t1 *= i;
        }
        for( i = 2 ; i <= k ; i++  ){
            t2 *= i;
        }
        cout << t1 / t2;
    }
    else{
        for( i = k + 1 ; i <= n ; i++ ){
            t1 *= i;
        }
        for( i = 2 ; i <= n - k ; i++ ){
            t2 *= i;
        }
        cout << t1 / t2;
    }
    return 0;
}
