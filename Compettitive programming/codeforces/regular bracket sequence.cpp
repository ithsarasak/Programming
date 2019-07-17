#include <bits/stdc++.h>

using namespace std;

long long o, t, th, f;

int main() {
    scanf("%lld %lld %lld %lld", &o, &t, &th, &f);
    o *= 2LL, f *= -2LL;
    if(th > o) return !printf("0\n");
    if(o + f != 0) return !printf("0\n");
    printf("1\n");

    return 0;
}