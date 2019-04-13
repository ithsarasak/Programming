#include<bits/stdc++.h>

using namespace std ;
const int MAXN = 100000 + 10;
int par[MAXN] , value[MAXN];
vector<int> E[MAXN];
int DP[MAXN][2] ;

void dp(int u){

    DP[u][0] = 0 ;
    DP[u][1] = value[u];

    for(int i = 0 ; i < E[u].size() ; i ++){
        int v = E[u][i];
        dp(v);
        DP[u][0] += max(DP[v][0],DP[v][1]);
        DP[u][1] += DP[v][0];
    }
}

int main(){
    int n ;
    cin >> n ;
    cin >> value[0];
    for(int i = 1 ; i < n ; i ++){
        int x ;
        cin >> x >> value[i];
        E[x].push_back(i);
    }
    dp(0);
    printf("%d\n",max(DP[0][0],DP[0][1]));

}
