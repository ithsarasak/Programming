#include<stdio.h>
#include<vector>

using namespace std;

int n,i,x,dp[500010],check[500010],p,q,m,k,t,max2=0;
vector <int> a[500001];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(i = 0; i < m; i++) {
        scanf("%d%d",&p,&q);
        if(p > q) t = p,p = q,q = t;
        a[p].push_back(q);
    }
    for(i = 0; i < k; i++){
        scanf("%d",&x);
        check[x] = 1;
    }
    dp[1] = 1;
    for(i = 1; i <= n; i++){
        if(dp[i] > 0){
            if(i > max2) max2 = i;
            if(!check[i]){
                dp[i + 1] = 1;
            }
            for(x = 0; x < a[i].size(); x++){
                dp[a[i][x]] = 1;
            }
        }
    }
    if(max2 == n){
        printf("1\n");
    }
    else
    printf("%d %d\n",0,max2);
}
