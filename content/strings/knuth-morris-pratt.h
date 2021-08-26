vector<int> kmp(const char* s) {
	int i, j, n = strlen(s);

	vector<int> f(n);
	for (i = 1; i < n; i++) {
		j = f[i - 1];
		while (j > 0 && s[i] != s[j])
			j = f[j - 1];
		if (s[i] == s[j])
			j++;
		f[i] = j;
	}
	return f;

}

vector<int> get_oc(const char* a, const char* b) {
	int i, n = strlen(a), m = strlen(b);
	char *c = (char *) malloc((n + m + 2) * sizeof(char));

	strcpy(c, b); strcpy(c + m + 1, a);
	c[m] = '@', c[n + m + 1] = '\0';
	vector<int> f = kmp(c), ret;
	for (i = m; i <= n; i++)
		if (f[i + m] == m)
			ret.push_back(i - m);
	return ret;
}