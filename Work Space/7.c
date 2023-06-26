#include<stdio.h>
#include<stdlib.h>

#define NN 10101010
#define inf 0x3f3f3f3f

typedef long long INT;

int a[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	
	int one = -inf, two = -inf;
	for(int i = 1, k; i <= n; i++) if(a[i] > two) {
		two = a[i];
		if(two > one) k = one, one = two, two = k;
	}
	INT ans = (INT)one * two;
	
	one = inf, two = inf;
	for(int i = 1, k; i <= n; i++) if(a[i] < two) {
		two = a[i];
		if(two < one) k = one, one = two, two = k;
	}
	INT x = (INT)one * two;
	
	if(x > ans) ans = x;
	printf("%I64d\n", ans);
    return 0;
}
