#include <stdio.h>

void sor(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i; j++) {
			if (a[j] < a[j + 1]) {
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
}


int main() {
	int m;
	scanf("%d", &m);
	int a[42];
	int data[21][21];
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &data[i][j]);
		}
	}

	int sum3 = 0;
	int sum4 = 0;
	for (int i = 1; i <= m; i++) {
		int sum1 = 0;
		int sum2 = 0;

		for (int j = 1; j <= m; j++) {
			if (i == j)
				sum3 += data[i][j];
			if (i + j == m + 1)
				sum4 += data[i][j];
			sum1 += data[i][j];
			sum2 += data[j][i];
		}
		a[i] = sum1;
		a[m + i] = sum2;
	}
	a[2 * m + 1] = sum3;
	a[2 * m + 2] = sum4;
	sor(a, 2 * m + 2);
	for (int i = 1; i <= 2 * m + 2; i++)
		printf("%d ", a[i]);
	return 0;
}