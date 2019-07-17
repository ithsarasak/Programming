#include<stdio.h>
#include<queue>

using namespace std;

struct node{
    double rice;
    double sussuan;
    bool operator<(const node &p)const{
            return p.sussuan < sussuan;
    }
}t;

double value[100000],rice[100000];
double sussuan[100000];
double kilo[100000];
double sum[100000];
int type,mer,i;

main()
{
    scanf("%d",&type);

    for(i=0;i<type;i++)
    {
        scanf("%lf %lf",&value[i],&rice[i]);
        sussuan[i]=value[i]/rice[i];
        //printf("%.3f\n",sussuan[i]);
    }

    scanf("%d",&mer);

    for(i=0;i<mer;i++)
    {
        scanf("%lf",&kilo[i]);
    }

    priority_queue<node> price;

    for(i=0;i<type;i++)
    {
        price.push({rice[i],sussuan[i]});
    }

    for(i=0;i<mer;i++)
    {
        while(kilo[i]!=0)
        {
            t=price.top();

            if(t.rice<kilo[i])
            {
                sum[i]=sum[i]+(t.rice*t.sussuan);
                kilo[i]=kilo[i]-t.rice;

                price.pop();
            }
            else
            {
                //printf("%.3f %.3f %.3f\n",t.rice,t.sussuan,kilo[i]);
                price.pop();
                price.push({t.rice-kilo[i],t.sussuan});
                sum[i]=sum[i]+(kilo[i]*t.sussuan);
                if(t.rice==0)
                {
                    price.pop();
                }
                kilo[i]=0;
                //printf("%.3f %.3f %.3f\n",t.rice,t.sussuan,kilo[i]);
            }
        }
    }

    for(i=0;i<mer;i++)
    {
        printf("%.3lf\n",sum[i]);
    }
}
