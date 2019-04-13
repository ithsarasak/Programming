#include<bits/stdc++.h>

using namespace std;
int n, buc[4010], f, ans, st;
int main()
{
    scanf("%d",&n);
    while( n-- ){
        int t;
        scanf("%d",&t);
        buc[t]++;
    }
    while( f <= 2017 ){
        if( buc[2017 - f] == 1 ){
            printf("%d",2017-f);
            return 0;
        }
        else if( buc[2017+f] == 1 ){
            printf("%d",2017+f);
            return 0;
        }
        else if( buc[2017-f] > 0 ){
            ans = -1;
        }
        else if( buc[2017+f] > 0 ){
            ans = -1;
        }
        f++;
    }
    printf("%d",ans);
    return 0;
}

