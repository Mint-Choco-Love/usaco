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

enum DIR{UP, RIGHT, DOWN, LEFT, INITIAL};

int N, ret;
vector<Point> arr;
vector<Point> vec;
bool visited[10];
enum DIR cur_dir;

enum DIR move(Point s, Point t)
{
    enum DIR ret = UP;
    if(s.x < t.x)
        ret = RIGHT;
    else if(s.x > t.x)
        ret = LEFT;
    else if(s.y < t.y)
        ret = UP;
    else
        ret = DOWN;
    return ret;
}

bool check(Point s, Point t)
{
    if(s.x != t.x && s.y != t.y) return false;
    if(cur_dir == INITIAL && (t.x != 0 && t.y != 0)) return false;
    if(cur_dir == UP && s.y < t.y) return false;
    if(cur_dir == DOWN && s.y > t.y) return false;
    if(cur_dir == RIGHT && s.x < t.x) return false;
    if(cur_dir == LEFT && s.x > t.x) return false;
    
    return true;
}

void dfs()
{
    /*
    for(auto p : vec)
    {
        printf("(%lld, %lld) ", p.x, p.y);
    }
     
    cout << endl;
    */
    if(vec.size() == N + 1)
    {
        if(check(vec.back(), Point{0,0}))
        {
            ret += 1;
        }
        return;
    }
    
    for(int i = 0; i < N; i++)
    {
        if(visited[i]) continue;
        if(!check(vec.back(), arr[i])) continue;
        
        auto temp_dir = cur_dir;
        cur_dir = move(vec.back(), arr[i]);
        visited[i] = true;
        vec.push_back(arr[i]);
        dfs();
        vec.pop_back();
        visited[i] = false;
        cur_dir = temp_dir;
    }
}

int32_t main()
{
    cin >> N; cur_dir = INITIAL;
    for(int i = 0; i < N; i++)
    {
        int x, y; cin >> x >> y; arr.push_back(Point{x, y});
    }
    vec.push_back(Point{0, 0});
    
    dfs();
    
    cout << ret << endl;
    
    return 0;
}

