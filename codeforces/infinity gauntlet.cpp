#include <bits/stdc++.h>

using namespace std;
int n;
string col[6] = { "red", "purple", "yellow", "orange", "green", "blue" };
map<string,string> ma;
map<string,int> m;
int main()
{
	ma["red"] = "Reality";
	ma["purple"] = "Power";
	ma["yellow"] = "Mind";
	ma["orange"] = "Soul";
	ma["green"] = "Time";
	ma["blue"] = "Space";
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ ){
		string s;
		cin >> s;
		m[s] = 1;
	}
	printf("%d\n",6-n);
	for( int i = 0 ; i < 6 ; i++ ){
		if( m[col[i]] == 0 ){
			cout << ma[col[i]] << endl;
		}
	}
	return 0;
}