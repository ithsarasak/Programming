#include <bits/stdc++.h>

using namespace std;
int q;
int ans[30], mark[6010];
vector<int> prime;
const int mx = 6000;
void genprime()
{
	int cnt = 0;
	for( int i = 2 ; i <= mx ; i++ ){
		if( !mark[i] ){
			for( int j = i ; j <= mx ; j += i ){
				mark[j] = 1;
			}
			prime.push_back( i );
		}
	}
}
void genans()
{
    for( int i = 2 ; i <= 25 ; i++ ){
        int a = (1<<i)-1;
//        printf("A : %d\n",a);
        for( int j = 0 ; j < prime.size() ; j++ ){
//            printf("A : %d P : %d R : %d\n",a,prime[j],a%prime[j]);
            if( a % prime[j] == 0 ){
//                printf("a : %d prime : %d\n",a,prime[i]);
                a /= prime[j];
                ans[i] = a;
                break;
            }
        }
        if( a == (1<<i)-1 ){
            ans[i] = 1;
        }
    }
}
int main()
{
	genprime();
//	for( int i = 0 ; i < prime.size() ; i++ )printf("%d ",prime[i]);
//	printf("\n");
	genans();
	scanf("%d",&q);
//	for( int i = 2 ; i <= 25 ; i++ )printf("%d ",ans[i]);
//	printf("\n");
	while( q-- ){
		int a;
		scanf("%d",&a);
		int cc = 0;
		for( int i = 2 ; i <= 25 ; i++ ){
//            printf("%d %d %d\n",a,((1<<i)-1),ans[i]);
			if( a == ((1<<i) - 1) ){
				printf("%d\n",ans[i]);
				cc = 1;
				break;
			}
		}
		if( cc )continue;
        for( int i = 2 ; i <= 25 ; i++ ){
            if( (1<<i)-1 > a ){
                printf("%d\n",(1<<i)-1);
                break;
            }
        }
	}
	return 0;
}
