#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int list[1000];
int T;
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> list[i];
	}
	sort(list, list + T);
	for (int i = 1; i < T; i++)
	{
		list[i] = list[i] + list[i - 1];
	}
	cout << accumulate(list, list + T, 0);
	return 0;
}