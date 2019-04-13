#include<bits/stdc++.h>

using namespace std;
int t;
long long pos[5], mx, now, help;
int main()
{
    scanf("%d",&t);
    for( int i = 0 ; i < 3 ; i++ ){
        scanf("%d",&pos[i]);
    }
    for( int i = 1 ; i <= t ; i++ ){
        /*printf("%d : ",i);
        for( int j = 0 ; j < 3 ; j++ ){
            printf("%lld ",pos[j]);
        }
        printf("\n");*/
        if( pos[0] == pos[1] && pos[1] == pos[2] )break;
        if( pos[now]  >= pos[(now+1)%3] && pos[now] >= pos[(now+2)%3] ){
            now++;
            now %= 3;
            continue;
        }
        if( pos[(now+1)%3] > pos[now] && pos[(now+2)%3] > pos[now] ){
            help = min( pos[(now+1)%3], pos[(now+2)%3] );
        }
        else{
            help = max( pos[(now+1)%3], pos[(now+2)%3] );
        }
        pos[now] += 2*( help - pos[now] );
        now++;
        now %= 3;
    }
    for( int i = 0 ; i < 3 ; i++ ){
        printf("%lld\n",pos[i]);
    }
    return 0;
}
