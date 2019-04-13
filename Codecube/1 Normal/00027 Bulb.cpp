#include<bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
using namespace std;
bool visit[1 << 21];
int main()
{
    int n,state=0;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        state+=a*(1 << i);
    }
    queue<pair<int,int>> q;
    q.push(mp(0,state));
    while(q.size())
    {
        auto fr=q.front();
        q.pop();
        int d=fr.x,node=fr.y;
        if(visit[node]) continue;
        visit[node]=1;
        if(node==0) {cout << d; return 0;}
        for(int i=0;i<n;i++)
        {
            int news=0;
            if(i>0) news+=(1 << (i-1));
            if(i<n-1) news+=(1 << (i+1));
            news+=(1 << i);
            news=news^node;
            if(!visit[news]) q.push(mp(d+1,news));
        }
    }
    cout << -1;
}
