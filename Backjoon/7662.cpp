#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;
string t1;
int t2, T, K;
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--)
	{
		cin >> K;
		map <int, int, greater<int>> m;
		for (int i = 0; i < K; i++)
		{
			cin >> t1 >> t2;
			if (t1 == "I")
			{
				if (m.find(t2) != m.end())
					m[t2]++;
				else
					m.insert({ t2, 1 });
			}
			else
			{
				if (!m.empty())
				{
					if (t2 == -1)
					{
						auto iter = m.rbegin();
						if (iter->second > 1)
							iter->second--;
						else
							m.erase(iter->first);
					}
					else
					{
						auto iter = m.begin();
						if (iter->second > 1)
							iter->second--;
						else
							m.erase(iter->first);
					}
				}
			}
		}
		if (m.empty())
			cout << "EMPTY" << '\n';
		else
			cout << m.begin()->first << ' ' << m.rbegin()->first << '\n';
	}
}