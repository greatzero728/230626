#include<stdio.h>
#include<stdlib.h>

#define NN 2020

int a[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n; scanf("%d", &n);
	int N = n << 1;
	for(int i = 1; i <= N; i++) scanf("%d", a + i);
	
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) if(a[i] > a[j]) {
			int k = a[i]; a[i] = a[j], a[j] = k;
		}
	}
	
	int mn = 1e9;
	for(int i = n; i <= N; i++) {
		int tmp = a[i] - a[i - n + 1];
		if(tmp < mn) mn = tmp;
	}
	printf("%d\n", mn);
    return 0;
}
