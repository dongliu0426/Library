int rand_() {
	static unsigned int X = chrono::high_resolution_clock::now()
	                        .time_since_epoch()
	                        .count();
	return (X *= 3) >> 1;
}