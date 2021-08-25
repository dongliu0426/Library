vector<int> sieve(int n) {
	int i, j;
	vector<int> kk(n + 1);

	for (i = 2; i <= n; i++)
		if (!kk[i])
			for (j = i; j <= n; j += i)
				kk[j] = i;
	return kk;
}
