#include <stdio.h>
int cost[100][100];
main()
{
    int n,m,l,k,c;
    int i,j;
    int sum=0,perPerson;

    scanf("%d %d",&n,&m);
    scanf("%d %d",&l,&k);
    scanf("%d",&c);

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&cost[i][j]);
            sum=sum+cost[i][j];
        }
    }
    if(sum%c!=0)
    {
        perPerson=(sum/c)+1;
    }
    else
    {
        perPerson=sum/c;
    }

    printf("%d",perPerson+(l*k));
}
