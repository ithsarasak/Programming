#include<bits/stdc++.h>

using namespace std;
int n, q;
int num[100100], num2[100100];
vector<int> po[100100];
int main()
{
    scanf("%d %d",&n,&q);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d",&num[i]);
        num2[i] = num[i];
    }
    sort( num2, num2 + n );
    for( int i = 0 ; i < n ; i++ ){
        num[i] = lower_bound( num2, num2 + n, num[i] ) - num2;
        po[num[i]].push_back( i );
    }
    for( int i = 0 ; i < q ; i++ ){
        int l, r, c;
        scanf("%d %d %d",&l,&r,&c);
        int idx = lower_bound( num2, num2 + n, c ) - num2;
        if( num2[idx] != c ){
            printf("0\n");
            continue;
        }
        int idx2 = lower_bound( po[idx].begin(), po[idx].end(), l - 1 ) - po[idx].begin();
        int idx3 = upper_bound( po[idx].begin(), po[idx].end(), r - 1 ) - po[idx].begin();
        printf("%d\n",idx3-idx2);
    }
    return 0;
}

