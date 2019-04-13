#include<bits/stdc++.h>
using namespace std;
const int sz=1e6+5;
int water[sz];
int dpl[sz],dpr[sz];
int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> water[i];
    for(int i=1;i<=n;i++)
    {
        dpl[i]=max(dpl[i-1],water[i]);
        dpr[i]=max(dpr[i-1],water[n-i+1]);
    }
    for(int i=1;i<n;i++)
        cout << min(dpl[i],dpr[n-i]) << " ";
}
