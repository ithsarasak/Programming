#include<bits/stdc++.h>
using namespace std;
int ex[100100],p[100100],mark[100100],temp[100100];
int main()
{
    int n,k,i,l,r,mid,pw,ch,cnt;
    scanf(" %d %d",&n,&k);
    for(i=1;i<=n;i++){
        scanf(" %d",&ex[i]);
    }
    for(i=1;i<=k;i++){
        scanf(" %d",&p[i]);
    }
    l=1; r=n;
    while(l<r){
        memset(temp,0,sizeof temp);
        memset(mark,0,sizeof mark);
        mid=(l+r)/2;
        cnt=0;
        for(i=1;i<=mid;i++){
            if(ex[i]==0) continue;
            if(mark[ex[i]]==0){
                cnt++;
            }
            mark[ex[i]]=i;
        }
        if(cnt<k){
            l=mid+1;
            continue;
        }
        for(i=1;i<=k;i++){
            temp[mark[i]]=i;
        }
        pw=0; ch=1;
        for(i=1;i<=mid;i++){
            if(temp[i]==0){
                pw++;
            }else{
                if(p[temp[i]]>pw){
                    ch=0;
                    break;
                }
                pw-=p[temp[i]];
            }
        }
        if(ch) r=mid;
        else l=mid+1;
    }
    printf("%d",l);
    return 0;
}
