#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

#define NN 101010
#define MM 101010

bool flag[NN];
int indeg[NN];
int head[NN], nxt[MM], to[MM], E;

void add(int u, int v) {
	to[E] = v, nxt[E] = head[u], head[u] = E++;
}

void init(int n) {
	E = 0;
	for(int i = 1; i <= n; i++) head[i] = -1;
}

int ans[NN], nn;

int dfs(int u) {
	ans[nn++] = u;
	for(int e = head[u]; ~e; e = nxt[e]) {
		int v = to[e];
		if(!flag[v]) return dfs(v);
		else puts("-1"), exit(0);
	}
	return 0;
}

int main() {
	int n, m; scanf("%d %d", &n, &m);
	while(m--) {
		int u, v; scanf("%d %d", &u, &v);
		add(u, v), indeg[v]++;
	}
	
	for(int i = 1; i <= n; i++) if(!indeg[i]) {
		dfs(i); break;
	}
	if(nn == n) {
		for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
	}
	else puts("-1");
	return 0;
}
