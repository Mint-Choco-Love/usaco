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

bool obstacle[5][5];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int K, ret;

vector<Point> visited;

bool check(int nx, int ny)
{
    for(auto p : visited)
    {
        if(p.x == nx && p.y == ny) return true;
    }
    return false;
}

void dfs(int x, int y, int step)
{
    if(step == 25 - K && x == 4 && y == 4)
        ret += 1;
    for(int i = 0; i < 4; i++)
    {
        auto nx = x + dx[i], ny = y + dy[i];
        if(min(nx, ny) < 0 || nx >= 5 || ny >= 5) continue;
        if(obstacle[nx][ny]) continue;
        if(check(nx, ny)) continue;
        
        visited.push_back(Point{nx, ny});
        dfs(nx, ny, step + 1);
        visited.pop_back();
    }
}

int32_t main(void)
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> K;
    for(int i = 0; i < K; i++)
    {
        int x, y; cin >> x >> y; x -= 1; y -= 1; obstacle[x][y] = true;
    }
    
    visited.push_back(Point{0,0});
    dfs(0, 0, 1);

    cout << ret << endl;
    return 0;
}

