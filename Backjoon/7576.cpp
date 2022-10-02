#include <queue>
#include <iostream>
#include <tuple>
using namespace std;

int level;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int mx;
int my;
int X, Y, x, y, eox, eoy;
int list[1000][1000];
int visited[1000][1000];
queue <pair <int, int>> q;

int check()
{
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			level = max(level, visited[i][j]);
			if (!visited[i][j])
				return -1;
		}
	}
	return level - 1;
}

void bfs()
{
	while (!q.empty())
	{
		tie(y, x) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			eox = x + dx[i];
			eoy = y + dy[i];
			if (eox < 0 || eoy < 0 || eox >= X || eoy >= Y || visited[eoy][eox])
				continue;
			q.push({ eoy, eox });
			visited[eoy][eox] = visited[y][x] + 1;
		}
	}
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> X >> Y;
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			cin >> list[i][j];
			if (list[i][j] == 1)
			{
				q.push({ i, j });
				visited[i][j] = 1;
			}
			if (list[i][j] == -1)
				visited[i][j] = -1;
		}
	}
	bfs();
	cout << check();
}