#include<bits/stdc++.h>

using namespace std;
int y, p, pope[1000010], mx, ans, f, t, mn = 1e9;
int main()
{
    while( scanf("%d", &y) != EOF ){
        scanf("%d",&p);
        mx = -1, mn = 1e9, ans = -1;
        memset( pope, 0, sizeof pope );
        for( int i = 0 ; i < p ; i++ ){
            int t;
            scanf("%d",&t);
            pope[t]++;
            mx = max( mx, t );
            mn = min( mn, t );
        }
        int sum = 0;
        for( int i = mn ; i <= mx ; i++ ){
            if( i >= mn + y ){
                sum += pope[i] - pope[i-y];
                if( ans < sum ){
                    ans = sum;
                    f = i-y+1, t = i;
                }
            }
            else{
                sum += pope[i];
                if( ans < sum ){
                    ans = sum;
                    f = mn, t = i;
                }
            }
        }
        for( int j = f ; j <= t ; j++ ){
            if( pope[j] ){
                f = j;
                break;
            }
        }
        printf("%d %d %d\n",ans,f,t);
    }
    return 0;
}
