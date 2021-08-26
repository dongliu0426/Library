struct TopoSort {
	int n;
	vector<int> w;
	vector<vector<int>> adj;

	void init(int n) {
		w.assign(n, 0);
		adj.assign(n, vector<int>());
	}
	void add_edge(int u, int v) {
		adj[u].push_back(v), w[v]++;
	}
	vector<int> sort() {
		int i;
		vector<int> q, r;

		q.reserve(n), r.reserve(n);
		for (i = 0; i < n; i++)
			if (w[i] == 0)
				q.push_back(i);
		for (i = 0; i < (int) q.size(); i++) {
			int u = q[i];

			r.push_back(u);
			for (int v : adj[u])
				if (--w[v] == 0)
					q.push_back(v);
		}
		return r;
	}
};