#include <stdio.h>

void perm(char s[], int t);

int main() {
	char s[] = "abc";
	perm(s, 0);
	return 0;
}

void perm(char s[], int t) {
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
				perm(s, t + 1);
				sta[i] = 0;
			}
		}
	}
}