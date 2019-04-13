#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<string> s;

vector<string> draw(const vector<pair<pair<int, int>, int>> &r) {
	vector<string> f(n, string(m, '.'));
	vector<vector<int>> h(n, vector<int>(m));
	vector<vector<int>> v(n, vector<int>(m));
	for (auto it : r) {
		int x = it.first.first;
		int y = it.first.second;
		int len = it.second;
		++v[x - len][y];
		if (x + len + 1 < n)
			--v[x + len + 1][y];
		++h[x][y - len];
		if (y + len + 1 < m)
			--h[x][y + len + 1];	
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i > 0) v[i][j] += v[i - 1][j];
			if (j > 0) h[i][j] += h[i][j - 1];
			if (v[i][j] > 0 || h[i][j] > 0)
				f[i][j] = '*';
		}
	}
	return f;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n >> m;
	s = vector<string>(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	
	vector<vector<int>> l(n, vector<int>(m));
	vector<vector<int>> r(n, vector<int>(m));
	vector<vector<int>> u(n, vector<int>(m));
	vector<vector<int>> d(n, vector<int>(m));
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i > 0) {
				if (s[i][j] != '.')
					u[i][j] = u[i - 1][j] + 1;
			} else {
				u[i][j] = s[i][j] != '.';
			}
			if (j > 0) {
				if (s[i][j] != '.')
					l[i][j] = l[i][j - 1] + 1;
			} else {
				l[i][j] = s[i][j] != '.';
			}
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			if (i < n - 1) {
				if (s[i][j] != '.')
					d[i][j] = d[i + 1][j] + 1;
			} else {
				d[i][j] = s[i][j] != '.';
			}
			if (j < m - 1) {
				if (s[i][j] != '.')
					r[i][j] = r[i][j + 1] + 1;
			} else {
				r[i][j] = s[i][j] != '.';
			}
		}
	}
	
	vector<pair<pair<int, int>, int>> ans;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == '*') {
				int len = min(min(u[i][j], l[i][j]), min(d[i][j], r[i][j])) - 1;
				if (len != 0) {
					ans.push_back(make_pair(make_pair(i, j), len));
				}
			}
		}
	}
	
	if (draw(ans) != s) {
		cout << -1 << endl;
	} else {
		cout << ans.size() << endl;
		for (auto it : ans) {
			cout << it.first.first + 1 << " " << it.first.second + 1 << " " << it.second << endl; 
		}
	}
	
	return 0;
}