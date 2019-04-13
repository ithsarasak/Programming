#include<bits/stdc++.h>

using namespace std;
int x, score[5], pos = -1, sum;
int main()
{
    scanf("%d",&x);
    for( int i = 0 ; i < 5 ; i++ ){
        scanf("%d",&score[i]);
        sum += score[i];
    }
    if( x > sum ){
        printf("-1");
        return 0;
    }
    if( x == sum ){
        for( int i = 0 ; i < 5 ; i++ ){
            printf("%d ",score[i]);
        }
        return 0;
    }
    for( int i = 4 ; i >= 0 ; i-- ){
        //printf("%d",i);
        if( score[i] == sum - x ){
            pos = i;
        }
    }
    if( pos == -1 ){
        printf("-1");
        return 0;
    }
    score[pos] = 0;
    for( int i = 0 ; i < 5 ; i++ ){
        printf("%d ",score[i]);
    }
    return 0;
}
