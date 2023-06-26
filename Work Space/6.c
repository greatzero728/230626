#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define NN 22
#define inf 0x3f3f3f3f

char s[NN][NN];
char ans[101010], pre[NN][NN];
int nn, n, m;
int qi[101010], qj[101010], qf, qb;
int d[NN][NN];

void Go(int stx, int sty, int edx, int edy) {
	qf = qb = 0;
	qi[qb] = edx, qj[qb++] = edy;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) d[i][j] = inf;
	}
	d[edx][edy] = 0;
	
	while(qf < qb) {
		int i = qi[qf], j = qj[qf++], I, J;
		if(i == stx && j == sty) break;
		
		I = i, J = j + 1;
		if(s[I][J] ^ '#' && s[I][J] ^ 'B' && d[I][J] > d[i][j] + 1) {
			d[I][J] = d[i][j] + 1, qi[qb] = I, qj[qb++] = J;
			pre[I][J] = 'w';
		}
		I = i - 1, J = j;
		if(s[I][J] ^ '#' && s[I][J] ^ 'B' && d[I][J] > d[i][j] + 1) {
			d[I][J] = d[i][j] + 1, qi[qb] = I, qj[qb++] = J;
			pre[I][J] = 's';
		}
		I = i, J = j - 1;
		if(s[I][J] ^ '#' && s[I][J] ^ 'B' && d[I][J] > d[i][j] + 1) {
			d[I][J] = d[i][j] + 1, qi[qb] = I, qj[qb++] = J;
			pre[I][J] = 'e';
		}
		I = i + 1, J = j;
		if(s[I][J] ^ '#' && s[I][J] ^ 'B' && d[I][J] > d[i][j] + 1) {
			d[I][J] = d[i][j] + 1, qi[qb] = I, qj[qb++] = J;
			pre[I][J] = 'n';
		}
	}
	
	for(int I = stx, J = sty; I != edx || J != edy; ) {
		putchar(pre[I][J]);
		if(pre[I][J] == 'e') J++;
		else if(pre[I][J] == 'n') I--;
		else if(pre[I][J] == 'w') J--;
		else I++;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	scanf("%d %d", &n, &m);
	
	int sti, stj, edi, edj;
	for(int i = 1; i <= n; i++) {
		scanf("%s", s[i] + 1);
		for(int j = 1; j <= m; j++) {
			if(s[i][j] == 'B') sti = i, stj = j;
			if(s[i][j] == 'T') edi = i, edj = j;
		}
	}
	
	qi[qb] = edi, qj[qb++] = edj;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) d[i][j] = inf;
	}
	d[edi][edj] = 0;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) pre[i][j] = '#';
	}
	while(qf < qb) {
		int i = qi[qf], j = qj[qf++], I, J;
		if(i == sti && j == stj) break;
		
		I = i, J = j + 1;
		if(s[I][J] ^ '#' && d[I][J] > d[i][j] + 1) {
			d[I][J] = d[i][j] + 1, qi[qb] = I, qj[qb++] = J;
			pre[I][J] = 'W';
		}
		
		I = i - 1, J = j;
		if(s[I][J] ^ '#' && d[I][J] > d[i][j] + 1) {
			d[I][J] = d[i][j] + 1, qi[qb] = I, qj[qb++] = J;
			pre[I][J] = 'S';
		}
		
		I = i, J = j - 1;
		if(s[I][J] ^ '#' && d[I][J] > d[i][j] + 1) {
			d[I][J] = d[i][j] + 1, qi[qb] = I, qj[qb++] = J;
			pre[I][J] = 'E';
		}
		
		I = i + 1, J = j;
		if(s[I][J] ^ '#' && d[I][J] > d[i][j] + 1) {
			d[I][J] = d[i][j] + 1, qi[qb] = I, qj[qb++] = J;
			pre[I][J] = 'N';
		}
	}
	
	for(int I = sti, J = stj; I != edi || J != edj; ) {
		ans[nn++] = pre[I][J];
		if(pre[I][J] == 'E') J++;
		else if(pre[I][J] == 'N') I--;
		else if(pre[I][J] == 'W') J--;
		else if(pre[I][J] == 'S') I++;
	}
	
	int I = sti, J = stj, x, y;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) if(s[i][j] == 'S') {
			x = i, y = j; break;
		}
	}
	
	char k;
	for(int i = 0; i < nn; i++) {
		if(ans[i] == 'E') Go(x, y, I, J - 1), x = I, y = J, k = s[I][J], s[I][J] = s[I][J + 1], s[I][J + 1] = k, J++;
		if(ans[i] == 'N') Go(x, y, I + 1, J), x = I, y = J, k = s[I][J], s[I][J] = s[I - 1][J], s[I - 1][J] = k, I--;
		if(ans[i] == 'W') Go(x, y, I, J + 1), x = I, y = J, k = s[I][J], s[I][J] = s[I][J - 1], s[I][J - 1] = k, J--;
		if(ans[i] == 'S') Go(x, y, I - 1, J), x = I, y = J, k = s[I][J], s[I][J] = s[I + 1][J], s[I + 1][J] = k, I++;
		putchar(ans[i]);
	}
	return 0;
}
