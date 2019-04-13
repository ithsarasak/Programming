/*#include<stdio.h>
main()
{
    int num[5];
    int t;
    char abc[10];

    scanf("%d %d %d",&num[0],&num[1],&num[2]);
    scanf("%s",abc);

    if(num[0]>num[1])
    {
        t=num[0];
        num[0]=num[1];
        num[1]=t;
    }
    if(num[0]>num[2])
    {
        t=num[0];
        num[0]=num[2];
        num[2]=t;
    }
    if(num[1]>num[2])
    {
        t=num[1];
        num[1]=num[2];
        num[2]=t;
    }

    printf("%d %d %d",num[abc[0]-'A'],num[abc[1]-'A'],num[abc[2]-'A']);
}*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int ar[3];
    char alp[3],temp;
    scanf("%d %d %d",&ar[0],&ar[1],&ar[2]);
    int t2 = ar[0];
    scanf("%s",alp);
    ar[0] = t2;
    for ( int i = 0 ; i < 3 ; i++ )
        for ( int j = i + 1 ; j < 3 ; j++ )
            if (ar[i] > ar[j]){
                int temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }

    for ( int i = 0 ; i < 3 ; i++ )
        {
        //cout << ar[0];
        if (alp[i]=='A') printf("%d ",ar[0]);
        else if (alp[i]=='B') printf("%d ",ar[1]);
        else if (alp[i]=='C') printf("%d ",ar[2]);
        }
}
