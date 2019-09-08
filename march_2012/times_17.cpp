#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int carry;
string sum(string a, string b)
{
	string ret = "";
	while(!a.empty())
	{
		auto cur1 = a.back(); a.pop_back(); cur1 -= '0';
		int cur2; if(b.empty()) cur2 = 0; else {cur2 = b.back(); b.pop_back(); cur2 -= '0';}
		
		auto temp = cur1 + cur2 + carry;
		if(temp > 1) {carry = 1;temp -= 2;}
		else {carry = 0;}
		temp += '0';
		ret.push_back((char)temp);
	}
	if(carry) ret.push_back('1');
	reverse(ret.begin(), ret.end());
	return ret;
}

int main()
{
	string str; cin >> str; string nw = str; for(int i = 0; i < 4; i++) nw.push_back('0');
	cout << sum(nw, str) << endl;
	return 0;
}
