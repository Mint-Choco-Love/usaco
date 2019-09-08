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

int ret[50001][2];
struct El{string str; int idx;};

int32_t main()
{
    MAGIC; int N; cin >> N;
    vector<El> vec1, vec2;
    for(int i = 0; i < N; i++)
    {
        string s; cin >> s; sort(s.begin(), s.end()); vec1.push_back(El{s, i});
        reverse(s.begin(), s.end()); vec2.push_back(El{s, i});
    }
    sort(vec1.begin(), vec1.end(), [](El a, El b) { return a.str < b.str ; });
    sort(vec2.begin(), vec2.end(), [](El a, El b) { return a.str < b.str ; });
    
    // 나만 vec1이고 다른 것들은 vec2이면, 가장 빠름
    int other = 0;
    for(int i = 0; i < N; i++)
    {
        auto cur = vec1[i];
        while(other < N && vec2[other].str < cur.str)
            other += 1;
        ret[cur.idx][0] = other + 1;
    }
    
    // 나만 vec2이고 다른 것들은 vec1이면, 가장 느림
    other = 0;
    for(int i = 0; i < N; i++)
    {
        auto cur = vec2[i];
        while(other < N && vec1[other].str < cur.str)
            other += 1;
        ret[cur.idx][1] = other + 1;
        
        auto cur_str = cur.str;
        auto reverse_str(cur_str); reverse(reverse_str.begin(), reverse_str.end());
        if(cur_str != reverse_str) ret[cur.idx][1] -= 1;
    }
    
    for(int i = 0; i < N; i++)
        cout << ret[i][0] << " " << ret[i][1] << endl;
    return 0;
}

