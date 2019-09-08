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
int arr[1001];
bool visited[1001];
bool ret[1001];

bool dfs(int cur)
{
    if(visited[cur]) return ret[cur];
    visited[cur] = true;
    
    if(arr[cur] == 0) return ret[cur] = true;
    auto nxt = arr[cur];
    
    if(dfs(nxt)) return ret[cur] = true;
    
    return false;
}
int32_t main()
{
    MAGIC;
    cin >> N; for(int i = 1; i <= N; i++) cin >> arr[i];
    int cnt = 0;
    
    for(int i = 1; i <= N; i++)
        if(dfs(i))
            cnt += 1;
    cout << cnt << endl;
    
    
    return 0;
}

