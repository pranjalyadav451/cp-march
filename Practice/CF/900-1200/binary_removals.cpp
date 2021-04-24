// Binary String
/*
- Find a seq 'a' is string 's' such that the characters in 'a'are not adjacent.
- Removing them fulfills two criterias
	- non-decreasing order
	- removed elements should not be adjacent

*/
/*
	Notes -:
		- Did too much than what was needed.
		- But grasped some practical concepts of dp.
*/



#include <bits/stdc++.h>
#define ll long long
#define vec vector
#define MOD 1000000007
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

using namespace std;

bool isSorted(string &s)
{
	for (int i = 1; i < s.size(); i++)
		if (s[i] < s[i - 1])
			return false;
	return true;

}

int dp[1010][1010];

bool isPos(string s, int n, int prev = 0)
{
	if (n == 0)
		return isSorted(s);

	if (prev - 1 != n)
	{
		string temp = s;
		s.erase(s.begin() + n - 1, s.begin() + n);

		bool inc = isPos(temp, n - 1, prev);
		bool exc = isPos(s, n - 1, n);
		dp[n][prev] = int(inc or exc);
	}
	else
		dp[n][prev] = (int)isPos(s, n - 1, prev);
	return dp[n][prev];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	clock_t begin = clock();

	int tt;
	cin >> tt;
	while (tt--)
	{
		string s;
		cin >> s;
		int n = s.size();

		memset(dp, -1, sizeof(dp));
		if (isPos(s, n));
		if (dp[n][0] == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif

}