#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> pii ;
const int N = 1e5+9 ;
#define fi first
#define se second
struct cht
{
    struct line
    {
        ll m,c ;
        line (ll m,ll c):m(m),c(c){}
        ll f(ll x){return m*x+c;}
    };
    vector<line> l ;
    int str=0 ;
    bool bad(line a,line b,line c)
    {
        return (c.c-a.c)*(a.m-b.m)<=(b.c-a.c)*(a.m-c.m);
    }
    void add(ll x,ll c)
    {
        line now(x,c);
        while(l.size()>1&&bad(l[l.size()-2],l[l.size()-1],now))l.pop_back();
        l.emplace_back(now);
    }
    ll query(ll x)
    {
        while(str<l.size()-1&&l[str].f(x)>l[str+1].f(x))str++;
        return l[str].f(x) ;
    }
}hull ;
ll dp[N];
vector<pair<ll,ll> > v,u ;
main()
{
    int n,i,j,x,y;
    ll A,H,Z ;
    cin >> n ;
    for(i=1;i<=n;i++)
    {
        cin >> A >> H >> Z ;
        v.emplace_back(A*H,Z);
    }
    sort(v.begin(),v.end());
    u.emplace_back(0,1e9);
    for(auto it:v)
    {
        while(it.se>(u.back().se))
        {
            u.pop_back();
        }
        u.emplace_back(it);
    }
    v=u;
    for(i=1;i<v.size();i++)
    {
        hull.add(v[i].se,dp[i-1]);
        dp[i]=hull.query(v[i].fi);
    }
    cout << dp[v.size()-1];
}