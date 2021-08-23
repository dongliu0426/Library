struct Seg {
	typedef int T;
	static constexpr T unit = INT_MAX;
	static constexpr T comb(const T& a, const T& b) {
		return a < b ? a : b;
	}

	int n_;
	vector<T> t;

	void init(int n) {
		n_ = 1;
		while (n_ < n)
			n_ <<= 1;
		t.assign(n_ << 1, unit);
	}
	void init(const vector<T>& aa) {
		int i, n;

		init(n = (int) aa.size());
		for (i = 0; i < n_; i++)
			t[i | n_] = i < n ? aa[i] : unit;
		for (i = n_ - 1; i > 0; i--)
			pull(i);
	}
	void pull(int i) {
		t[i] = comb(t[i << 1 | 0], t[i << 1 | 1]);
	}
	void update(int i, const T& x) {
		t[i |= n_] = x;
		while (i > 1)
			pull(i >>= 1);
	}
	T query(int l, int r) {
		T la = unit, ra = unit;

		for (l |= n_, r |= n_; l <= r; l >>= 1, r >>= 1) {
			if (l & 1)
				la = comb(la, t[l++]);
			if (~r & 1)
				ra = comb(ra, t[r--]);
		}
		return comb(la, ra);
	}
};