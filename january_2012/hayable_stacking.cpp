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

int st[1000001];
int ed[1000001];

int32_t main(void)
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N, K; cin >> N >> K;
    while(K--)
    {
        int A, B; cin >> A >> B; st[A] += 1; ed[B] += 1;
    }
    int cur = 0;
    vector<int> stks;
    
    for(int i = 1; i <= N; i++)
    {
        cur += st[i];
        stks.push_back(cur);
        cur -= ed[i];
    }
    sort(stks.begin(), stks.end());
    
    
    /*
    for(auto s : stks)
        cout << s << " ";
    cout << endl;
     
     */
    
    cout << stks[stks.size() / 2] << endl;
    
    
    return 0;
}

