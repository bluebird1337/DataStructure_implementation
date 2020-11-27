

int hash_function(int key);
void linear_probling(int HT[], int key) {
	int index = hash_function(key);
	int i = 0;
	while (HT[(index + i)%10] != -1) {
		i++;
	}
	HT[(index + i)%10] = key;
}

int linear_search(int HT[], int key) {
	int index = hash_function(key);
	int i = 0;
	while (HT[(index + i) % 10] != -1 && HT[(index + i) % 10] != key)
		i++;

	if (HT[(index + i) % 10] == -1)
		return ;
	else
		return (index + i) % 10;
}

