#include<bits/stdc++.h>

using namespace std;
double num[101000], cnt;
int q, n;
int main()
{
    cnt = 1.0;
    for( int i = 1 ; i <= 100000 ; i++ ){
        num[i] = num[i-1] + log10( cnt );
        cnt += 1.0;
        //printf("%f\n",num[i]);
    }
    /*for( int i = 1 ; i <= 100 ; i++ ){
        printf("%.0f ",num[i]);
    }*/
    scanf("%d",&q);
    while( q-- ){
        scanf("%d",&n);
        printf("%.0f\n",ceil( num[n]) );
    }
    return 0;
}
