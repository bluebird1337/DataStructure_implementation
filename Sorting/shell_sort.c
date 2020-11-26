#pragma warning(disable:4996)

void shell_sort(int* a, int n) {
	int gap, i, j, tmp;
	for (gap = n / 2; gap >= 1; gap /= 2) {
		for (i = gap; i < n; i++) {
			tmp = a[i];
			j = i - gap;

			while (j >= 0 && a[j] > tmp) {
				a[j+gap] = a[j];
				j = j - gap;
			}
			a[j + gap] = tmp;
		}
	}
}
 