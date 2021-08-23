template<class T> struct FT {
	int n;
	vector<T> t;

	void init(int n_) {
		n = n_;
		t.assign(n, 0);
	}
	void update(int i, const T& a) {
		while (i < n) {
			t[i] += a;
			i |= i + 1;
		}
	}
	T query(int i) {
		T sum = 0;

		while (i >= 0) {
			sum += t[i];
			i &= i + 1, --i;
		}
		return sum;
	}
	T query(int l, int r) {
		return query(r) - query(l - 1);
	}
};