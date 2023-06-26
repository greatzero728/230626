#include<stdio.h>
#include<stdlib.h>

#define NN 101010
#define MM 202020
#define inf 0x3f3f3f3f

int head[NN], nxt[NN], to[NN], E;
int d[NN], q[NN], qf, qb;

void add(int u, int v) {
	to[E] = v, nxt[E] = head[u], head[u] = E++;
}
void init(int n) {
	E = 0;
	for(int i = 1; i <= n; i++) head[i] = -1, d[i] = inf;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n, m; scanf("%d %d", &n, &m);
	init(n);
	while(m--) {
		int u, v; scanf("%d %d", &u, &v);
		add(u, v), add(v, u);
	}
	int s; scanf("%d", &s);
	while(s--) {
		int x; scanf("%d", &x);
		d[x] = 0, q[qb++] = x;
	}
	
	while(qf < qb) {
		int u = q[qf++];
		for(int e = head[u]; ~e; e = nxt[e]) {
			int v = to[e];
			if(d[v] > d[u] + 1) {
				d[v] = d[u] + 1, q[qb++] = v;
			}
		}
	}
	for(int i = 1; i <= n; i++) printf("%d ", d[i]);
    return 0;
}