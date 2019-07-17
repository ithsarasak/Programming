#include<bits/stdc++.h>
using namespace std;
struct r
{
    int x,y,d;
};
int board[505][505];
int dist[505][505];
bool visit[505][505];
map<int,int> mp;
int main()
{
    int h,w;
    cin >> h >> w;
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
            cin >> board[i][j];
    queue<r> q;
    int di[2][2]={{0,1},{-1,0}};
    mp[0]=0;
    r in;
    in.x=h;
    in.y=1;
    in.d=1;
    q.push(in);
    while(q.size())
    {
        auto fr=q.front();
        q.pop();
        int x=fr.x,y=fr.y,d=fr.d;
        if(visit[x][y]) continue;
        visit[x][y]=1;
        dist[x][y]=d;
        if(mp.find(d)==mp.end()) mp[d]=1;
        else mp[d]++;
        for(int i=0;i<2;i++)
        {
            int xx=x+di[i][0],yy=y+di[i][1];
            if(xx<1||xx>h||yy<1||yy>w) continue;
            if(!visit[xx][yy]&&board[xx][yy]==0) {in.x=xx; in.y=yy; in.d=d+1; q.push(in);}
        }
    }
    int ans=0;
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
            ans+=mp[dist[i][j]];
    cout << ans;
}
