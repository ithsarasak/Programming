#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 100;
int n, co, pic[N], mul[N];
map<long long,int> ma;
long long hashs = 98765431;

int check( int mid ) {
    long long sum = 0, pw = 1; 
    //printf("%d\n",mid);
    for( int i = 0 ; i < mid ; i++ ){
        //printf("%d ",mid-i-1);
        sum = sum * hashs + ( long long )pic[i];
        pw *= hashs;
    }
    //printf("\n");
    ma[sum]++;
    for( int i = mid ; i < n + mid - 1 ; i++ ){
        sum = sum * hashs + ( long long )pic[i % n];
        sum -= pw * ( long long )pic[(i - mid + n) % n];
        if( ma.count(sum) ){
            ma.clear();
            return 1;
        }
        ma[sum]++;
    }
    ma.clear();
    return 0;
}

int main()
{
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++ ) scanf("%d",&pic[i]);
    int l = 0, r = n;
    while( l < r ){
        int mid = ( l + r + 1 ) >> 1;
        if( check( mid ) ) l = mid;
        else r = mid - 1;
    }
    if(l == n) printf("-1\n");
    else printf("%d", l);
    return 0;
}
