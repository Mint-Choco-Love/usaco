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
#define MAGIC cin.tie(NULL); ios_base::sync_with_stdio(false)
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

int32_t main()
{
    MAGIC; int N; cin >> N; vector<int> vec(N); for(int i = 0; i < N; i++) cin >> vec[i];
    int ret = 0;
    
    for(int i = 0; i < N; i++)
    {
        auto removal = vec[i];
        int temp = 0; int prev = -1; int cnt = 0;
        
        for(int j = 0; j < N; j++)
        {
            if(vec[j] == removal) continue;
            if(prev == vec[j]) cnt += 1;
            else { temp = max(temp, cnt); prev = vec[j]; cnt = 1; }
        }
        temp = max(temp, cnt);
        
        
        ret = max(ret, temp);
    }
    
    cout << ret << endl;
    return 0;
}

