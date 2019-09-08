#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;

int N, M; bool visited[50][50];
int dx[]{0, 1, 0, -1};
int dy[]{1, 0, -1, 0};
struct Point{int x; int y; int dist;};
vector<string> mp;
Point position;

queue<Point> quu, temp;
int32_t main()
{
	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		string t; cin >> t; mp.push_back(t);
		for(int j = 0; j < M; j++)
			if(mp[i][j] == 'X')
				position = {i, j, 0};
	}
	
	temp.push(position); visited[position.x][position.y] = true;
	while(!temp.empty())
	{
		auto cur = temp.front(); temp.pop();
		quu.push(cur);
		for(int i = 0; i < 4; i++)
		{
			auto nx = cur.x + dx[i], ny = cur.y + dy[i];
			if(min(nx, ny) < 0 || nx >= N ||ny >= M) continue;
			if(visited[nx][ny]) continue;
			if(mp[nx][ny] == '.') continue;
			visited[nx][ny] = true;
			temp.push(Point{nx, ny, 0});
		}
	}
	

	while(!quu.empty())
	{
		auto cur = quu.front(); quu.pop();
		for(int i = 0; i < 4; i++)
		{
			auto nx = cur.x + dx[i], ny = cur.y + dy[i];
			if(min(nx, ny) < 0 || nx >= N ||ny >= M) continue;
			if(visited[nx][ny]) continue;
			visited[nx][ny] = true;
			if(mp[nx][ny] == 'X')
			{
				cout << cur.dist << endl; exit(0);
			}
			quu.push(Point{nx, ny, cur.dist + 1});
		}
	}
	
	
	return 0;
}
