#include<bits/stdc++.h>
using namespace std;
struct A
{
    int i,j,w,use;
    bool operator<(const A&o)const
    {
        return w>o.w;
    }
};
int tab[105][105];
int dist[105][105][2];
int dir[4]={1,-1,0,0};
int dic[4]={0,0,1,-1};
priority_queue< A > q;
int main()
{
    int n,m,sti,stj,eni,enj,hour,minute,nowi,nowj,nowuse,noww,alltime;
    scanf("%d %d %d %d %d %d %d:%d",&n,&m,&sti,&stj,&eni,&enj,&hour,&minute);
    alltime=hour*60+minute;
    for(int i=1;i<=n;i++)   for(int j=1;j<=m;j++) scanf("%d",&tab[i][j]),dist[i][j][0]=dist[i][j][1]=1e9+5;
    dist[sti][stj][0]=0;
    q.push({sti,stj,0,0});
    while(!q.empty())
    {
        int nowi=q.top().i,nowj=q.top().j,noww=q.top().w,nowuse=q.top().use,nexti,nextj;
        q.pop();
        for(int k=0;k<4;k++)
        {
            nexti=nowi+dir[k],nextj=nowj+dic[k];
            if(nexti<=0||nextj<=0||nexti>n||nextj>m)    continue;
            if(tab[nowi][nowj]>=0){
            if(noww+max(0,tab[nowi][nowj])<dist[nexti][nextj][nowuse])
            {
                dist[nexti][nextj][nowuse]=noww+max(0,tab[nowi][nowj]);
                q.push({nexti,nextj,noww+max(0,tab[nowi][nowj]),nowuse});
            }
            }
            else
            {
            if(nowuse==0&&tab[nowi][nowj]<0&&noww+tab[nowi][nowj]<dist[nexti][nextj][1])
            {
                dist[nexti][nextj][1]=noww+tab[nowi][nowj];
                q.push({nexti,nextj,noww+tab[nowi][nowj],1});
            }
            if(noww<dist[nexti][nextj][nowuse])
            {
                dist[nexti][nextj][nowuse]=noww;
                q.push({nexti,nextj,noww,nowuse});
            }
            }
        }
    }
    alltime+=min(dist[eni][enj][0],dist[eni][enj][1])+max(0,tab[eni][enj]);
    alltime%=1440;
    alltime+=1440;
    alltime%=1440;
    hour=alltime/60;
    minute=alltime-hour*60;
    printf("%02d:%02d\n",hour%12,minute);
    return 0;
}
