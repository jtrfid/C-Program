#include <stdio.h>
#include <string.h>

int main() {
	char s[10];
	gets(s);
	int n = strlen(s);
	int a[10];
	for (int i = 0; i < n; i++) {
		a[i] = s[i] - '0';
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] < a[j + 1]) {
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}