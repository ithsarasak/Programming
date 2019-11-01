   #include <bits/stdc++.h>
using namespace std;

int sum(int A, int B) {
    return A + B;
}

   int main() {
    int tests;
    cin >> tests;
    for (int i = 1; i <= tests; ++i) {
        int A, B;
        cin >> A >> B;
        cout << sum(A, B) << "\n";
    }
    return 0;
}
