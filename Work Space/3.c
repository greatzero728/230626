#include<stdio.h>
#include<stdlib.h>

#define NN 101010

int L[NN], R[NN], k;

void reverse(int u) {
	if(L[u]) reverse(L[u]);
	if(R[u]) reverse(R[u]);
	k = L[u], L[u] = R[u], R[u] = k;
}

void check(int ls, int rs) {
	if((L[ls] > 0) != (L[rs] > 0)) puts("NOT"), exit(0);
	if(L[ls]) check(L[ls], L[rs]);
	if((R[ls] > 0) != (R[rs] > 0)) puts("NOT"), exit(0);
	if(R[ls]) check(R[ls], R[rs]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int n, m; scanf("%d %d", &n, &m);
	while(m--) {
		char c; int pa, u;
		scanf(" %c %d %d", &c, &pa, &u);
		if(c == 'L') L[pa] = u;
		else R[pa] = u;
	}
	int rt; scanf("%d", &rt);
	if(L[rt] && R[rt]) {
		reverse(R[rt]);
		check(L[rt], R[rt]);
	}
	else if(!L[rt] && !R[rt]) {
		puts("MIRROR");
	}
	else puts("NOT");
	
    return 0;
}
