#include <iostream>
#include <set>

using namespace std;
int M;
string s1;
int a;
set <int> s;
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> M;
	while (M--)
	{
		cin >> s1;
		if (s1 == "all" || s1 == "empty")
		{
			if (s1 == "all")
			{
				for (int i = 0; i <= 20; i++)
					s.insert(i);
			}
			else
			{
				s.clear();
			}
		}
		else
		{
			cin >> a;
			if (s1 == "add")
			{
				if (!s.count(a))
					s.insert(a);
			}
			else if (s1 == "remove")
			{
				if (s.count(a))
					s.erase(a);
			}
			else if (s1 == "check")
			{
				if (s.count(a))
					cout << '1' << '\n';
				else
					cout << '0' << '\n';
			}
			else // toggle
			{
				if (s.count(a))
					s.erase(a);
				else
					s.insert(a);
			}
		}
	}
}