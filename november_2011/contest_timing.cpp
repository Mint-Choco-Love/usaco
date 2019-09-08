#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

int32_t main()
{
	int d, h, m; cin >> d >> h >> m;
	int total = m + h*60 + 60*24*d;
	int st = 11 + 11*60 + 60*24*11;
	
	total -= st;
	
	cout << max(-1LL, total) << endl;
	

	
	return 0;
}
