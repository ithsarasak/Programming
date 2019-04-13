#include<stdio.h>
int n,i,x,check[2000010];
int dfs(int num,int d){
    if(d >= 30) { return 0;}
    if(num == n){ printf("%d ",num); return 1;}


        if(dfs(2 * num,d + 1) == 1){
            printf("%d ",num);
            return 1;
        }

        if(dfs(num / 3,d + 1)){
            printf("%d ",num);
            return 1;
        }

    return 0;
}
int main(){
    scanf("%d",&n);
    dfs(1,0);
}
