#pragma warning(disable:4996)


void merge(int a[], int l, int m, int h) {
	int i = l, j = m + 1, k = l;
	int c[100] = { 0 };

	while (i <= m && j <= h) {
		if (a[i] <= a[j])
			c[k++] = a[i++];
		else
			c[k++] = a[j++];
	}
	for (; i <= m; i++)
		c[k++] = a[i];
	for (; j <= h; j++)
		c[k++] = a[j];

	for (i = l; i <= h; i++)
		a[i] = c[i];
}

void Rmerge_sort(int* a, int l, int h) {
	if (l < h) {
		int m = (l + h) / 2;
		Rmerge_sort(a, l, m);
		Rmerge_sort(a, m + 1, h);
		merge(a, l, m, h);
	}
}

void merge_sort(int a[], int n) {
	int l, m, h, p, i;
	for (p = 2; p <= n; p = p * 2) {
		for (i = 0; i + p - 1 < n; i = i + p) {
			l = i;
			h = i + p - 1;
			m = (l + h) / 2;
			merge(a, l, m, h);
		}

		//each time merge with last list
		if (n - i > p / 2) {
			l = i;
			h = n - 1;
			m = (l + h) / 2;
			merge(a, l, m, h);
		}
	}

	//merge with last list
	if (p / 2 < n)
		merge(a, 0, p / 2 - 1, n - 1);
}