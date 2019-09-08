#include <iostream>
#define int long long
using namespace std;
int dp[40];
int n;
int len(int k)
{
	if(k == 0) return 3;
	if(dp[k]) return dp[k];
	return dp[k] = len(k-1) + (k+3) + len(k-1);
}
void recursion(int k)
{
	auto length = len(k);
	if(length < n) recursion(k+1);	
	if(k == 0)
	{
		if(n == 1) puts("m");else puts("o");exit(0);
	}
	if(n <= len(k-1)) recursion(k-1);
	n -= len(k-1);
	if(n <= (k+3))
	{
        if(n == 1) puts("m");else puts("o");exit(0);
	}
	n -= (k+3);
	recursion(k-1);
}
int32_t main()
{
	cin >> n;
	recursion(0);
	return 0;
}
