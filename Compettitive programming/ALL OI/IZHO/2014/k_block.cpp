#include <bits/stdc++.h>
 
#define fr first
#define sc second
#define pb push_back
#define mk make_pair
#define all(s) s.begin(), s.end()
 
using namespace std;
 
const int N = 1e5 + 5;
 
int n, k, a[N];
 
long long dp[N][105];
 
vector <pair< pair<int, long long>, long long> > vec;
 
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	memset(dp, 0x3f3f3f3f, sizeof(dp));
	dp[0][0] = 0;
	for (int j = 1; j <= k; j++) {
		vec.clear();
		for (int i = 1; i <= n; i++) {
			long long mn = dp[i - 1][j - 1];
			while (!vec.empty() && vec.back().fr.fr <= a[i]) {
				mn = min(mn, vec.back().fr.sc);
				vec.pop_back();
			}
			long long val = a[i] + mn;
			if (!vec.empty()) 
				val = min(val, vec.back().sc);
				
			vec.pb({{a[i], mn}, val});
			dp[i][j] = val;
		}
	}	
	cout << dp[n][k]<< endl;
}
