#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n;
char A[N][15];
int pos[N];


int main() {
	scanf("%d", &n);
	iota(pos, pos+n, 0);
	for(int i = 0; i < n; ++i) scanf("%s", A[i]);
	sort(pos, pos+n, [&](int a, int b) {
		for(int i = 0; i < 10; ++i) {
			if(A[a][i] == A[b][i]) continue;
			return A[a][i] < A[b][i];
		}
	});
	for(int i = 0; i < n; ++i) printf("%s\n", A[pos[i]]);
}
