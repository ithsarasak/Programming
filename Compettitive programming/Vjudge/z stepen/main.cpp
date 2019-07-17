#include<stdio.h>
#include<math.h>
long long o,s,m;
long long po(long long a,long long b){
    long long k;
    if(b==1) return a;
    if(b==0) return 1;
    a=a%m;
    k=pow(a,2);
    a=a%m;
    if(b%2==0) return po(k,b/2)%m;
    else return (po(k,b/2)*a)%m;
}
main(){

    scanf("%lld%lld%lld",&o,&s,&m);
    o=o%m;
    printf("%lld\n",po(o,s)%m );
}
