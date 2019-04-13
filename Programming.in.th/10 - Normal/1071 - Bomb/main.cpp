#include<stdio.h>
int a[1001][1001];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int x,y;
    for(int i=0;i<n;i++){
        scanf("%d%d",&x,&y);
        a[x][y]=1;
    }
    int z,t=0;
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&x,&y,&z);
        t=0;
        for(int j=x-z;j<=x+z;j++){
            for(int k=y-z;k<=y+z;k++){
                if(j>=0&&j<=1000&&k>=0&&k<=1000){
                    if(a[j][k]){
                        t++;
                        a[j][k]=0;
                    }
                }
            }
        }
        printf("%d\n",t);
    }
    return 0;
}
