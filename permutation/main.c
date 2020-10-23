#include <stdio.h>

char s[] = "abc";

void swap(int a, int b) {
	char tmp = s[a];
	s[a] = s[b];
	s[b] = tmp;
}

void perm1(char s[], int l, int r) {
	if (l == r) {
		printf("%s\n", s);
	}
	else {
		for (int i = l; i <= r; i++) {
			swap(l, i);
			perm1(s, l+1, r);
			swap(l, i);
		}
	}
}

void perm2(char s[], int t) {
	static char res[10];
	static int sta[10] = { 0 };
	int i;
	if (s[t] == '\0') {
		printf("%s\n", res);
	}
	else {
		for (i=0; s[i] != '\0'; i++) {
			if (sta[i] == 0) {
				res[t] = s[i];
				sta[i] = 1;
				perm2(s, t + 1);
				sta[i] = 0;
			}
		}
	}
}

int main() {
	perm1(s, 0, 2);
	return 0;
}