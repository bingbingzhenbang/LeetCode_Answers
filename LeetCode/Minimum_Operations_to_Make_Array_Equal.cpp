int minOperations(int n) {
	if (n % 2 == 1)
	{
		int sz = (n - 1) / 2;
		return sz * (sz + 1);
	}
	else
	{
		int sz = n / 2;
		return sz * sz;
	}
}