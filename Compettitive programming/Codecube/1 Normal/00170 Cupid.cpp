	#include<bits/stdc++.h>
using namespace std;
struct people
{
    int m,f;
}land[1002];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int sum_m=0,sum_f=0;
    for(int i=1;i<=n;i++)
    {
        int m,f;
        scanf("%d%d",&land[i].m,&land[i].f);
        sum_m+=land[i].m;
        sum_f+=land[i].f;
    }
    if(sum_f!=sum_m) printf("NO");
    else
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=max(1,i-k);j<=min(n,i+k);j++)
            {
                    if(land[i].m>=land[j].f) {land[i].m-=land[j].f; land[j].f=0;}
                    else {land[j].f-=land[i].m; land[i].m=0;}
            }
        }
        bool ans=true;
        for(int i=1;i<=n;i++)
            if(land[i].m>0||land[i].f>0) ans=false;
        if(ans) printf("YES"); else printf("NO");
    }
}

