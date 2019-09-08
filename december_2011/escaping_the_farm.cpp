#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
#define int long long

int n, ret;
vector<int> vec;

bool check(int x, int y)
{
	while(x > 0 && y > 0)
	{
		if((x % 10) + (y % 10) >= 10) return false;
		x /= 10; y /= 10;
	}
	
	return true;
}

void dfs(int last, int sum, int cnt)
{
	ret = max(ret, cnt);
	if(last + 1 >= n) return;

	if(check(sum, vec[last + 1])) dfs(last + 1, sum + vec[last + 1], cnt + 1);
	dfs(last + 1, sum, cnt);
}

int32_t main(void)
{
    cin >> n; for(int i = 0; i < n; i++) { int t; cin >> t; vec.push_back(t); }
    
    dfs(-1, 0, 0);
    
    cout << ret << endl;
    
}
