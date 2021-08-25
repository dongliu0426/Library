vector<int> suffix_array(const char *s) {
	int i, s1, sz, n = strlen(s);
	vector<int> sa(n), c(n);

	for (i = 0; i < n; i++) {
		sa[i] = n - i - 1;
		c[i] = s[i];
	}
	stable_sort(begin(sa), end(sa), [&](int i, int j) {
		return s[i] < s[j];
	});
	for (sz = 1; sz < n; sz <<= 1) {
		vector<int> c_(c);
		for (i = 0; i < n; i++)
			c[sa[i]] = (i && sa[i - 1] + sz < n
			            && c_[sa[i]] == c_[sa[i - 1]]
			            && c_[sa[i] + sz / 2] == c_[sa[i - 1] + sz / 2])
			           ? c[sa[i - 1]] : i;
		vector<int> cnt(n), sa_(sa);
		for (i = 0; i < n; i++) cnt[i] = i;
		for (i = 0; i < n; i++) {
			s1 = sa_[i] - sz;
			if (s1 >= 0)
				sa[cnt[c[s1]]++] = s1;
		}
	}
	return sa;
}

vector<int> lcp_array(const vector<int>& sa, const char* s) {
	int i, j, pre, n = strlen(s);
	vector<int> rank(n), lcp(n - 1);

	for (i = 0; i < n; i++)
		rank[sa[i]] = i;
	for (i = 0, pre = 0; i < n; i++) {
		if (rank[i] < n - 1) {
			j = sa[rank[i] + 1];
			while (max(i, j) + pre < n && s[i + pre] == s[j + pre])
				pre++;
			lcp[rank[i]] = pre;
			if (pre > 0)
				pre--;
		}
	}
	return lcp;
}