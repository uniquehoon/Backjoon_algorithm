#include <iostream>
#include <cmath>
using namespace std;
int N, r, c;
int cnt;

void recur(int n, int x, int y)
{
	if (n == 1)
	{
		if (x == r && y == c)
		{
			cout << cnt;
			exit(0);
		}
		cnt++;
	}
	else
	{
		for (int i = x; i < x + n; i += n / 2)
		{
			for (int j = y; j < y + n; j += n / 2)
			{
				if ((i <= r && r <= i + (n / 2)) && (j <= c && c <= j + (n / 2)))
					recur(n / 2, i, j);
				else
					cnt += pow((n / 2), 2);
			}
		}
	}
}

int main(int argc, char** argv)
{
	cin >> N >> r >> c;
	recur(pow(2, N), 0, 0);
	return 0;
}