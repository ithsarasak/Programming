#include<bits/stdc++.h>
using namespace std;
char str[2];
priority_queue< int > q[4];
int main()
{
    int n,val,now,cnta=0,cntb=0,all=0,qt=0;
    long long ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s %d",str,&val);
        now=2*(str[0]-'0')+(str[1]-'0');
        q[now].push(val);
    }
    while(!q[3].empty())
    {
        ans+=q[3].top();
        all++;
        cnta++;
        cntb++;
        q[3].pop();
        qt++;
    }
    while(!q[1].empty()&&!q[2].empty())
    {
        cnta++;
        cntb++;
        all+=2;
        ans+=q[1].top()+q[2].top();
        q[1].pop();
        q[2].pop();
    }
    while(!q[1].empty())    q[0].push(q[1].top()),q[1].pop();
    while(!q[2].empty())    q[0].push(q[2].top()),q[2].pop();
    for(int i=1;i<=qt;i++)
    {
        if(q[0].empty())    break;
        ans+=q[0].top();
        q[0].pop();
    }
    printf("%lld\n",ans);
    return 0;
}