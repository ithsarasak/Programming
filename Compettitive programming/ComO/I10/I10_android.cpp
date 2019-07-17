#include<bits/stdc++.h>
using namespace std;
int mem[1005];
int last[1005];
int main()
{
    int p,s,m;
    scanf("%d%d%d",&p,&s,&m);
    for(int i=1;i<=p;i++) scanf("%d",&mem[i]);
    int now=0;
    for(int i=1;i<=s;i++)
    {
        int w;
        scanf("%d",&w);
        while(now+mem[w]>m) {
        int mn=1e8,to_delete;
        for(int j=1;j<=p;j++)
            if(mn>last[j]&&last[j]>0) { mn=last[j]; to_delete=j; }
        now-=mem[to_delete]; last[to_delete]=0;
        }
        if(last[w]==0) now+=mem[w];
        last[w]=i;
    }
    printf("%d",m-now);
}

