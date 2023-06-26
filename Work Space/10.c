#include<stdio.h>
#include<stdlib.h>

#define NN 101010

int head[NN], nxt[NN], to[NN], E;
int c[NN], ans[NN], nn;

void init(int n) {
	E = 0;
	for(int i = 1; i <= n; i++) head[i] = -1;
}
void add(int u, int v) {
	to[E] = v, nxt[E] = head[u], head[u] = E++;
}

void dfs(int u, int up) {
	ans[nn++] = up * 2 + c[u];
	for(int e = head[u]; ~e; e = nxt[e]) {
		int v = to[e];
		dfs(v, 2 * up + c[v]);
	}
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n, rt; scanf("%d %d", &n, &rt);
	for(int i = 1; i <= n; i++) scanf("%d", c + i);
	
	init(n);
	for(int i = 1; i < n; i++) {
		int pa, u; scanf("%d %d", &pa, &u);
		add(pa, u);
	}
	dfs(rt, 1);
	
	qsort(ans, nn, sizeof(int), compare);
	
	int mn = ans[1] - ans[0];
	for(int i = 1; i + 1 < nn; i++) {
		int val = ans[i + 1] - ans[i];
		if(val < mn) mn = val;
	}
    return 0;
}
