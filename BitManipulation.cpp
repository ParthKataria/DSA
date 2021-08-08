// Bit Manipulation
int setBits(int N)
{
	int sum = 0;
	while (N > 0)
	{
		sum += N & 1;
		N = N / 2;
		// N=N>>1;
	}
	return sum;
	// return __builtin_popcount(N);
}
// ##Good
// Simple solution using sorting and hashing
vector<int> singleNumber(vector<int> nums)
{
	int x = 0;
	for (int i = 0; i < nums.size(); i++)
		x = x ^ nums[i];
	for (int i = 0; i < 32; i++)
		if (x & (1 << i))
		{
			x = 1 << i;
			break;
		}
	// Any set bit in complete xor will be either due to first no. or second no.
	// Two groups each will give a number
	vector<int>a, y;
	for (int i = 0; i < nums.size(); i++)
	{
		if (x & nums[i])
			a.push_back(nums[i]);
		else
			y.push_back(nums[i]);
	}
	int l = 0, m = 0;
	for (int i = 0; i < a.size(); i++)
		l = l ^ a[i];
	for (int i = 0; i < y.size(); i++)
		m = m ^ y[i];
	vector<int>v = {l, m};
	sort(v.begin(), v.end());
	return v;
}
//
int countBitsFlip(int a, int b)
{
	int sum = 0;
	for (int i = 0; i < 32; i++)
	{
		int x = a & (1 << i);
		int y = b & (1 << i);
		if (x ^ y)
			sum++;
	}
	return sum;
	// Other method calculate set bits of a^b
}
//
bool isPowerOfTwo(int n)
{
	if (n == 0)
		return false;

	return (ceil(log2(n)) == floor(log2(n)));
}
bool isPowerofTwo(long long n) {
	int sum = 0;
	for (int i = 0; i < 32; i++)
		if (n & (1 << i))
			sum++;
	if (sum == 1)
		return true;
	return false;
}
//
int findPosition(int n) {
	if (n == 0)
		return -1;
	if (ceil(log2(n)) != floor(log2(n)))
		return -1;
	return floor(log2(n)) + 1;
}
//
int setbitsltor(int x, int y, int l, int r)
{
	for (int i = l - 1; i <= r - 1; i++)
		if (y & (1 << i))
			x |= (1 << i);
	return x;
}
// Multiply using bits
square(n) = 0 if n == 0
  if n is even 
     square(n) = 4*square(n/2) 
  if n is odd
     square(n) = 4*square(floor(n/2)) + 4*floor(n/2) + 1 
// Divide using bits
for(int i=31;i>=0;i--)
	if(temp + (divisor<<i)<=dividend)
	{
		temp+=divisor<<i;
		quotient|=(1<<i);
	}
//
vector<string> AllPossibleStrings(string s) {
	vector<string>v;
	for (int i = 0; i < pow(2, s.size()); i++)
	{
		string z = "";
		for (int j = 0; j < 32; j++)
			if (i & (1 << j))
				z += s[j];
		if (z.size() > 0)
			v.push_back(z);
	}
	sort(v.begin(), v.end());
	return v;
}



