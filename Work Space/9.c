#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define NN 101010

char st[NN], s[NN];
int lastIndex[26], nn;
bool seen[26];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    
    for(int i = 1; i <= n; i++) lastIndex[s[i] - 'a'] = i;
    
    for(int i = 1; s[i]; i++) {
        if(seen[s[i] - 'a']) continue;
        while(nn && st[nn] > s[i] && i < lastIndex[st[nn] - 'a']) {
            seen[st[nn--] - 'a'] = 0;
        }
        st[++nn] = s[i], seen[s[i] - 'a'] = 1;
    }
    for(int i = 1; i <= nn; i++) putchar(st[i]);
    return 0;
}
