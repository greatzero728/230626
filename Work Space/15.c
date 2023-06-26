#include<stdio.h>
#include<stdlib.h>

#define NN 101010

int deg[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n, m; scanf("%d %d", &n, &m);
	while(m--) {
		int u, v; scanf("%d %d", &u, &v);
		deg[u]++, deg[v]++;
	}
	
	int mx = deg[n];
	for(int i = 1; i < n; i++) if(deg[i] > mx) mx = deg[i];
	printf("%d\n", mx);
    return 0;
}