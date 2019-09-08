#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

int N, B;
struct COST{int P; int S;};

int32_t main()
{
	cin >> N >> B; vector<COST> vec; bool flag = false; int ret = 0;
	for(int i = 0; i < N; i++)
	{
		int p, s; cin >> p >> s; vec.push_back(COST{p, s});
	}
	
	for(int i = 0; i < N; i++)
	{
		vector<COST> temp;
		for(int j = 0; j < N; j++)
		{
			if(j == i) temp.push_back(COST{vec[j].P/2, vec[j].S});
			else temp.push_back(COST{vec[j].P, vec[j].S});
		}
		sort(temp.begin(), temp.end(), [](COST a, COST b){return a.P+a.S<b.P+b.S;});
		int ptr = 0, acc = 0;
		while(ptr < N && temp[ptr].P+temp[ptr].S+acc <= B)
		{
			acc += temp[ptr].P+temp[ptr].S;
//			cout << "ptr: " << ptr << ", acc: " << acc << ", P: " << temp[ptr].P << ", S: " << temp[ptr].S << endl;
			ptr++;
		}
		ret = max(ret, ptr);
//		cout << i << " " << ptr << endl;
//		cout << endl;
	}
	
	
	cout << ret << endl;
	return 0;
}
