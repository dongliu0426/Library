template<class T> struct Compress {
	vector<T> tt;

	void insert(const T& a) {
		tt.push_back(x);
	}
	void insert(const vector<T>& aa) {
		for (const T& a : aa)
			insert(a);
	}
	void gen() {
		sort(begin(tt), end(tt));
		tt.erase(unique(begin(tt), end(tt)), end(tt));
	}
	int index(const T& x) {
		return int(lower_bound(begin(tt), end(tt), x) - begin(tt));
	}
};