template<class T, class F> T first_true(T lower, T upper, const F& f) {
	T mid;

	assert(lower <= ++upper);
	while (lower < upper) {
		mid = lower + (upper - lower) / 2;
		f(mid) ? upper = mid : lower = mid + 1;
	}
	return lower;
}

template<class T, class F> T last_true(T lower, T upper, const F& f) {
	T mid;

	assert(--lower <= upper);
	while (lower < upper) {
		mid = lower + (upper - lower + 1) / 2;
		f(mid) ? lower = mid : upper = mid - 1;
	}
	return lower;
}