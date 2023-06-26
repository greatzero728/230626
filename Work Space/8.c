#include<stdio.h>
#include<stdlib.h>

#define NN 202020

int a[NN], b[NN];
int num[NN], B[NN];

int calc(int u) {
	int ans = 0;
	for(; u < NN; u += u & -u) ans += B[u];
	return ans;
}
void update(int u) {
	for(; u; u ^= u & -u) B[u]++;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i), num[a[i]]++;
	for(int i = 1; i <= n; i++) scanf("%d", b + i), num[b[i]]--;
	for(int i = NN; i--; ) if(num[i]) puts("IMPOSSIBLE");
	
	long long ans = 0;
	for(int i = 1; i <= n; i++) {
		ans += calc(a[i] + 1);
		update(a[i]);
	}
	
	for(int i = NN; i--; ) B[i] = 0;
	for(int i = 1; i <= n; i++) {
		ans -= calc(b[i] + 1);
		update(b[i]);
	}
	if(ans) puts("IMPOSSIBLE");
	else puts("POSSIBLE");
    return 0;
}
