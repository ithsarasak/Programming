#include<bits/stdc++.h>

using namespace std;
int n, temp, ans;
int buc[1000100];
int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ){
        scanf("%d",&temp);
        if( buc[temp+1] ){
            buc[temp+1]--;
            buc[temp]++;
        }
        else{
            buc[temp]++;
            ans++;
        }
    }
    printf("%d",ans);
    return 0;
}
