#include<bits/stdc++.h>
using namespace std;
int ant[50005];
int check[50005];
int par[50005];
int root(int i)
{
    while(i!=par[par[i]])
    {
        par[i]=par[par[i]];
        i=par[par[i]];
    }
    return i;
}
void mergeset(int a,int b)
{
    par[root(b)]=root(a);
}
struct e
{
    int u,v,w;
}edge[70005];
bool cmp(e x,e y)
{
    return x.w>y.w;
}
int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++)
        cin >> ant[i];
    for(int i=1;i<=m;i++)
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
        sort(edge+1,edge+m+1,cmp);
    int first=1,last=1e9,ans=0;
    while(first<=last)
    {
        int mid=(first+last)/2,cnt=0;
        for(int i=1;i<=n;i++)
            par[i]=i;
        for(int i=1;i<=m;i++)
        {
            e now=edge[i];
            int x=now.u,y=now.v,d=now.w;
            if(d<=mid) {cnt=m-i+1; break;}
            if(root(x)!=root(y)) mergeset(x,y);
        }
        bool q=true;
        for(int i=1;i<=n;i++)
        {
            if(check[ant[i]]==0) check[ant[i]]=root(i);
            else if(check[ant[i]]!=root(i)) {q=false; break;}
        }
        if(q) {first=mid+1; ans=cnt;}
        else last=mid-1;
        for(int i=1;i<=k;i++)
            check[i]=0;
    }
    cout << ans;
}
