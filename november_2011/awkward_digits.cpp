#include <iostream>
#include <string>
#include <algorithm>
#define int long long
using namespace std;

int get_it(string str, int base)
{
	int ex = 1;
	int ret = 0;
	while(!str.empty())
	{
		auto cur = str.back(); str.pop_back();
		ret += ex * (cur - '0');
		ex *= base;
	}
	
	return ret;
}

int32_t main()
{
	string tw, th; cin >> tw >> th;
//	reverse(tw.begin(), tw.end()); reverse(th.begin(), th.end());
	
//	cout << tw << " " << th << endl << endl;
	for(int i = 0; i < tw.size(); i++)
	{
		char origin2 = tw[i];
		tw[i] = origin2 == '0' ? '1' : '0';
		for(int j = 0; j < th.size(); j++)
		{
			char origin3 = th[j];
			for(int k = 0; k < 3; k++)
			{
				if(origin3 - '0' == k) continue;
				th[j] = (char)(k + '0');
				
				
				
				auto two = get_it(tw, 2), three = get_it(th, 3);
	//			cout << tw << " " << th << " : " << two << " ," << three << endl;
				if(two == three)
				{
					cout << two << endl; exit(0);
				}
				
			}
			th[j] = origin3;
		}
		tw[i] = origin2;
	}
	
	
	
	
	return 0;
}
