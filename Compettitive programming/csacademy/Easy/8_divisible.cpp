#include <bits/stdc++.h>

using namespace std;

const string mx = string(1000, '9');
vector<int> freq(10);
string n;

string LowestString(vector<int> f) {
    int mn = 10;
    for (int i = 1; i <= 9; i += 1) {
        if (f[i]) {
            mn = i;
            break;
        }
    }
    
    if (mn == 10) { return mx; }
    string s(1, '0' + mn);
    f[mn] -= 1;
    for (int i = 0; i < 10; i += 1) {
        s += string(f[i], '0' + i);
    }
    
    return s;
}

string GetMinStr(int i) {
    string low = to_string(i);
    auto f = freq;
    for (char itr : low) {
        f[itr - '0'] -= 1;
        if (f[itr - '0'] < 0) {
            return mx;
        }
    }
    
    if (low.size() == n.size()) {
        return low;   
    }
    
    f[0] -= 3 - low.size();
    if (f[0] < 0) { return mx; }
    low = string(3 - low.size(), '0') + low;
    
    return LowestString(f) + low;
}

int main() {
    cin >> n;
    assert(n != "0");
    for (char itr : n) {
        freq[itr - '0'] += 1;
    }
    
    string best = mx;
    for (int i = 0; i < 999; i += 1) {
        if (i % 8 == 0) {
            best = min(best, GetMinStr(i));
        }
    }
    
    if (best == mx) { best = "-1"; }
    cout << best << '\n';
    return 0;
}