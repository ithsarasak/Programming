#include<bits/stdc++.h>

using namespace std;
struct qq{
    int va, idx;
};
deque<qq> q;
int n, num[100010];
int sum, sum2;
int main()
{
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; i++ ){
        scanf("%d",&num[i]);
        sum += num[i];
    }
    if( sum % 2 ){
        printf("NO");
        return 0;
    }
    for( int i = 1 ; i <= n ; i++ ){
        while( sum2 + num[i] > sum / 2 && !q.empty() ){
            sum2 -= q.front().va;
            q.pop_front();
        }
        q.push_back({ num[i], i });
        sum2 += num[i];
        if( sum2 == sum / 2 ){
            if( q.front().idx != 1 ){
                printf("%d ",q.front().idx-1);
            }
            printf("%d",q.back().idx);
            return 0;
        }
    }
    printf("NO");
    return 0;
}
