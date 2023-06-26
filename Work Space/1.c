#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

#define NN 101010
#define MM 230202
#define inf 0x3f3f3f3f

int head[NN], nxt[MM], to[MM], E;

void add(int u, int v) {
	to[E] = v, nxt[E] = head[u], head[u] = E++;
}

void init(int n) {
	E = 0;
	for(int i = 1; i <= n; i++) head[i] = -1;
}

int mn;
int C[NN];
bool flag[NN];

void dfs(int u) {
	if(C[u] < mn) mn = C[u];
	for(int e = head[u]; ~e; e = nxt[e]) {
		int v = to[e];
		if(!flag[v]) dfs(v);
	}
}

int main() {
	int n, m; scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", C + i);
	init(n);
	while(m--) {
		int u, v; scanf("%d %d", &u, &v);
		add(u, v), add(v, u);
	}
	
	int num = 0, sum = 0;
	for(int i = 1; i <= n; i++) if(!flag[i]) {
		mn = inf, dfs(i);
		num++, sum += mn;
	}
	printf("%d %d\n", num, sum);
	return 0;
}
