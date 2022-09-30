#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector <vector <int>> v;
int cnt = 1;
int value = -1;
int T;
int trig;
int a1, a2;
int idx;
int find_index;

bool cmp(vector <int>& v1, vector <int>& v2)
{
	if (v1[1] == v2[1])
		return v1[0] < v2[0];
	return v1[1] < v2[1];
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> a1 >> a2;
		v.push_back({ a1, a2 });
	}
	sort(v.begin(), v.end(), cmp);
	while (!trig && idx < (T - 1))
	{
		if (value < 0)
		{
			value = v[0][1];
			continue;
		}
		trig = 1;
		for (int i = idx + 1; i < T; i++)
		{
			if (value <= v[i][0])
			{
				value = v[i][1];
				idx = i;
				trig = 0;
				cnt++;
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}