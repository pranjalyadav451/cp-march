#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int LongestRepeatingSubsequence(string str)
	{
	}
};

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}