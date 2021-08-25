vector<int> manacher(const char *s) {
	int n = strlen(s), i, lo = 0, hi = 0;
	char *t = (char *) malloc((2 * n + 1) * sizeof(char));

	t[0] = '@';
	for (i = 0; i < n; i++)
		t[i * 2 + 1] = s[i], t[i * 2 + 2] = '#';
	t[n * 2] = '&';
	n = strlen(t);
	vector<int> ans(n - 1);
	for (i = 1; i < n - 1; i++) {
		if (i != 1)
			ans[i] = min(hi - i, ans[hi - i + lo]);
		while (t[i - ans[i] - 1] == t[i + ans[i] + 1])
			ans[i]++;
		if (i + ans[i] > hi)
			lo = i - ans[i], hi = i + ans[i];
	}
	ans.erase(begin(ans));
	for (i = 0; i < (int) ans.size(); i++)
		if ((i & 1) == (ans[i] & 1))
			ans[i]++;
	free(t);
	return ans;
}
