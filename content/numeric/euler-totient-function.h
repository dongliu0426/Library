vector<int> phi(int n) {
	int i, j;
	vector<int> kk(n + 1);

	kk[0] = 0, kk[1] = 1;
	for (i = 2; i <= n; i++)
		kk[i] = i;
	for (i = 2; i <= n; i++)
		if (kk[i] == i)
			for (j = i; j <= n; j += i)
				kk[j] -= kk[j] / i;
	return kk;
}