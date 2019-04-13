#include<bits/stdc++.h>

using namespace std;
char wrong[1000010], righ[1000010];
int ans[1000010], c;
int main()
{
    scanf("%s",wrong);
    scanf("%s",righ);
    int len = strlen( wrong );
    for( int i = 0 ; i < len ; i++ ){
        wrong[i] = tolower( wrong[i] );
        righ[i] = tolower( righ[i] );
        if(( wrong[i] - righ[i] > 9 || wrong[i] - righ[i] < 0 ) && ( wrong[i] + 26 - righ[i] > 9 || wrong[i] + 26 - righ[i] < 0 )){
            printf("R.I.P.\n");
            return 0;
        }
        else{
            if( wrong[i] - righ[i] >= 0 ){
                ans[c] = wrong[i] - righ[i];
            }
            else{
                ans[c] = wrong[i] - righ[i] + 26;
            }
            c++;
        }
    }
    for( int i = 0 ; i < c ; i++ ){
        printf("%d",ans[i]);
    }
    return 0;
}
