#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <ctime>
#include <fstream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
//#define ll long long
#define mod 1000000007
#define NCONS 100001
//#define NCONS 100001
//#define NCONS 1001
//#define NCONS 101
#define MCONS 2001
#define LIMIT 1000000000
#define TRUE 1
#define FALSE 0
#define toRadian(degree) ((degree) * (M_PI / 180.))
#define toDegree(radian) ((radian) * (180. / M_PI))
#define int long long
//#define double long double
using namespace std;
struct Point{int x; int y;};
struct PPoint{Point x; Point y;};
typedef long long ll;

int gcd(int a, int b) { if(a < b) swap(a, b); if(b <= 0) return a; return gcd(b, a % b); }

#define YYYY cout << "YES" << endl
#define NNNN cout << "NO" << endl
#define yyyy cout << "Yes" << endl
#define nnnn cout << "No" << endl

int N, L, ret;
vector<int> arr, diff;

bool check(int left, int right)
{
    if(left > right) return true;
    if(left == right) return true;
    
    if(diff[left] != diff[right]) return false;

    return check(left + 1, right - 1);
}

int32_t main(void)
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N >> L; for(int i = 0; i < N; i++) { int t; cin >> t; arr.push_back(t); }
    sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size() - 1; i++)
        diff.push_back(arr[i+1] - arr[i]);
    
    for(int i = 0; i < diff.size(); i++)
    {
        if(check(0, i))
            ret += 1;
    }
    for(int i = 1; i < diff.size(); i++)
    {
        if(check(i, diff.size() - 1))
            ret += 1;
    }
    
    
    cout << ret << endl;
    return 0;
}

