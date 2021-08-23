struct DSU {
	vector<int> ds;

	DSU() {}
	DSU(int n) : ds(n, -1) {}
	int find(int i) {
		return ds[i] < 0 ? i : ds[i] = find(ds[i]);
	}
	int size(int i) {
		return -ds[find(i)];
	}
	bool join(int i, int j) {
		i = find(i), j = find(j);
		if (i == j)
			return 0;
		if (ds[i] > ds[j])
			swap(i, j);
		ds[i] += ds[j], ds[j] = i;
		return 1;
	}
};