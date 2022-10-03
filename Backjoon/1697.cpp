#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
queue <pair <int, int>> q;
int start, finish, x, level;
int visited[200001];
#define MAX 100000
void solve()
{
	if (!visited[x - 1] && x - 1 >= 0)
	{
		q.push({ x - 1, level + 1 });
		visited[x - 1]++;
	}
	if (!visited[x + 1] && x + 1 <= MAX)
	{
		q.push({ x + 1, level + 1 });
		visited[x + 1]++;
	}
	if (!visited[x * 2] && x * 2 <= MAX)
	{
		q.push({ x * 2, level + 1 });
		visited[x * 2]++;
	}
}

void bfs()
{
	while (!q.empty())
	{
		tie(x, level) = q.front();
		if (x == finish)
		{
			cout << level;
			return;
		}
		q.pop();
		solve();
	}
}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> start >> finish;
	q.push({ start, 0 });
	bfs();
}