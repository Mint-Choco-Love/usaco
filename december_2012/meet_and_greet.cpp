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

int ret;
int position[2][1000001];

int32_t main()
{
    MAGIC;
    int b, e, t; string s; cin >> b >> e; int pos = 0; int time = 0;

    while(b--)
    {
        cin >> t >> s;
        while(t--)
        {
            if(s == "L") pos -= 1; else pos += 1; time += 1;
            position[0][time] = pos;
        }
    }
    
    time += 1;
    while(time < 1000001)
    {
        position[0][time] = position[0][time - 1]; time += 1;
    }
    
    
    
    pos = 0; time = 0;
    while(e--)
    {
        cin >> t >> s;
        while(t--)
        {
            if(s == "L") pos -= 1; else pos += 1; time += 1;
            position[1][time] = pos;
//            cout << position[0][time] << " " << position[1][time] << endl;
        }
    }
    time += 1;
    while(time < 1000001)
    {
        position[1][time] = position[1][time - 1]; time += 1;
    }
    
    for(int i = 1; i < 1000001; i++)
    {
        if(position[1][i] == position[0][i] && position[1][i-1] != position[0][i-1])
        {
            ret += 1;
        }
    }
    
    cout << ret << endl;
   
    return 0;
}

