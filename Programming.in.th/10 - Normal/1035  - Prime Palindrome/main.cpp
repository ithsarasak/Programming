#include <iostream>
#include<stdio.h>
#include<string.h>
#define MAX 1000000
#define MAX_PRIME 1000000
using namespace std;
int prime[MAX]={2,3,5,7,11,13,17,19,23
,29,31,37,41,43,47,53,59,61
,67,71,73,79,83,89,97,101,103
,107,109,113,127,131,137,139,149,151
};
int maxPrimeCount=35;
void initPrime(){
     prime[0]=2;
long i;
long primeCount=0;
for(i=153;i<MAX_PRIME;i++){
        //printf("%d",i);
        int chk = 0;
        for(primeCount=0; primeCount<maxPrimeCount && primeCount<=i ;primeCount++){
              if(i%prime[primeCount]==0){
                chk =1;
                break;
              }
        }
        if(chk==0){
                    prime[maxPrimeCount]=i;
                maxPrimeCount++;
               // printf("[%d]",i);
                }
}
}
long pow10(long x){
   long pow=1;
    for(long i=0;i<x;i++)
        pow*=10;
return pow;
}
long isPalindrome(long x){
char a[MAX];
long ans=x;
for(long i =0;i<MAX;i++)
    a[i]=0;
 for(long i=0;x>0;i++){
    a[i]=(x%pow10(i))/pow10(i-1)+'0';
    x = x- x%pow10(i);
 }
long len = strlen(a) ;
 for(long i=1;i<len/2+1;i++)
    if(a[i]!=a[len-i])
        return 0;
 return ans;
}
long isPrime(long x){
//for(long j=2;j<x;j++)
    //if(x%j==0)
    long i;
    for(i=0;prime[i]<x;i++){
        if(x%prime[i]==0)
            return 0;
    }
return x;
}
int main()
{
    //cout << "Hello world!" << endl;
   long i,k,input;
   initPrime();
    scanf("%ld",&input);
    for(i=input+1;;i++){
            //printf("%ld ",i);
        if(isPrime(i)!=0){
           // printf("[%ld] ",i);
            if(isPalindrome(i)!=0){
                printf("%ld",i);
                break;
          }
        }
    }
    return 0;
}
