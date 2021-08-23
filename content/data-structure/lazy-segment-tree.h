struct Seg {
	typedef int T;
	static constexpr T unit = 0;
	static constexpr T comb(const T& a, const T& b) {
		return a + b;
	}

	typedef int U;
	static constexpr U lz_unit = 0;
	static constexpr U lz_comb(const U& a, const U& b) {
		return a + b;
	}
	static constexpr T use_lz(const T& a, int sz, const U& lz) {
		return a + lz * sz;
	}

	int n_, h_;
	vector<int> sz; vector<T> st; vector<U> lz;

	void init(int n) {
		int i;

		h_ = 0;
		while ((1 << h_) < n)
			h_++;
		n_ = 1 << h_;
		st.assign(n_ << 1, unit);
		lz.assign(n_ << 1, lz_unit);
		sz.assign(n_ << 1, 1);
		for (i = n_ - 1; i > 0; i--)
			sz[i] = sz[i << 1 | 0] + sz[i << 1 | 1];
	}
	void init(const vector<T>& aa) {
		int i, n;

		init(n = (int) aa.size());
		for (i = 0; i < n_; i++)
			st[i | n_] = i < n ? aa[i] : unit;
		for (i = n_ - 1; i > 0; i--)
			st[i] = comb(st[i << 1 | 0], st[i << 1 | 1]);
	}
	void put(int i, const U& a) {
		st[i] = use_lz(st[i], sz[i], a);
		if (i < n_)
			lz[i] = lz_comb(lz[i], a);
	}
	void pull(int i) {
		const T& a = comb(st[i << 1 | 0], st[i << 1 | 1]);

		st[i] = use_lz(a, sz[i], lz[i]);
	}
	void push(int i) {
		int h, j;

		for (h = h_; h > 0; h--)
			if (lz[j = i >> h] != lz_unit) {
				put(j << 1 | 0, lz[j]), put(j << 1 | 1, lz[j]);
				lz[j] = lz_unit;
			}
	}

	T query(int l, int r) {
		T la = unit, ra = unit;

		push(l |= n_), push(r |= n_);
		for ( ; l <= r; l >>= 1, r >>= 1) {
			if (l & 1)
				la = comb(la, st[l++]);
			if (~r & 1)
				ra = comb(st[r--], ra);
		}
		return comb(la, ra);
	}

	void update(int l, int r, const U& a) {
		int l_ = l |= n_, r_ = r |= n_;

		push(l_), push(r_);
		for ( ; l <= r; l >>= 1, r >>= 1) {
			if (l & 1)
				put(l++, a);
			if (~r & 1)
				put(r--, a);
		}
		l = l_, r = r_;
		for (l >>= 1, r >>= 1; l > 0; l >>= 1, r >>= 1)
			pull(l), pull(r);
	}
};
