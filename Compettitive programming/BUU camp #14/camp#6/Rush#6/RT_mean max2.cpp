#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 100;
int n, k2;
double num[N], sumnow, mx, sz, k;
deque<double> q;
int main()
{
	scanf("%d %d",&n,&k2);
	k = ( double )k2;
	for( int i = 1 ; i <= n ; i++ ) scanf("%lf",&num[i]);
	for( int i = 1 ; i <= k2 ; i++ ) {
		q.push_back( num[i] );
		sumnow += num[i];
	}
	sz = k, mx = sumnow / k;
	for( int i = k2 + 1 ; i <= n ; i++ ) {
		q.push_back( num[i] );
		sumnow += num[i], sz += 1.00;
		double temp = q.front();
		deque<double> q2;
		printf("BF : " );
		q2 = q;
		while( !q2.empty() ) {
			cout << q2.front() << " ";
			q2.pop_front();
		}
		cout << endl;
		while( sz - k > 1e-6 && (((sumnow-temp)/(sz - 1.00)) - (sumnow/sz)) > 1e-6 ) {
			sumnow -= temp, sz -= 1.00;
			q.pop_front();
			temp = q.front();
		}
		q2 = q;
		printf("AF : ");
		while( !q2.empty() ) {
			cout << q2.front() << " ";
			q2.pop_front();
		}
		cout << endl;
		cout << endl;
		if( (sumnow/sz) - mx > 1e-6 ) mx = sumnow/sz;
	}
	printf("%.1f",mx);
	return 0;
}