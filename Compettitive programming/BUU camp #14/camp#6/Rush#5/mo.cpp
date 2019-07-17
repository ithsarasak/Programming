#include<bits/stdc++.h>

using namespace std;
int n, k;
int num[5500], num2[5500];
vector<int> lis;
int main()
{
    scanf("%d %d",&n,&k);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&num[i]);
        num2[i] = num[i];
    }
    sort( num2 + 1, num2 + n + 1 );
    for( int i = 1 ; i <= n ; i++ ){
        int idx = lower_bound( num2 + 1, num2 + 1 + n, num[i] ) - num2;
        //printf("%d\n",idx);
        num[i] = ( ceil )( ( double )idx / ( double )k );
    }
    lis.push_back( num[1] );
    /*for( int i = 1 ; i <= n ; i++ ){
        printf("%d ",num[i]);
    }
    printf("\n");*/
    for( int i = 2 ; i <= n ; i++ ){
        if( num[i] < lis[0] )lis[0] = num[i];
        else if( num[i] >= lis[lis.size()-1] )lis.push_back( num[i] );
        else{
            int idx = upper_bound( lis.begin(), lis.end(), num[i] ) - lis.begin();
            lis[idx] = num[i];
        }
    }
    printf("%d",n-lis.size());
    return 0;
}
