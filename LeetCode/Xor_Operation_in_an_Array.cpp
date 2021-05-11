int xorOperation(int n, int start) {
	int ret = start, current = start;
	for (int i = 1; i < n; ++i)
	{
		current += 2;
		ret ^= current;
	}
	return ret;
}