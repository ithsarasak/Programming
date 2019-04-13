#include <cstdio>

long long fibo[80];
int i = 3;

float binary (int num, int x) {
	float dot;
	int l = 0, r = x;
	int m = (l+r)/2;
	while (l < r) {
		if (num > fibo[m]) {
			l = m+1;
		}
		else if (num < fibo[m]){
			r = m-1;
		}
		else {
			return m;
		}
	}
	dot = (i-2)+(num-fibo[r])/((fibo[l]-fibo[r])*1.00);
	return dot;
}

float function(int num) {
	float dot;
	while (i < 80){
		if (fibo[i-1] < num) {
			fibo[i] = fibo[i-1]+fibo[i-2];
		}
		else if (fibo[i-1] > num){
			//dot = (i-2)+(num-fibo[i-2])/((fibo[i-1]-fibo[i-2])*1.00);//no
			return binary(num,i-1);
		}
		else {
			return i-1;
		}
		i++;
	}

}

int main() {
	int T;
	long long num;
	fibo[0]=0;
	fibo[1]=1;
	fibo[2]=1;
	
	scanf ("%d", &T);
	
	for (int i = 0; i < T; i++) {
		scanf ("%d", &num);
		printf ("Case #%d: %.4f\n", i+1, function(num));
	}
	
	return 0;
}
