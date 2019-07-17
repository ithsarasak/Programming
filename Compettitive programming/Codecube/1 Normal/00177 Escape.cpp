#include<bits/stdc++.h>

using namespace std;
int n, m, ma[1010][1010], mic[1010][1010];
int mod = 1e9+7;
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&ma[i][j]);
        }
    }
    for(int j=1;j<=m;j++) if(ma[1][j]==0) mic[1][j]=1;
    for(int i=1;i<=n;i++) if(ma[i][1]==0) mic[i][1]=1;
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            if(ma[i][j]==0) mic[i][j]=mic[i-1][j]+mic[i][j-1];
            mic[i][j] %= mod;
        }
    }
    printf("%d",mic[n][m]);
    return 0;
}
