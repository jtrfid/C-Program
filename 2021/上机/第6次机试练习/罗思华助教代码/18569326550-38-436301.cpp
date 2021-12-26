#include <stdio.h>
#include <string.h>

int judge(char s[]) {
	char ss[20];
	int n = strlen(s);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		ss[i] = s[n - i - 1];
		sum += s[i] - '0';

	}
	ss[n] = '\0';
	if (!strcmp(s, ss))
		return sum;
	else
		return -1;

}

int main() {
	char s[20];
	gets(s);
	int x = judge(s);
	if (x == -1)
		printf("no");
	else
		printf("%d", x);
	return 0;
}