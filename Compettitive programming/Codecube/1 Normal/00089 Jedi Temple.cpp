#include<bits/stdc++.h>

using namespace std;
int n, m;
int num[1010], temp[1010];
int main()
{
    scanf("%d %d",&n,&m);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d",&num[i]);
    }
    for( int i = 0 ; i < m ; i++ ){
        int f, t, c = 0, co;
        scanf("%d %d",&f,&t);
        co = t;
        f -= 1;
        for( int j = 0 ; j < t ; j++ ){
            temp[c] = num[f];
            f++;
            f %= n ;
            c++;
        }
        f += n - 1;
        f %= n;
        for( int j = 0 ; j < c ; j++ ){
            num[f] = temp[j];
            f += n - 1;
            f %= n;
        }
    }
    for( int i = 0 ; i < n ; i++ ){
        printf("%d ",num[i]);
    }
    return 0;
}
