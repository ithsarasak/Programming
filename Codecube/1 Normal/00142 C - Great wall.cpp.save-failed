#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 100010;
long long sum[ N ], H[ N ];
int n, w, k;
// return whether the input can be

bool check( int h );
int main( void ) {
// read input
cin.sync_with_stdio( false );
cin >> n >> w >> k;
for ( int i = 0 ; i < n ; ++i ) {
cin >> H[i];
}
// Small - NOTE: answer is h
// int h = 0;
// while ( !check(h) ) {
// ++h;
// }
// cout << h << endl;
// Large - NOTE: answer is lo
int maxH = *max_element( H, H + n );
int lo = 0, hi = maxH;
while ( lo < hi ) {
int mid = ( lo + hi ) / 2;
if ( check( mid ) ) {
hi = mid;
} else {
lo = mid + 1;
}
}
cout << lo << endl;
return 0;
}
bool check( int h ) {
// reset sum
fill( sum, sum + n, 0 );
long long numWallBreaking = 0ll;
for ( int i = 0 ; i < n ; ++i ) {
// fix quick sum
sum[i] += sum[i-1];
// in case that the height is more than the limit
if ( H[i] - sum[i] > h ) {
// break walls H[i] - h times
long long breakingRequired = H[i] - sum[i] - h;
numWallBreaking += breakingRequired;
// update quick sum
sum[i] += breakingRequired;
if ( i + w < n ) sum[ i + w ] -= breakingRequired;
}
}
// it's valid if number of required wall breaking is not more than k
return numWallBreaking <= k;
}
