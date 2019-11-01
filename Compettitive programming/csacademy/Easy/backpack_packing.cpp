#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b, n;
    cin >> a >> b >> n;
    int ans = 0;
    for (int i = 0; i < n; i += 1) {
        int x;
        cin >> x;

        if (a < b) {
            swap(a, b);
        }

        if (x <= a) {
            a -= x;
        } else {
            ans += 1;
        }
    }

    cout << ans << '\n';
    return 0;
}