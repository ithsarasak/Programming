#include<bits/stdc++.h>

using namespace std;
int n, mi, li, ma;
int num[10100];
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d",&num[i]);
    }
    for( int i = 0 ; i < n ; i++ ){
        if( num[i] == 10 )li++;
        else if( num[i] == 13 ){
            if( num[i+1] == 10 )mi++;
            ma++;
        }
    }
    printf("%d %d %d",mi+1,li+1,ma+1);
    return 0;
}
