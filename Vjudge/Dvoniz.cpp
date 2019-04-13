#include<bits/stdc++.h>
using namespace std;
int a[100100],qs[100100];
int main(){
    int n,s,i;
    scanf("%d %d",&n,&s);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        qs[i] = qs[i-1]+a[i];
    }
    for(i=1;i<=n;i++){
        int p=i,q=n;
        while(p < q){
            int mid = (p+q+1)/2;
            //printf("%d %d %d\n",p,q,mid);
            if(qs[(mid+i-1)/2]-qs[i-1] > s || qs[mid]-qs[(mid+i-1)/2] > s)
                q = mid-1;
            else
                p = mid;
        }
        if((p-i+1) % 2 == 1){
            p++;
        }
        if(qs[p]-qs[(p+i-1)/2] <= s && qs[(p+i-1)/2]-qs[i-1] <= s && p <= n)
            printf("%d\n",p-i+1);
        else
            printf("%d\n",p-2-i+1);
    }
    return 0;
}
