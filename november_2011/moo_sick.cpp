#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int N, C;
int notes[20000], ill[10];
bool check(int idx)
{
	vector<int> vec(C);
	for(int i = 0; i < C; i++)
	{
		if(i + idx >= N) return false;
		vec[i] = notes[i + idx];
	}
	sort(vec.begin(), vec.end());
	int offset = vec[0] - ill[0];
	for(int i = 0; i < C; i++)
		if(vec[i] - ill[i] != offset) return false;
	return true;
}
int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> N; for(int i = 0; i < N; i++) cin >> notes[i];
	cin >> C;  for(int i = 0; i < N; i++) cin >> ill[i];
	sort(ill, ill + C);
	vector<int> ret;
	
	for(int i = 0; i < N; i++)
		if(check(i))
			ret.push_back(i);
	cout << ret.size() << endl;
	for(auto r : ret) cout << r + 1 << endl;
	
	
	return 0;
}
