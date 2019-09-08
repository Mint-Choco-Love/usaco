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

int N;
int position[5][20001];

bool cmp(int a, int b)
{
    int cnt = 0;
    for(int i = 0; i < 5; i++)
    {
        if(position[i][a] < position[i][b])
            cnt += 1;
    }
    return cnt > 2;
}

int32_t main()
{
    MAGIC; cin >> N;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < N; j++)
        {
            int t; cin >> t; position[i][t] = j;
        }
    }
    vector<int> vec(N); for(int i = 0; i < N; i++) vec[i] = i + 1;
    sort(vec.begin(), vec.end(), cmp);
    
    for(auto v : vec)
        cout << v << endl;

    return 0;
}

