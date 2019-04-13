#include<stdio.h>
main()
{
    int a[20];
    int sum=0;
    int diff=0;
    int i,j;
    int nt1,nt2;

    for(i=0;i<9;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<9;i++){
        sum=sum+a[i];
    }
    diff=sum-100;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++)
        if(a[i]+a[j+1]==diff){
            nt1=a[i];
            nt2=a[j+1];
        }
    }
    for(i=0;i<9;i++){
        if(a[i]!=nt1&&a[i]!=nt2){
            printf("%d\n",a[i]);
        }
    }
}
