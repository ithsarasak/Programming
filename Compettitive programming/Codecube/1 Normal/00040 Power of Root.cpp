#include<bits/stdc++.h>
using namespace std;
struct A
{
    int a[4][4];
};
A tmp;
int h;
A mul(A a,A b)
{
    memset(tmp.a,0,sizeof tmp.a);
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            for(int k=0;k<4;k++)
            {
                tmp.a[i][j]+=a.a[i][k]*b.a[k][j];
                tmp.a[i][j]%=h;
            }
        }
    }
    return tmp;
}
A p[32],ans;
int main()
{
    int q,a,b,c,n;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d %d %d %d",&a,&b,&c,&n,&h);
        if(n==1)
        {
            printf("0 %d %d %d\n",a%h,b%h,c%h);
            continue;
        }
        p[0]={c,b*2,a*3,0,
              b,c,0,a*3,
              a,0,c,b*2,
              0,a,b,c};
        ans={0,a,b,c,
             0,0,0,0,
             0,0,0,0,
             0,0,0,0};
        n--;
        for(int i=1;i<=30;i++)
        {
            p[i]=mul(p[i-1],p[i-1]);
        }
        for(int i=0;i<=30;i++)
        {
            if(n&(1<<i))
            {
                ans=mul(ans,p[i]);
            }
        }
        for(int i=0;i<=3;i++)
        {
            printf("%d ",ans.a[0][i]);
        }
        printf("\n");
    }
    return 0;
}
/*
2
1 1 1 3 100
1 1 1 3 100
*/
