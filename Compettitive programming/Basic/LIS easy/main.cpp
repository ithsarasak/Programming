#include<stdio.h>
#include<stack>

using namespace std;

stack<int> ans;
int i,j, maxs;
int dp[1010], path[1010], num[1010];
int amount;
int main()
{
    scanf("%d",&amount);
    for( i = 1 ; i <= amount ; i++ ){
        scanf("%d",&num[i]);
    }
    dp[1] = 1;
    path[1] = 0;
    maxs = 1;
    for( i = 2 ; i <= amount ; i++ ){
        for( j = 1 ; j < i ; j++ ){
            if( num[j] < num[i] && dp[j] + 1 > dp[i] ){
                dp[i] = dp[j] + 1;
                path[i] = j;
            }
        }
        if( dp[i] == 0 ){
            dp[i]++;
        }
        if( maxs < dp[i] ){
            maxs = dp[i];
        }
    }
    for( i = 1 ; i <= amount ; i++ ){
        //printf("%d ",dp[i]);
        if( dp[i] == maxs ){
            printf("%d\n",maxs);
            while( path[i] != 0 ){
                ans.push( num[i] );
                i = path[i];
            }
            ans.push( num[i] );
            break;
        }
    }
    int sizes = ans.size();
    for( i = 0 ; i < sizes ; i++ ){
        int t = ans.top();
        printf("%d ",t);
        ans.pop();
    }
    return 0;
}
