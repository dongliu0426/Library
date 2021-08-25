int minRotation(const char *s) {
	int b, i, a = 0, n = strlen(s);
	char* t = (char *) malloc(n * 2 * sizeof(char));

	strcpy(t, s); strcpy(t + n, s);
	for (b = 0; b < n; b++) {
		for (i = 0; i < n; i++) {
			if (a + i == b || t[a + i] < t[b + i]) {
				b += max(0, i - 1);
				break;
			}
			if (t[a + i] > t[b + i]) {
				a = b;
				break;
			}
		}
	}
	free(t);
	return a;
}
/*
int p = minRotation(a);
for (int i = 0; i < n; ++i)
	printf("%c", a[(i + p) % n]);
printf("\n");
*/