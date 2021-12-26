#include <stdio.h>

int main()
{
	int m, n, i, j, a[200][200], count = 0, max = 0, location = 0, sign = 0;
	scanf("%d%d", &m, &n);
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (i = 0; i < m; i++)
	{
		max = 0;
		sign = 0;
		count = 0;
		for (j = 0; j < n; j++)
		{
			if (a[i][j] == 1)
			{
				count++;
				sign = 1;
				if (count > max)
				{
					max = count;
					location = j;
				}
			
			}
			else count=0;

		}
		if (sign)
		{
			printf("%d %d\n", location - max+1, location);
		}
		else
			printf("-1 -1\n");
	}

	return 0;
}

