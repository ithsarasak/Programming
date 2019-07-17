#include<bits/stdc++.h>
using namespace std;
struct A
{
    int x,y;
    bool operator<(const A&o)const
    {
        if(x!=o.x)
            return x<o.x;
        return y<o.y;
    }
};
A a[100100];
deque<int> mi;
deque<int> ma;
int main()
{
    int n,ch,l,r,mid,q,high;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d",&n,&high);
        for(int i=1; i<=n; i++)
        {
            scanf("%d %d",&a[i].x,&a[i].y);
        }
        sort(a+1,a+n+1);
        l=0,r=1000000;
        while(l<r)
        {
            mid=(l+r)/2;
            ch=0;
            for(int i=1; i<=n; i++)
            {
                while(!ma.empty()&&a[i].x-a[ma.front()].x>mid)
                    ma.pop_front();
                while(!ma.empty()&&a[i].y>a[ma.back()].y)
                    ma.pop_back();
                ma.push_back(i);
                while(!mi.empty()&&a[i].x-a[mi.front()].x>mid)
                    mi.pop_front();
                while(!mi.empty()&&a[i].y<a[mi.back()].y)
                    mi.pop_back();
                mi.push_back(i);
                if(a[ma.front()].y-a[mi.front()].y>=high&&ma.front()!=mi.front())
                {
                    ch=1;
                    break;
                }
            }
            while(!ma.empty())
                ma.pop_back();
            while(!mi.empty())
                mi.pop_back();
            if(ch)
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        ch=0;
        for(int i=1; i<=n; i++)
        {
            while(!ma.empty()&&a[i].x-a[ma.front()].x>l)
                ma.pop_front();
            while(!ma.empty()&&a[i].y>a[ma.back()].y)
                ma.pop_back();
            ma.push_back(i);
            while(!mi.empty()&&a[i].x-a[mi.front()].x>l)
                mi.pop_front();
            while(!mi.empty()&&a[i].y<a[mi.back()].y)
                mi.pop_back();
            mi.push_back(i);
            if(a[ma.front()].y-a[mi.front()].y>=high)
            {
                ch=1;
                break;
            }
        }
        if(ch)
        {
            printf("%d\n",l);
        }
        else
        {
            printf("-1\n");
        }
        while(!mi.empty())
            mi.pop_back();
        while(!ma.empty())
            ma.pop_back();
    }
    return 0;
}


